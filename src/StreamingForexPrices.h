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

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
    
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
    void retreiveValuesFromStream(const Json::Value& json_, std::string& instrument_, std::string& time_, double& bid_, double& ask_) const;
    void createTickEvent(const std::string& oandaStream_);
    void emplaceTickEvent(const std::string& instrument_, const std::string& time_, const double bid_, const double ask_);
    void printHeartbeat(const std::string& heartBeat_) const;
    
private:
    std::string m_domain;
    std::string m_accessToken;
    std::string m_accountId;
    std::string m_instruments;
    eventsQueue& m_eventsQueue;

};

#endif /* STREAMINGFOREXPRICES_H */

