/* 
 * File:   Execution.h
 * Author: alexandrepetit
 *
 * Created on May 25, 2016, 7:38 PM
 */

#ifndef EXECUTION_H
#define EXECUTION_H

//#include "OrderEvent.h"

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

using namespace Poco;
using namespace Poco::Net;

class Execution {
public:
    Execution(std::string domain_, std::string accessToken_, std::string accountId_);
    ~Execution();
    
    void executeOrder();
private:
    std::string m_domain;
    std::string m_accessToken;
    std::string m_accountId;
    
    Context::Ptr*       m_context;
    URI*                m_uri;
    HTTPRequest*        m_request;
    HTTPSClientSession* m_session;
};

#endif /* EXECUTION_H */

