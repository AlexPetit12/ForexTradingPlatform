/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TickEvent.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 5:07:26 PM
 */

#ifndef TICKEVENT_H
#define TICKEVENT_H

#include <cppunit/extensions/HelperMacros.h>

class TickEvent : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TickEvent);

    CPPUNIT_TEST(testTickEventConstructor);

    CPPUNIT_TEST_SUITE_END();

public:
    TickEvent();
    virtual ~TickEvent();
    void setUp();
    void tearDown();

private:
    void testTickEventConstructor();
};

#endif /* TICKEVENT_H */

