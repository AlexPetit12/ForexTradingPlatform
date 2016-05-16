/* 
 * File:   StreamingForexPrices.h
 * Author: alexandrepetit
 *
 * Created on May 15, 2016, 6:14 PM
 */

#ifndef STREAMINGFOREXPRICES_H
#define STREAMINGFOREXPRICES_H

#include "Event.h"

class StreamingForexPrices {
public:
    StreamingForexPrices(std::string domain_, std::string accessToken_,
                         std::string accountId_, std::string instrument_,
                         eventsQueue& eventsQueue_);
private:
    std::string m_domain;
    std::string m_accessToken;
    std::string m_accountId;
    std::string m_instruments;
    eventsQueue& m_eventsQueue;

};

#endif /* STREAMINGFOREXPRICES_H */

