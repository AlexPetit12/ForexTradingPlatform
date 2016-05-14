/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UtilityTests.h
 * Author: alexandrepetit
 *
 * Created on May 14, 2016, 5:08:32 PM
 */

#ifndef UTILITYTESTS_H
#define UTILITYTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class UtilityTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(UtilityTests);

    CPPUNIT_TEST(testGetEnvironmentVariable);

    CPPUNIT_TEST_SUITE_END();

public:
    UtilityTests();
    virtual ~UtilityTests();
    void setUp();
    void tearDown();

private:
    void testGetEnvironmentVariable(void);
};

#endif /* UTILITYTESTS_H */

