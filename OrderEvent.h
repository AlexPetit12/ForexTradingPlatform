/* 
 * File:   OrderEvent.h
 * Author: alexandrepetit
 *
 * Created on May 8, 2016, 3:48 PM
 */

#ifndef ORDEREVENT_H
#define ORDEREVENT_H

#include "Event.h"

/**
 * \class OrderEvent class
 * \brief Generates an OrderEvent object
 */
class OrderEvent : public Event
{
public:
    OrderEvent();
    OrderEvent(std::string type_, std::string instrument_, int units_,
               std::string orderType_, std::string side_);
    virtual ~OrderEvent();
    
    int getUnits();
    void setUnits(int units_);
    
    std::string getOrderType();
    void setOrderType(std::string orderType_);
    
    std::string getSide();
    void setSide(std::string side_);
    
private:
    int m_units;
    std::string m_orderType;
    std::string m_side;

};

#endif /* ORDEREVENT_H */

