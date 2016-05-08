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

std::string Event::getInstrument()
{
    return m_instrument;
}

void Event::setType(std::string type_)
{
    m_type = type_;
}

void Event::setInstrument(std::string instrument_)
{
    m_instrument = instrument_;
}