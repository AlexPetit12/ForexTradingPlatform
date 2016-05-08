/* 
 * File:   OrderEvent.cpp
 * Author: alexandrepetit
 * 
 * Created on May 8, 2016, 3:48 PM
 */

#include "OrderEvent.h"

/**
 * \brief Default constructor
 */
OrderEvent::OrderEvent() {
}

/**
 * @param type_
 * @param instrument_
 * @param units_
 * @param orderType_
 * @param side_
 */
OrderEvent::OrderEvent(std::string type_, std::string instrument_, int units_,
                       std::string orderType_, std::string side_) :
        Event(type_, instrument_),
        m_units(units_),
        m_orderType(orderType_),
        m_side(side_)
{
}

/**
 * \brief Destructor
 */
OrderEvent::~OrderEvent() 
{
}

/**
 * @return m_units
 */
int OrderEvent::getUnits()
{
    return m_units;
}

/**
 * @param units_
 */
void OrderEvent::setUnits(int units_)
{
    m_units = units_;
}

/**
 * @return m_orderType
 */
std::string OrderEvent::getOrderType()
{
    return m_orderType;
}

/**
 * @param orderType_
 */
void OrderEvent::setOrderType(std::string orderType_)
{
    m_orderType = orderType_;
}

/**
 * @return m_side
 */
std::string OrderEvent::getSide()
{
    return m_side;
}

/**
 * @param side_
 */
void OrderEvent::setSide(std::string side_)
{
    m_side = side_;
}