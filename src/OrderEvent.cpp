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
OrderEvent::OrderEvent(const std::string& instrument_, const std::string& unitsQty_,
                       const std::string& orderType_, const std::string& side_) :
        Event("ORDER", instrument_),
        m_unitsQty(unitsQty_),
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
std::string OrderEvent::getUnitsQty() const
{
    return m_unitsQty;
}

/**
 * @param units_
 */
void OrderEvent::setUnitsQty(const std::string& unitsQty_)
{
    m_unitsQty = unitsQty_;
}

/**
 * @return m_orderType
 */
std::string OrderEvent::getOrderType() const
{
    return m_orderType;
}

/**
 * @param orderType_
 */
void OrderEvent::setOrderType(const std::string& orderType_)
{
    m_orderType = orderType_;
}

/**
 * @return m_side
 */
std::string OrderEvent::getSide() const
{
    return m_side;
}

/**
 * @param side_
 */
void OrderEvent::setSide(const std::string& side_)
{
    m_side = side_;
}