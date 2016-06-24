#ifndef TRADING_H
#define TRADING_H

#include "Event.h"
#include "Execution.h"
#include "Portfolio.h"
#include "TestRandomStrategy.h"

void trade(eventsQueue& eventsQueue_, 
           TestRandomStrategy& strategy_, 
           Portfolio& portfolio_, 
           Execution& execution_);

#endif /* TRADING_H */
