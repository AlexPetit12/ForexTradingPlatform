/* 
 * File:   TickEvent.cpp
 * Author: alexandrepetit
 * 
 * Created on May 7, 2016, 4:07 PM
 */

#include "TickEvent.h"

TickEvent::TickEvent() {
}

TickEvent::TickEvent(std::string type_, std::string instrument_, 
                     std::string time_, double bid_, double ask_) :
        Event(type_, instrument_),
        m_time(time_),
        m_bid(bid_),
        m_ask(ask_)
{
}

TickEvent::~TickEvent() 
{
}

std::string TickEvent::getTime()
{
    return m_time;
}

void TickEvent::setTime(std::string time_)
{
    m_time = time_;
}

double TickEvent::getBid()
{
    return m_bid;
}

void TickEvent::setBid(double bid_)
{
    m_bid = bid_;
}

double TickEvent::getAsk()
{
    return m_ask;
}

void TickEvent::setAsk(double ask_)
{
    m_ask = ask_;
}