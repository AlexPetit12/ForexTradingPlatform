/*
 * File:   UtilityTests.cpp
 * Author: alexandrepetit
 *
 * Created on May 14, 2016, 5:08:32 PM
 */

#include "UtilityTests.h"

#include "../src/Util.h"

CPPUNIT_TEST_SUITE_REGISTRATION(UtilityTests);

UtilityTests::UtilityTests() {
}

UtilityTests::~UtilityTests() {
}

void UtilityTests::setUp() {
}

void UtilityTests::tearDown() {
}

void UtilityTests::testGetEnvironmentVariable(void) 
{
    std::string realValue = "test";
    std::string envVarName = "EnvVarTest";
    std::string envVarValue = util::getEnvironmentVariable(envVarName);
    CPPUNIT_ASSERT_EQUAL(realValue, envVarValue);
}

