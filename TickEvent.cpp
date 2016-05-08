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

TickEvent::~TickEvent() {
}

