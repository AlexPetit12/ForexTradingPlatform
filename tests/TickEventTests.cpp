/*
 * File:   TickEventTest.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 5:21:12 PM
 */

#include "TickEventTests.h"

#include "../TickEvent.h"

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
    // Variables to test constructor and getters
    //std::string firstType =       "TICK";
    std::string firstInstrument = "EUR_USD";
    std::string firstTime =       "12:34:56";
    double      firstBid =        10.5;
    double      firstAsk =        10.7;
    
    TickEvent T(firstInstrument, firstTime, firstBid, firstAsk);
    
    //CPPUNIT_ASSERT_EQUAL(firstType, T.getType());
    CPPUNIT_ASSERT_EQUAL(firstInstrument, T.getInstrument());
    CPPUNIT_ASSERT_EQUAL(firstTime, T.getTime());
    CPPUNIT_ASSERT_EQUAL(firstBid, T.getBid());
    CPPUNIT_ASSERT_EQUAL(firstAsk, T.getAsk());
    
    // New variables to test setters
    std::string secondType =       "Order";
    std::string secondInstrument = "CAN_JPN";
    std::string secondTime =       "05:21:56";
    double      secondBid =        21.5;
    double      secondAsk =        22.7;
    
    T.setType(secondType);
    T.setInstrument(secondInstrument);
    T.setTime(secondTime);
    T.setBid(secondBid);
    T.setAsk(secondAsk);
    
    CPPUNIT_ASSERT_EQUAL(secondType, T.getType());
    CPPUNIT_ASSERT_EQUAL(secondInstrument, T.getInstrument());
    CPPUNIT_ASSERT_EQUAL(secondTime, T.getTime());
    CPPUNIT_ASSERT_EQUAL(secondBid, T.getBid());
    CPPUNIT_ASSERT_EQUAL(secondAsk, T.getAsk());
}

