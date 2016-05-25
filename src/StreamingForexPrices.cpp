/* 
 * File:   StreamingForexPrices.cpp
 * Author: alexandrepetit
 * 
 * Created on May 15, 2016, 6:15 PM
 */

#include "StreamingForexPrices.h"

#include "TickEvent.h"

#include <sstream>

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

#if notTests
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

using namespace Poco::Net;
using namespace Poco;
#endif

/**
 * @param domain_
 * @param accessToken_
 * @param accountId_
 * @param instrument_
 * @param eventsQueue_
 */
StreamingForexPrices::StreamingForexPrices(std::string domain_, std::string accessToken_,
                                           std::string accountId_, std::string instrument_,
                                           eventsQueue& eventsQueue_) :
        m_domain(domain_),
        m_accessToken(accessToken_),
        m_accountId(accountId_),
        m_instruments(instrument_),
        m_eventsQueue(eventsQueue_)                  
{
}

#if notTests

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
    
        //std::cout << oss.str() << std::endl;
        
        std::string oandaStream = oss.str();
        Json::Value root;   
        Json::Reader reader;

        bool parsingSuccessful = reader.parse(oandaStream, root);

        if (!parsingSuccessful)
        {
            std::cout  << "Failed to parse" << reader.getFormattedErrorMessages();
            return;
        }

        std::string heartbeat = "heartbeat";
        if(oandaStream.find(heartbeat) == std::string::npos)
        {
            // New tick event
            Json::Value tick = root["tick"];
            std::string instrument = tick.get("instrument", "No instrument found\n").asString();
            std::string time = tick.get("time", "No time found\n").asString();
            double bid = tick.get("bid", "No bid found\n").asDouble();
            double ask = tick.get("ask", "No ask found\n").asDouble();
            
            std::cout << "New tick event " << oandaStream << "\n";
            m_eventsQueue.emplace(std::unique_ptr<TickEvent>(new TickEvent(instrument, time, bid, ask)));
            
            //std::cout << dynamic_cast<TickEvent*>((m_eventsQueue.back()).get())->getTime() << std::endl;
            //std::cout << "queue size " << m_eventsQueue.size() << std::endl;
        }
        else
        {
            // Print heartbeat
            std::cout << oandaStream << "\n";
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
    const Context::Ptr context = new Context(Context::CLIENT_USE, "", "", "", Context::VERIFY_NONE, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
   
    // prepare session
    URI uri(m_domain + std::string("/v1/prices?accountId=") + m_accountId + std::string("&instruments=") + m_instruments);
      
    HTTPSClientSession session(uri.getHost(), uri.getPort(), context);
    session.setKeepAlive(true);

    // prepare path
    std::string path(uri.getPathAndQuery());
     if (path.empty())
     {
         path = "/";
     }

    // send request
    HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
    req.set("Authorization", std::string("Bearer ") + m_accessToken);
    session.sendRequest(req);

    // get response
    HTTPResponse res;
    std::istream& stream = session.receiveResponse(res);
    
    // handle stream
    handleStream(stream.rdbuf());
}

#endif