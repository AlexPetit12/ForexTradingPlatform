/* 
 * File:   SignalEvent.cpp
 * Author: alexandrepetit
 * 
 * Created on June 14, 2016, 9:51 PM
 */

#include "SignalEvent.h"

SignalEvent::SignalEvent() 
{
}

SignalEvent::SignalEvent(const std::string& instrument_, const std::string& orderType_, 
                         const std::string& side_) :
        Event("SIGNAL", instrument_),
        m_orderType(orderType_),
        m_side(side_)
{
}


SignalEvent::~SignalEvent() 
{
}

