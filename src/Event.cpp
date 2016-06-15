/* 
 * File:   Event.cpp
 * Author: alexandrepetit
 * 
 * Created on May 7, 2016, 3:18 PM
 */

#include "Event.h"

/**
 * \brief Default constructor
 */
Event::Event() 
{
}

/**
 * @param type_
 * @param instrument_
 */
Event::Event(const std::string& type_, const std::string& instrument_) :
        m_eventType(type_),
        m_instrument(instrument_)
{
}

/**
 * \brief Destructor
 */
Event::~Event() 
{
}

Event& Event::operator =(const Event& rhs)
{
    m_eventType = rhs.getEventType();
    m_instrument = rhs.getInstrument();
}

/**
 * @return m_type
 */
std::string Event::getEventType() const
{
    return m_eventType;
}

/**
 * @param type_
 */
void Event::setEventType(const std::string& type_)
{
    m_eventType = type_;
}

/**
 * @return m_instrument
 */
std::string Event::getInstrument() const
{
    return m_instrument;
}

/**
 * @param instrument_
 */
void Event::setInstrument(const std::string& instrument_)
{
    m_instrument = instrument_;
}