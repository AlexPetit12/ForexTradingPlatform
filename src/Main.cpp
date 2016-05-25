/* 
 * File:   Main.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:10 PM
 */

#include "StreamingForexPrices.h"
#include "TickEvent.h"
#include "Util.h"

int main(int argc, char** argv) 
{
    std::string accountId = util::getEnvironmentVariable("ACCOUNT_ID");
    std::string accessToken = util::getEnvironmentVariable("ACCESS_TOKEN");
    std::string instruments = "USD_CAD";
    std::string domain = "https://stream-fxpractice.oanda.com";

    eventsQueue eventsQueue;
    StreamingForexPrices Stream(domain, accessToken, accountId, 
                                instruments, eventsQueue);
  
#if notTests
    Stream.streamToQueue();
#endif
    
    return 0;
}

