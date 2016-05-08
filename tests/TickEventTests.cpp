/*
 * File:   TickEventTest.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 5:21:12 PM
 */

#include "TickEventTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TickEventTest);

TickEventTest::TickEventTest() {
}

TickEventTest::~TickEventTest() {
}

void TickEventTest::setUp() {
}

void TickEventTest::tearDown() {
}

void TickEventTest::testConstructor() {
    std::string type = "TICK";
    std::string instrument = "EUR_USD";
    std::string theTime = "12:34:56";
    double      bid = 10.5;
    double      ask = 10.7;
    
    TickEvent T(type, instrument, theTime, bid, ask);
    
    CPPUNIT_ASSERT_EQUAL(type, T.getType());
}

