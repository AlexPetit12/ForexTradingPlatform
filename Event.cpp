/* 
 * File:   Event.cpp
 * Author: alexandrepetit
 * 
 * Created on May 7, 2016, 3:18 PM
 */

#include "Event.h"

Event::Event() 
{
}

Event::Event(std::string type_, std::string instrument_) :
        m_type(type_),
        m_instrument(instrument_)
{
}

Event::~Event() 
{
}

std::string Event::getType()
{
    return m_type;
}

