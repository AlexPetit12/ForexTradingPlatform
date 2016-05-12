/* 
 * File:   TickEvent.cpp
 * Author: alexandrepetit
 * 
 * Created on May 7, 2016, 4:07 PM
 */

#include "TickEvent.h"

/**
 * \brief Default constructor
 */
TickEvent::TickEvent() 
{
}

/**
 * @param type_
 * @param instrument_
 * @param time_
 * @param bid_
 * @param ask_
 */
TickEvent::TickEvent(std::string instrument_, std::string time_, 
                     double bid_, double ask_) :
        Event("TICK", instrument_),
        m_time(time_),
        m_bid(bid_),
        m_ask(ask_)
{
}

/**
 * \brief Destructor
 */
TickEvent::~TickEvent() 
{
}

/**
 * @return m_time
 */
std::string TickEvent::getTime() const
{
    return m_time;
}

/**
 * @param time_
 */
void TickEvent::setTime(std::string time_)
{
    m_time = time_;
}

/**
 * @return m_bid
 */
double TickEvent::getBid() const
{
    return m_bid;
}

/**
 * @param bid_
 */
void TickEvent::setBid(double bid_)
{
    m_bid = bid_;
}

/**
 * @return m_ask
 */
double TickEvent::getAsk() const
{
    return m_ask;
}

/**
 * @param ask_
 */
void TickEvent::setAsk(double ask_)
{
    m_ask = ask_;
}