/*
 * File:   EventTests.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 11:14:23 PM
 */

#include "EventTests.h"

#include "../src/Event.h"

CPPUNIT_TEST_SUITE_REGISTRATION(EventTests);

EventTests::EventTests() {
}

EventTests::~EventTests() {
}

void EventTests::setUp() {
}

void EventTests::tearDown() {
}

void EventTests::testConstructor() {
    // Variables to test constructor and getters
    std::string firstType =        "TICK";
    std::string firstInstrument =  "EUR_USD";
    
    Event E(firstType, firstInstrument);
    
    CPPUNIT_ASSERT_EQUAL(firstType, E.getType());
    CPPUNIT_ASSERT_EQUAL(firstInstrument, E.getInstrument());
    
    // New variables to test setters
    std::string secondType =       "TEST";
    std::string secondInstrument = "CAN_JPN";
    
    E.setType(secondType);
    E.setInstrument(secondInstrument);
    
    CPPUNIT_ASSERT_EQUAL(secondType, E.getType());
    CPPUNIT_ASSERT_EQUAL(secondInstrument, E.getInstrument());
}

