/* 
 * File:   Execution.cpp
 * Author: alexandrepetit
 * 
 * Created on May 25, 2016, 7:38 PM
 */

#include "Execution.h"

#include <iostream>
#include <sstream>

Execution::Execution(const std::string& domain_, const std::string& accessToken_, const std::string& accountId_) :
        m_domain(domain_),
        m_accessToken(accessToken_),
        m_accountId(accountId_)                    
{
    // Prepare session
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

Execution::~Execution()
{
}

void Execution::executeOrder(const OrderEvent* pOrderEvent_)
{
    // Prepare request body 
    // Example: "instrument=EUR_USD&units=5&side=buy&type=market";
    std::string instrument = pOrderEvent_->getInstrument();
    std::string unitsQty = pOrderEvent_->getUnitsQty();
    std::string side = pOrderEvent_->getSide();
    std::string type = pOrderEvent_->getOrderType();
    
    std::stringstream streamBody;
    streamBody << "instrument=" << instrument << "&units=" << unitsQty << "&side=" << side << "&type=" << type;
    std::string body = streamBody.str();
    
    // Send request and body
    m_request->setContentLength(body.length());
    m_request->write(std::cout);
    std::ostream& os = m_session->sendRequest(*m_request);
    os << body;
    
    // Receive response
    Poco::Net::HTTPResponse response;
    std::istream& rs = m_session->receiveResponse(response);
    
    // Print response
    std::cout << rs.rdbuf();
}