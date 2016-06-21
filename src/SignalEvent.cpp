/* 
 * File:   SignalEvent.cpp
 * Author: alexandrepetit
 * 
 * Created on June 14, 2016, 9:51 PM
 */

#include "SignalEvent.h"

/**
 * \brief Default constructor
 */
SignalEvent::SignalEvent() 
{
}

/**
 * @param instrument_
 * @param orderType_
 * @param side_
 */
SignalEvent::SignalEvent(const std::string& instrument_, const std::string& orderType_, 
                         const std::string& side_) :
        Event("SIGNAL", instrument_),
        m_orderType(orderType_),
        m_side(side_)
{
}

/**
 * brief Destructor
 */
SignalEvent::~SignalEvent() 
{
}

/**
 * @param orderType_
 */
void SignalEvent::setOrderType(const std::string& orderType_)
{
    m_orderType = orderType_;
}

/**
 * @param side_
 */
void SignalEvent::setSide(const std::string& side_)
{
    m_side = side_;
}
/**
 * @return m_orderType
 */
std::string SignalEvent::getOrderType() const
{
    return m_orderType;
}

/**
 * @return m_side
 */
std::string SignalEvent::getSide() const
{
    return m_side;
}