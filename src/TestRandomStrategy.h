/* 
 * File:   TestRandomStrategy.h
 * Author: alexandrepetit
 *
 * Created on May 8, 2016, 5:29 PM
 */ 

#ifndef TESTRANDOMSTRATEGY_H
#define TESTRANDOMSTRATEGY_H

#include "OrderEvent.h"

class TestRandomStrategy {
public:
    TestRandomStrategy(std::string instrument_, int units_, 
                       eventsQueue& eventsQueue_);
    virtual ~TestRandomStrategy();
    
    int getTicks() const;
    void setTicks(int totalTicks_);
    
    void increaseTicks(int increase_ = 1);
    void calculateSignals(Event& event_);
   
private:
    std::string m_instrument;
    int m_units;
    eventsQueue& m_eventsQueue;
    int m_ticks;

};

#endif /* TESTRANDOMSTRATEGY_H */

