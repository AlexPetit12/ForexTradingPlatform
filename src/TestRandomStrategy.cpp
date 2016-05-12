/* 
 * File:   TestRandomStrategy.cpp
 * Author: alexandrepetit
 * 
 * Created on May 8, 2016, 5:29 PM
 */

#include "TestRandomStrategy.h"

#include <array>
#include <random>

/**
 * @param instrument_
 * @param units_
 * @param eventsQueue_
 */
TestRandomStrategy::TestRandomStrategy(std::string instrument_, int units_, 
                                       eventsQueue& eventsQueue_) :
        m_instrument(instrument_),
        m_units(units_),
        m_eventsQueue(eventsQueue_),
        m_ticks(0)
{
}

/**
 * \brief Destructor
 */
TestRandomStrategy::~TestRandomStrategy() {
}

/**
 * @return m_ticks
 */
int TestRandomStrategy::getTicks() const
{
    return m_ticks;
}

/**
 * @param totalTicks_
 */
void TestRandomStrategy::setTicks(int totalTicks_)
{
    m_ticks = totalTicks_;
}

/**
 * @param increase_
 */
void TestRandomStrategy::increaseTicks(int increase_)
{
    m_ticks += increase_;
}

/**
 * \brief Calculate signals for a random strategy
 * @param event_
 */
void TestRandomStrategy::calculateSignals(Event& event_)
{
    if(event_.getType() == "TICK")
    {
        //increaseTicks();
        if(getTicks() % 5 == 0)
        {
            std::array<std::string, 2> sides = {"BUY", "SELL"};
            int randomSide = rand() % 2;
            std::string side = sides.at(randomSide);
	    m_eventsQueue.emplace(std::unique_ptr<OrderEvent>(
                new OrderEvent(m_instrument, m_units, "MKT", side)));
        }
        increaseTicks();
    }
}