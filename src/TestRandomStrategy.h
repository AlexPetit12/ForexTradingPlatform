/* 
 * File:   TestRandomStrategy.h
 * Author: alexandrepetit
 *
 * Created on May 8, 2016, 5:29 PM
 */ 

#ifndef TESTRANDOMSTRATEGY_H
#define TESTRANDOMSTRATEGY_H

#include "TickEvent.h"

class TestRandomStrategy {
public:
    TestRandomStrategy(const std::string& instrument_, const std::string& unitsQty_, 
                       eventsQueue& eventsQueue_);
    virtual ~TestRandomStrategy();
    
    int getTicks() const;
    void setTicks(int totalTicks_);
    
    void increaseTicks(int increase_ = 1);
    void calculateSignals(const TickEvent* pTickEvent_);
   
private:
    std::string m_instrument;
    std::string m_unitsQty;
    eventsQueue& m_eventsQueue;
    int m_ticks;

};

#endif /* TESTRANDOMSTRATEGY_H */

