/* 
 * File:   Portfolio.h
 * Author: alexandrepetit
 *
 * Created on June 19, 2016, 4:48 PM
 */

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <map>

#include "OrderEvent.h"
#include "Position.h"

class Portfolio {
public:
    Portfolio(const std::string& ticker_, eventsQueue& eventsQueue_, const std::string& base_, 
              const int& leverage_ = 20, const double& equity_ = 100000.0, const double& riskPerTrade_ = 0.02);
    virtual ~Portfolio();
    
    int calculateRiskPositionSize();
    void addNewPosition(const std::string& side_, const std::string& market_, const std::string& units_, 
                        const double& exposure_, const double& addPrice_, const double& removePrice_);
    bool addPositionsUnits(const std::string& market_, const std::string& units_, 
                           const double& exposure_, const double& addPrice_, const double& removePrice_);
private:
    std::string m_ticker;
    eventsQueue& m_eventsQueue;
    std::string m_base;
    int m_leverage;
    double m_equity;
    double m_balance;
    double m_riskPerTrade;
    int m_tradeUnits;
    std::map<std::string, std::unique_ptr<Position>> m_positions;

};

#endif /* PORTFOLIO_H */

