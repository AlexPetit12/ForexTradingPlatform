/*
 * File:   EventTests.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 11:14:23 PM
 */

#include "EventTests.h"

#include "../Event.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EventTests);

EventTests::EventTests() {
}

EventTests::~EventTests() {
}

void EventTests::setUp() {
}

void EventTests::tearDown() {
}

void EventTests::testEvent() {
    std::string firstType =        "TICK";
    std::string firstInstrument =  "EUR_USD";
    std::string secondType =       "EVENT";
    std::string secondInstrument = "CAN_JPN";
    
    Event E(firstType, firstInstrument);
    
    E.setType(secondType);
    E.setInstrument(secondInstrument);
    
    CPPUNIT_ASSERT_EQUAL(secondType, E.getType());
    CPPUNIT_ASSERT_EQUAL(secondInstrument, E.getInstrument());
}

