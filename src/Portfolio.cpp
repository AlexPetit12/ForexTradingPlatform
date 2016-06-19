/* 
 * File:   Portfolio.cpp
 * Author: alexandrepetit
 * 
 * Created on June 19, 2016, 4:48 PM
 */

#include "Portfolio.h"

Portfolio::Portfolio(const std::string& ticker_, eventsQueue& eventsQueue_, const std::string& base_, 
                     const int& leverage_, const double& equity_, const double& riskPerTrade_) :
        m_ticker(ticker_),
        m_eventsQueue(eventsQueue_),
        m_base(base_),
        m_leverage(leverage_),
        m_equity(equity_),
        m_balance(equity_),
        m_riskPerTrade(riskPerTrade_),
        m_tradeUnits(calculateRiskPositionSize())
{
}


Portfolio::~Portfolio() 
{
}

int Portfolio::calculateRiskPositionSize()
{
    return m_equity * m_riskPerTrade;
}

void Portfolio::addNewPosition(const std::string& side_, const std::string& market_, const std::string& units_, 
                               const double& exposure_, const double& addPrice_, const double& removePrice_)
{
    m_positions.emplace(market_, std::unique_ptr<Position>(new Position(
                        side_, market_, units_, exposure_, addPrice_, removePrice_)));
}

bool Portfolio::addPositionsUnits(const std::string& market_, const std::string& units_, const double& exposure_, 
                                  const double& addPrice_, const double& removePrice_)
{
    if(m_positions.find(market_) == m_positions.end())
    {
        return false; // Market_ type not found in current positions
    }
    else
    {
        Position* pPosition = m_positions[market_].get();
        return true;
    }
}