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
    TestRandomStrategy(const std::string& instrument_, const std::string& quantity_, 
                       eventsQueue& eventsQueue_);
    virtual ~TestRandomStrategy();
    
    int getTicks() const;
    void setTicks(int totalTicks_);
    
    void increaseTicks(int increase_ = 1);
    virtual void calculateSignals(const TickEvent* pTickEvent_);
   
protected:
    std::string m_instrument;
    std::string m_quantity;
    eventsQueue& m_eventsQueue;
    int m_ticks;
    bool m_invested;

};

class TestStrategy: public TestRandomStrategy
{
public: 
    TestStrategy(const std::string& instrument_, const std::string& unitsQty_, 
                       eventsQueue& eventsQueue_);
    virtual ~TestStrategy();
    
    void calculateSignals(const TickEvent* pTickEvent_) override;

};

#endif /* TESTRANDOMSTRATEGY_H */

