/* 
 * File:   Execution.cpp
 * Author: alexandrepetit
 * 
 * Created on May 25, 2016, 7:38 PM
 */

#include "Execution.h"

#include <iostream>

Execution::Execution(std::string domain_, std::string accessToken_, std::string accountId_) :
        m_domain(domain_),
        m_accessToken(accessToken_),
        m_accountId(accountId_)                    
{
    Context::Ptr m_context = new Context(Context::CLIENT_USE, "", "", "", Context::VERIFY_NONE, 
                                       9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
    m_uri = new URI(m_domain);
    
    m_session = new HTTPSClientSession(m_uri->getHost(), m_uri->getPort(), m_context);
    m_session->setKeepAlive(true);
    
    m_request = new HTTPRequest(HTTPRequest::HTTP_POST, std::string("/v1/accounts/") + 
                               m_accountId + std::string("/orders"), HTTPMessage::HTTP_1_1);
    m_request->setContentType(std::string("application/x-www-form-urlencoded"));
    m_request->set("Authorization", std::string("Bearer ") + m_accessToken);
}

Execution::~Execution()
{
    //delete m_context;
    //delete m_uri;
    //delete m_session;
    //delete m_request;
}

void Execution::executeOrder()
{
    std::string body = "instrument=EUR_USD&units=5&side=buy&type=market";
    m_request->setContentLength(body.length());
    m_request->write(std::cout);
    std::ostream& os = m_session->sendRequest(*m_request);
    os << body;
    HTTPResponse response;
    std::istream& rs = m_session->receiveResponse(response);
    std::cout << rs.rdbuf();
}