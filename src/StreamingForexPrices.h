/* 
 * File:   StreamingForexPrices.h
 * Author: alexandrepetit
 *
 * Created on May 15, 2016, 6:14 PM
 */

#ifndef STREAMINGFOREXPRICES_H
#define STREAMINGFOREXPRICES_H

#include "Event.h"

#include <iostream>
#include <iterator>
#include <sstream>
    
/**
 * \class StreamingForexPrices
 * \brief Streams forex prices
 */
class StreamingForexPrices {
public:
    StreamingForexPrices(const std::string& domain_, const std::string& accessToken_,
                         const std::string& accountId_, const std::string& instrument_,
                         eventsQueue& eventsQueue_);
 
    void handleStream(std::streambuf* streamBuffer_);
    void streamToQueue();

private:
    std::string m_domain;
    std::string m_accessToken;
    std::string m_accountId;
    std::string m_instruments;
    eventsQueue& m_eventsQueue;

};

#endif /* STREAMINGFOREXPRICES_H */

