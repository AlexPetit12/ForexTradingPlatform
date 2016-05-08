/*
 * File:   OrderEventTests.h
 * Author: alexandrepetit
 *
 * Created on May 8, 2016, 4:03:22 PM
 */

#ifndef ORDEREVENTTESTS_H
#define ORDEREVENTTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class OrderEventTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OrderEventTests);

    CPPUNIT_TEST(testConstructor);

    CPPUNIT_TEST_SUITE_END();

public:
    OrderEventTests();
    virtual ~OrderEventTests();
    void setUp();
    void tearDown();

private:
    void testConstructor();
};

#endif /* ORDEREVENTTESTS_H */

