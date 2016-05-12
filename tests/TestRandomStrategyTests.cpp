/*
 * File:   TestRandomStrategyTests.cpp
 * Author: alexandrepetit
 *
 * Created on May 11, 2016, 8:06:52 PM
 */

#include "TestRandomStrategyTests.h"

#include "../src/TestRandomStrategy.h"
#include "../src/TickEvent.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestRandomStrategyTests);

TestRandomStrategyTests::TestRandomStrategyTests() {
}

TestRandomStrategyTests::~TestRandomStrategyTests() {
}

void TestRandomStrategyTests::setUp() {
}

void TestRandomStrategyTests::tearDown() {
}

void TestRandomStrategyTests::testCalculateSignals() {
    // Create a TestRandomStrategy object
    std::string firstInstrument = "EUR_USD";
    int firstUnits = 10;
    eventsQueue eQueue;
    TestRandomStrategy randomStrategy(firstInstrument, firstUnits, eQueue);
    
    // Test calculateSignals()
    std::string firstTime =       "12:34:56";
    double      firstBid =        10.5;
    double      firstAsk =        10.7;
    TickEvent tickEvent(firstInstrument, firstTime, firstBid, firstAsk);
    randomStrategy.calculateSignals(tickEvent);
    
    // Verify that an OrderEvent was added to eQueue
    size_t eQueueSizeAfterCalculateSignals = 1;
    CPPUNIT_ASSERT_EQUAL(eQueueSizeAfterCalculateSignals, eQueue.size());
    CPPUNIT_ASSERT_EQUAL(std::string("ORDER"), eQueue.back()->getType());
    
    // Call calculateSignals five times and verify that a 
    // new TickEvent was placed in eQueue
    for(int i = 0; i < 5; i++)
    {
        randomStrategy.calculateSignals(tickEvent);
    }
    
    // Verify that a second OrderEvent was added to eQueue
    eQueueSizeAfterCalculateSignals = 2;
    CPPUNIT_ASSERT_EQUAL(eQueueSizeAfterCalculateSignals, eQueue.size());
    CPPUNIT_ASSERT_EQUAL(std::string("ORDER"), eQueue.back()->getType());
    
}

