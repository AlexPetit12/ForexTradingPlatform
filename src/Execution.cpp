/* 
 * File:   Execution.cpp
 * Author: alexandrepetit
 * 
 * Created on May 25, 2016, 7:38 PM
 */

#include "Execution.h"

#include <iostream>
#include <sstream>

/**
 * @param domain_
 * @param accessToken_
 * @param accountId_
 */
Execution::Execution(const std::string& domain_, const std::string& accessToken_, const std::string& accountId_) :
        m_domain(domain_),
        m_accessToken(accessToken_),
        m_accountId(accountId_)                    
{
    // Prepare session to send orders to OANDA
    Poco::Net::Context::Ptr m_context = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_NONE, 
                                       9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
    m_uri = new Poco::URI(m_domain);
    
    m_session = new Poco::Net::HTTPSClientSession(m_uri->getHost(), m_uri->getPort(), m_context);
    m_session->setKeepAlive(true);
    
    m_request = new Poco::Net::HTTPRequest(Poco::Net::HTTPRequest::HTTP_POST, std::string("/v1/accounts/") + 
                               m_accountId + std::string("/orders"), Poco::Net::HTTPMessage::HTTP_1_1);
    m_request->setContentType(std::string("application/x-www-form-urlencoded"));
    m_request->set("Authorization", std::string("Bearer ") + m_accessToken);
}

/**
 * \brief Default constructor
 */
Execution::~Execution()
{
}


/**
 * @param pOrderEvent_
 */
void Execution::executeOrder(const OrderEvent* pOrderEvent_) const
{
    std::string body;
    prepareRequestBody(pOrderEvent_, body);
    
    // Send request with body
    sendRequest(body);
    
    // Receive response
    std::istream& response = receiveResponse();
    
    // Print response
    printResponse(response);
}

/**
 * \brief Prepare request body 
 * \brief Example: "instrument=EUR_USD&units=5&side=buy&type=market";
 * @param pOrderEvent_
 * @param body_
 */
void Execution::prepareRequestBody(const OrderEvent* pOrderEvent_, std::string& body_) const
{
    std::string instrument = pOrderEvent_->getInstrument();
    std::string unitsQty   = pOrderEvent_->getUnitsQty();
    std::string side       = pOrderEvent_->getSide();
    std::string type       = pOrderEvent_->getOrderType();
    
    std::stringstream streamBody;
    streamBody << "instrument=" << instrument << "&units=" << unitsQty << "&side=" << side << "&type=" << type;
    body_.clear();
    body_ = streamBody.str();
}

/**
 * @param body_
 */
void Execution::sendRequest(const std::string& body_) const
{
    m_request->setContentLength(body_.length());
    m_request->write(std::cout);
    std::ostream& os = m_session->sendRequest(*m_request);
    
    // Send body
    os << body_;
}

/**
 * @return response
 */
std::istream& Execution::receiveResponse() const
{
    Poco::Net::HTTPResponse response;
    std::istream& rs = m_session->receiveResponse(response);
    return rs;
}

/**
 * @param reponse_
 */
void Execution::printResponse(const std::istream& reponse_) const
{
    std::cout << reponse_.rdbuf();
}