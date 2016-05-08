/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TickEventTests.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 5:02:31 PM
 */

#ifndef TICKEVENTTESTS_H
#define TICKEVENTTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class TickEventTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TickEventTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    TickEventTests();
    virtual ~TickEventTests();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif /* TICKEVENTTESTS_H */

