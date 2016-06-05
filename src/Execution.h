/* 
 * File:   Execution.h
 * Author: alexandrepetit
 *
 * Created on May 25, 2016, 7:38 PM
 */

#ifndef EXECUTION_H
#define EXECUTION_H

#include "OrderEvent.h"

#include <memory>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

class Execution {
public:
    Execution(const std::string& domain_, const std::string& accessToken_, const std::string& accountId_);
    ~Execution();
    
    void executeOrder(const OrderEvent* pOrderEvent_);
    void prepareRequestBody(const OrderEvent* pOrderEvent_, std::string& body_);
    void sendRequest(std::string& body_);
    void printResponse(std::istream& reponse_);
    std::istream& receiveResponse();
    
private:
    std::string m_domain;
    std::string m_accessToken;
    std::string m_accountId;
    
    Poco::Net::Context::Ptr*       m_context = nullptr;
    Poco::URI*                     m_uri = nullptr;
    Poco::Net::HTTPRequest*        m_request = nullptr;
    Poco::Net::HTTPSClientSession* m_session = nullptr;
};

#endif /* EXECUTION_H */

