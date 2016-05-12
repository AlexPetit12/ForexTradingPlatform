/*
 * File:   TestRandomStrategyTests.h
 * Author: alexandrepetit
 *
 * Created on May 11, 2016, 8:06:51 PM
 */

#ifndef TESTRANDOMSTRATEGYTESTS_H
#define TESTRANDOMSTRATEGYTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class TestRandomStrategyTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestRandomStrategyTests);

    CPPUNIT_TEST(testCalculateSignals);

    CPPUNIT_TEST_SUITE_END();

public:
    TestRandomStrategyTests();
    virtual ~TestRandomStrategyTests();
    void setUp();
    void tearDown();

private:
    void testCalculateSignals();
};

#endif /* TESTRANDOMSTRATEGYTESTS_H */

