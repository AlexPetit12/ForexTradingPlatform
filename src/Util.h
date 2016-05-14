/* 
 * File:   Util.h
 * Author: alexandrepetit
 *
 * Created on May 14, 2016, 5:00 PM
 */

#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <iostream>
#include <string>

namespace util
{
    std::string getEnvironmentVariable(const std::string& variable); 
}

#endif /* UTIL_H */

