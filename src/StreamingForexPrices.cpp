/* 
 * File:   StreamingForexPrices.cpp
 * Author: alexandrepetit
 * 
 * Created on May 15, 2016, 6:15 PM
 */

#include "StreamingForexPrices.h"

#include "TickEvent.h"

#include <sstream>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

/**
 * @param domain_
 * @param accessToken_
 * @param accountId_
 * @param instrument_
 * @param eventsQueue_
 */
StreamingForexPrices::StreamingForexPrices(const std::string& domain_, const std::string& accessToken_,
                                           const std::string& accountId_, const std::string& instrument_,
                                           eventsQueue& eventsQueue_) :
        m_domain(domain_),
        m_accessToken(accessToken_),
        m_accountId(accountId_),
        m_instruments(instrument_),
        m_eventsQueue(eventsQueue_)
{ 
}

/**
 * @param streamBuffer_
 */
void StreamingForexPrices::handleStream(std::streambuf* streamBuffer_)
{
    std::istreambuf_iterator<char> eos; // end-of-range iterator
    std::istreambuf_iterator<char> iit (streamBuffer_); // stream iterator
    
    while (iit!=eos) {
        std::ostringstream oss;
        while (*iit != '\n') {
            oss << *iit++;
        }
        
        std::string oandaStream = oss.str();

        // Received a tick
        if(receivedTick(oandaStream))
        {
            // Create new tick event
            createTickEvent(oandaStream);
        }
        // No tick received, but heartbeat received
        else 
        {
            // Print heartbeat
            printHeartbeat(oandaStream);
        }
        
        *iit++;
    
    }
}

/**
 * \brief Streams tick events to events queue
 */
void StreamingForexPrices::streamToQueue()
{
    //*********************
    // Connect to stream
    //*********************
    const Poco::Net::Context::Ptr context = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", "", "", 
                                                                   Poco::Net::Context::VERIFY_NONE, 9, false, 
                                                                   "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
   
    // prepare session
    Poco::URI uri(m_domain + std::string("/v1/prices?accountId=") + m_accountId + std::string("&instruments=") + m_instruments);
      
    Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
    session.setKeepAlive(true);

    // prepare path
    std::string path(uri.getPathAndQuery());
     if (path.empty())
     {
         path = "/";
     }

    // send request
    Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
    req.set("Authorization", std::string("Bearer ") + m_accessToken);
    session.sendRequest(req);

    // get response
    Poco::Net::HTTPResponse res;
    std::istream& stream = session.receiveResponse(res);
    
    // handle stream
    handleStream(stream.rdbuf());
}

/**
 * @param json_
 * @param instrument_
 * @param time_
 * @param bid_
 * @param ask_
 */
void StreamingForexPrices::retreiveValuesFromStream(const Json::Value& json_, std::string& instrument_, std::string& time_, double& bid_, double& ask_)
{
    Json::Value tick = json_["tick"];
    instrument_ = tick.get("instrument", "No instrument found\n").asString();
    time_ = tick.get("time", "No time found\n").asString();
    bid_ = tick.get("bid", "No bid found\n").asDouble();
    ask_ = tick.get("ask", "No ask found\n").asDouble();
    
    setCurrentBid(bid_);
    setCurrentAsk(ask_);
}

/**
 * @param oandaStream_
 */
void StreamingForexPrices::createTickEvent(const std::string& oandaStream_)
{
    Json::Value root;   
    Json::Reader reader;

    bool parsingSuccessful = reader.parse(oandaStream_, root);

    if (!parsingSuccessful)
    {
        std::cout  << "Failed to parse" << reader.getFormattedErrorMessages();
        return;
    }

    // Get values from stream
    std::string instrument;
    std::string time;
    double bid;
    double ask;
    retreiveValuesFromStream(root, instrument, time, bid, ask);
    
    std::cout << "New tick event " << oandaStream_ << std::endl;
    emplaceTickEvent(instrument, time, bid, ask);
}

/**
 * @param instrument_
 * @param time_
 * @param bid_
 * @param ask_
 */
void StreamingForexPrices::emplaceTickEvent(const std::string& instrument_, const std::string& time_, const double bid_, const double ask_)
{
    m_eventsQueue.emplace(std::unique_ptr<TickEvent>(new TickEvent(instrument_, time_, bid_, ask_)));
}

/**
 * @param heartBeat_
 */
void StreamingForexPrices::printHeartbeat(const std::string& heartBeat_) const
{
    std::cout << heartBeat_ << std::endl;
}

/**
 * \brief Returns whether or not a stream contains a tick (true) or just a heartbeat (false)
 * @param stream_
 */
bool StreamingForexPrices::receivedTick(const std::string& stream_) const
{
    std::string tick = "tick";
    return stream_.find(tick) != std::string::npos;
}

/**
 * @param bid_
 */
void StreamingForexPrices::setCurrentBid(const double bid_)
{
    m_currentBid = bid_;
}

/**
 * @param ask_
 */
void StreamingForexPrices::setCurrentAsk(const double ask_)
{
    m_currentAsk = ask_;
}

/**
 * @return m_currentBid
 */
double StreamingForexPrices::getCurrentBid() const
{
    return m_currentBid;
}

/**
 * @return m_currentAsk
 */
double StreamingForexPrices::getCurrentAsk() const
{
    return m_currentAsk;
}