/* 
 * File:   Position.h
 * Author: alexandrepetit
 *
 * Created on June 17, 2016, 10:24 PM
 */

#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position 
{
public:
    Position();
    Position(const std::string& side_, const std::string& market_, const std::string& quantity_,
             const double& exposure_, const double& averagePrice_, const double& currentPrice_);
    virtual ~Position();
    
    double calculatePips();
    double calculateProfitBase();
    double calculateProfitPercentage();
    void   updatePositionPrice(const double& currentPrice_);
    
private:
    std::string m_side;
    std::string m_market;
    std::string m_quantity;
    double      m_exposure;
    double      m_averagePrice;
    double      m_currentPrice;
    double      m_profitBase;
    double      m_profitPercentage;
};

#endif /* POSITION_H */

