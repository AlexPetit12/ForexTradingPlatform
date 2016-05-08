/*
 * File:   TickEventTest.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 5:21:11 PM
 */

#ifndef TICKEVENTTEST_H
#define TICKEVENTTEST_H

#include <cppunit/extensions/HelperMacros.h>

class TickEventTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TickEventTest);

    CPPUNIT_TEST(testConstructor);

    CPPUNIT_TEST_SUITE_END();

public:
    TickEventTest();
    virtual ~TickEventTest();
    void setUp();
    void tearDown();

private:
    void testConstructor();
};

#endif /* TICKEVENTTEST_H */

