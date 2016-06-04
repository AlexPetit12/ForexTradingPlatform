/* 
 * File:   Main.cpp
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:10 PM
 */

#include <thread>

#include "StreamingForexPrices.h"
//#include "TickEvent.h"
#include "Trading.h"
#include "Util.h"

int main(int argc, char** argv) 
{
    std::string accountId =     util::getEnvironmentVariable("ACCOUNT_ID");
    std::string accessToken =   util::getEnvironmentVariable("ACCESS_TOKEN");
    std::string instruments =   "USD_CAD";
    std::string apiDomain =     "https://api-fxpractice.oanda.com";
    std::string streamDomain =  "https://stream-fxpractice.oanda.com";
    std::string unitsQty =      "2";
    
    // Empty events queue
    eventsQueue eventsQueue;
    
    // Stream
    StreamingForexPrices stream(streamDomain, accessToken, accountId, instruments, eventsQueue);
    
    // Execution
    Execution execution(apiDomain, accessToken, accountId);
    
    // Strategy
    TestRandomStrategy strategy(instruments, unitsQty, eventsQueue);
    
    // Threads
    std::thread tradeThread(trade, std::ref(eventsQueue), std::ref(strategy), std::ref(execution));
    std::thread streamThread(&StreamingForexPrices::streamToQueue, stream);
    tradeThread.join();
    streamThread.join();
    
    return 0;
}

