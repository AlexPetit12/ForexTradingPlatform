/* 
 * File:   TickEvent.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 4:07 PM
 */

#ifndef TICKEVENT_H
#define TICKEVENT_H

#include "Event.h"

class TickEvent : public Event {
public:
    TickEvent();
    TickEvent(std::string type_, std::string instrument_, std::string time_, 
              double bid_, double ask_);
    virtual ~TickEvent();
    
private:
    std::string m_time;
    double m_bid;
    double m_ask;

};

#endif /* TICKEVENT_H */

