/* 
 * File:   TickEvent.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 4:07 PM
 */

#ifndef TICKEVENT_H
#define TICKEVENT_H

#include "Event.h"

/**
 * \class TickEvent
 * \brief Generates a TickEvent object
 */
class TickEvent : public Event {
public:
    TickEvent();
    TickEvent(const std::string& instrument_, const std::string& time_, 
              double bid_, double ask_);
    virtual ~TickEvent();
    
    std::string getTime() const;
    void setTime(const std::string& time_);
    
    double getBid() const;
    void setBid(double bid_);
    
    double getAsk() const;
    void setAsk(double ask_);
    
private:
    std::string m_time;
    double m_bid;
    double m_ask;

};

#endif /* TICKEVENT_H */

