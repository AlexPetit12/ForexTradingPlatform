/* 
 * File:   SignalEvent.h
 * Author: alexandrepetit
 *
 * Created on June 14, 2016, 9:51 PM
 */

#ifndef SIGNALEVENT_H
#define SIGNALEVENT_H

#include "Event.h"

class SignalEvent : public Event
{
public:
    SignalEvent();
    SignalEvent(const std::string& instrument_, const std::string& orderType_, const std::string& side_);
    virtual ~SignalEvent();
    
    // Setters
    void setOrderType(const std::string& orderType_);
    void setSide(const std::string& side_);
    
    // Getters
    std::string getOrderType() const;
    std::string getSide() const;
    
private:
    std::string m_orderType;
    std::string m_side;

};

#endif /* SIGNALEVENT_H */

