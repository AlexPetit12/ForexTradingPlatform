/*
 * File:   EventTests.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 11:14:22 PM
 */

#ifndef EVENTTESTS_H
#define EVENTTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class EventTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(EventTests);

    CPPUNIT_TEST(testEvent);

    CPPUNIT_TEST_SUITE_END();

public:
    EventTests();
    virtual ~EventTests();
    void setUp();
    void tearDown();

private:
    void testEvent();
};

#endif /* EVENTTESTS_H */

