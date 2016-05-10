/*
 * File:   OrderEventTests.cpp
 * Author: alexandrepetit
 *
 * Created on May 8, 2016, 4:03:23 PM
 */

#include "OrderEventTests.h"

#include "../OrderEvent.h"

CPPUNIT_TEST_SUITE_REGISTRATION(OrderEventTests);

OrderEventTests::OrderEventTests() {
}

OrderEventTests::~OrderEventTests() {
}

void OrderEventTests::setUp() {
}

void OrderEventTests::tearDown() {
}

void OrderEventTests::testConstructor() {
    // Variables to test constructor and getters
    //std::string firstType =       "TICK";
    std::string firstInstrument = "EUR_USD";
    int firstUnits =              10;
    std::string firstOrderType =  "MKT";
    std::string firstSide =       "LONG";
    
    OrderEvent O(firstInstrument, firstUnits, firstOrderType, firstSide);
    
    //CPPUNIT_ASSERT_EQUAL(firstType, O.getType());
    CPPUNIT_ASSERT_EQUAL(firstInstrument, O.getInstrument());
    CPPUNIT_ASSERT_EQUAL(firstUnits, O.getUnits());
    CPPUNIT_ASSERT_EQUAL(firstOrderType, O.getOrderType());
    CPPUNIT_ASSERT_EQUAL(firstSide, O.getSide());
    
    // New variables to test setters
    std::string secondType =       "Order";
    std::string secondInstrument = "CAN_JPN";
    int secondUnits =              20;
    std::string secondOrderType =  "LMT";
    std::string secondSide =       "SHORT";
    
    O.setType(secondType);
    O.setInstrument(secondInstrument);
    O.setUnits(secondUnits);
    O.setOrderType(secondOrderType);
    O.setSide(secondSide);
    
    CPPUNIT_ASSERT_EQUAL(secondType, O.getType());
    CPPUNIT_ASSERT_EQUAL(secondInstrument, O.getInstrument());
    CPPUNIT_ASSERT_EQUAL(secondUnits, O.getUnits());
    CPPUNIT_ASSERT_EQUAL(secondOrderType, O.getOrderType());
    CPPUNIT_ASSERT_EQUAL(secondSide, O.getSide());
}

