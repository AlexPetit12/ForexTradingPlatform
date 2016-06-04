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
    OrderEvent(const std::string& instrument_, const std::string& unitsQty_,
               const std::string& orderType_, const std::string& side_);
    virtual ~OrderEvent();
    
    std::string getUnitsQty() const;
    void setUnitsQty(const std::string& unitsQty_);
    
    std::string getOrderType() const;
    void setOrderType(const std::string& orderType_);
    
    std::string getSide() const;
    void setSide(const std::string& side_);
    
private:
    std::string m_unitsQty;
    std::string m_orderType;
    std::string m_side;

};

#endif /* ORDEREVENT_H */

