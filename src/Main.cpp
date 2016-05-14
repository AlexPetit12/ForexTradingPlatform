/* 
 * File:   Main.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:10 PM
 */

#include "TickEvent.h"
#include "Util.h"

std::string type = "TICK";
std::string instrument = "EUR_USD";
std::string theTime = "12:34:56";
double      bid = 10.5;
double      ask = 10.7;

int main(int argc, char** argv) 
{
    std::string val = util::getEnvironmentVariable("ACCESS_TOKEN");
    std::cout << val;
    return 0;
}

