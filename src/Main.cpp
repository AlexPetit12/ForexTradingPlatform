/* 
 * File:   Main.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:10 PM
 */

#include <cstdlib>
#include <iostream>

#include "TickEvent.h"

std::string type = "TICK";
std::string instrument = "EUR_USD";
std::string theTime = "12:34:56";
double      bid = 10.5;
double      ask = 10.7;
    
int main(int argc, char** argv) {
    
    TickEvent T(instrument, theTime, bid, ask);
    std::cout << T.getType() << std::endl;
    
    return 0;
}

