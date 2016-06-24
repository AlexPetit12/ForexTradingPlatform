#include "Trading.h"

#include "TickEvent.h"

#include <iostream>
#include <thread>

void trade(eventsQueue& eventsQueue_, 
           TestRandomStrategy& strategy_, 
           Portfolio& portfolio_,
           Execution& execution_)
{
    while(true)
    {
        if(!eventsQueue_.empty())
        {
            std::unique_ptr<Event> pUniqueEvent = std::move(eventsQueue_.front());
            Event* pEvent = pUniqueEvent.get();
            
            eventsQueue_.pop();
            
            std::string eventType = pEvent->getEventType();
            
            if(eventType == "TICK")
            {
                std::cout << "TICK\n";
                TickEvent* pTickEvent = dynamic_cast<TickEvent*>(pEvent);
                if(pTickEvent == nullptr)
                {
                    std::cout << "nullptr in trade() TICK" << std::endl;
                    return;
                }
                strategy_.calculateSignals(pTickEvent);
            }
            else if(eventType == "SIGNAL")
            {
                std::cout << "SIGNAL\n";
                SignalEvent* pSignalEvent = dynamic_cast<SignalEvent*>(pEvent);
                if(pSignalEvent == nullptr)
                {
                    std::cout << "nullptr in trade() SIGNAL" << std::endl;
                }
                portfolio_.executeSignal(pSignalEvent);
            }
            else if(eventType == "ORDER")
            {
                std::cout << "ORDER\n";
                OrderEvent* pOrderEvent = dynamic_cast<OrderEvent*>(pEvent);
                if(pOrderEvent == nullptr)
                {
                    std::cout << "nullptr in trade() ORDER" << std::endl;
                    return;
                }
                execution_.executeOrder(pOrderEvent);
            }
            
        }
        
        // Heartbeat
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}