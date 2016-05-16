/* 
 * File:   StreamingForexPrices.cpp
 * Author: alexandrepetit
 * 
 * Created on May 15, 2016, 6:15 PM
 */

#include "StreamingForexPrices.h"

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