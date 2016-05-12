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
Event::Event(std::string type_, std::string instrument_) :
        m_type(type_),
        m_instrument(instrument_)
{
}

/**
 * \brief Destructor
 */
Event::~Event() 
{
}

/**
 * @return m_type
 */
std::string Event::getType() const
{
    return m_type;
}

/**
 * @param type_
 */
void Event::setType(std::string type_)
{
    m_type = type_;
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
void Event::setInstrument(std::string instrument_)
{
    m_instrument = instrument_;
}