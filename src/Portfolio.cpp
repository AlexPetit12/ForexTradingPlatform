/* 
 * File:   Portfolio.cpp
 * Author: alexandrepetit
 * 
 * Created on June 19, 2016, 4:48 PM
 */

#include "Portfolio.h"

/**
 * @param ticker_
 * @param eventsQueue_
 * @param base_
 * @param leverage_
 * @param equity_
 * @param riskPerTrade_
 */
Portfolio::Portfolio(StreamingForexPrices& stream_, eventsQueue& eventsQueue_, const std::string& base_, 
                     const int leverage_, const double equity_, const double riskPerTrade_) :
        m_stream(stream_),
        m_eventsQueue(eventsQueue_),
        m_base(base_),
        m_leverage(leverage_),
        m_equity(equity_),
        m_balance(equity_),
        m_riskPerTrade(riskPerTrade_),
        m_tradeUnits(calculateRiskPositionSize())
{
}

/**
 * \brief Destructor
 */
Portfolio::~Portfolio() 
{
}

/**
 * @return risk position size
 */
int Portfolio::calculateRiskPositionSize()
{
    return m_equity * m_riskPerTrade;
}

/**
 * @param side_
 * @param market_
 * @param units_
 * @param exposure_
 * @param addPrice_
 * @param removePrice_
 */
void Portfolio::addNewPosition(const std::string& side_, const std::string& market_, const std::string& units_, 
                               const double exposure_, const double addPrice_, const double removePrice_)
{
    m_positions.emplace(market_, std::unique_ptr<Position>(new Position(
                        side_, market_, units_, exposure_, addPrice_, removePrice_)));
}

/**
 * @param market_
 * @param units_
 * @param exposure_
 * @param addPrice_
 * @param removePrice_
 * @return 
 */
bool Portfolio::addPositionsUnits(const std::string& market_, const std::string& units_, const double exposure_, 
                                  const double addPrice_, const double removePrice_)
{
    if(m_positions.find(market_) == m_positions.end())
    {
        return false; // Market type not found in current positions
    }
    
    Position* pPosition = m_positions[market_].get();
    std::string units = pPosition->getUnits();
    
    int newTotalUnits = std::stoi(units) + std::stoi(units_);
    double newTotalCost = pPosition->getAveragePrice() * std::stoi(units) + addPrice_ * std::stoi(units_);
    
    pPosition->increaseExposureBy(exposure_);
    pPosition->setAveragePrice(newTotalCost / newTotalUnits );
    pPosition->setUnits(std::to_string(newTotalUnits));
    pPosition->updatePositionPrice(removePrice_);
    
    return true;
    
}

/**
 * @param market_
 * @param units_
 * @param removePrice_
 * @return 
 */
bool Portfolio::removePositionsUnits(const std::string& market_, const std::string& units_, const double removePrice_)
{
    if(m_positions.find(market_) == m_positions.end())
    {
        return false; // Market type not found in current positions
    }
    
    Position* pPosition = m_positions[market_].get();
    
    std::string units = pPosition->getUnits();
    int exposure = std::stoi(units);
    
    pPosition->increaseExposureBy(-1 * exposure);
    pPosition->updatePositionPrice(removePrice_);
    
    double pnl = pPosition->calculatePips() * exposure / removePrice_;
    increaseBalanceBy(pnl);
    
    return true;
}

/**
 * @param market_
 * @param removePrice_
 * @return 
 */
bool Portfolio::closePosition(const std::string& market_, const double removePrice_) 
{
    if(m_positions.find(market_) == m_positions.end())
    {
        return false; // Market type not found in current positions
    }
    
    Position* pPosition = m_positions[market_].get();
    std::string units = pPosition->getUnits();
    
    int exposure = std::stoi(units);
    pPosition->updatePositionPrice(removePrice_);
    
    double pnl = pPosition->calculatePips() * exposure / removePrice_;
    increaseBalanceBy(pnl);
    
    m_positions.erase(market_);
    
    return true;
}

/**
 * @param pSignalEvent_
 */
void Portfolio::executeSignal(const SignalEvent* pSignalEvent_)
{
    std::string side = pSignalEvent_->getSide();
    std::string market = pSignalEvent_->getInstrument();
    int units = getUnits();
    
    double addPrice = m_stream.getCurrentAsk();
    double removePrice = m_stream.getCurrentBid();
    double exposure = double(units);
    
    if(m_positions.find(market) == m_positions.end())
    {
        // Market type not found in current positions, so create one
        addNewPosition(side, market, std::to_string(units), exposure, addPrice, removePrice);
        
        // New OrderEvent
        m_eventsQueue.emplace(std::unique_ptr<OrderEvent>(
                new OrderEvent(market, std::to_string(units), "market", "buy")));
    }
    else
    {
        Position* pPosition = m_positions[market].get();
        
        if(side == pPosition->getSide())
        {
            addNewPosition(side, market, std::to_string(units), exposure, addPrice, removePrice);
        }
        else
        {
            if(units == std::stoi(pPosition->getUnits()))
            {
                closePosition(market, removePrice);
                m_eventsQueue.emplace(std::unique_ptr<OrderEvent>(
                    new OrderEvent(market, std::to_string(units), "market", "sell")));
            }
            else if(units < std::stoi(pPosition->getUnits()))
            {
                removePositionsUnits(market, std::to_string(units), removePrice);
            }
            else
            {
                int newUnits = units - std::stoi(pPosition->getUnits());
                closePosition(market, removePrice);
            
            
                std::string newSide;
                if(side == "buy")
                {
                    newSide = "sell";
                }
                else
                {
                    newSide = "buy";
                }
                
                double newExposure = units;
                addNewPosition(newSide, market, std::to_string(newUnits), newExposure, addPrice, removePrice);
            }
        }
    }
    
    std::cout << "Balance: " << getBalance() << std::endl;
}

/**
 * @param balanceIncrease_
 */
void Portfolio::increaseBalanceBy(const double balanceIncrease_)
{
    double currentBalance = getBalance();
    setBalance(currentBalance + balanceIncrease_);
}

/**
 * @param balance_
 */
void Portfolio::setBalance(const double balance_)
{
    m_balance = balance_;
}

/**
 * @return m_balance
 */
double Portfolio::getBalance() const
{
    return m_balance;
}

/**
 * @return m_tradeUnits
 */
int Portfolio::getUnits() const
{
    return m_tradeUnits;
}
