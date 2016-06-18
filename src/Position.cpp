/* 
 * File:   Position.cpp
 * Author: alexandrepetit
 * 
 * Created on June 17, 2016, 10:24 PM
 */

#include "Position.h"

Position::Position() 
{
}

Position::Position(const std::string& side_, const std::string& market_, const std::string& quantity_, 
                   const double& exposure_, const double& averagePrice_, const double& currentPrice_) :
        m_side(side_),
        m_market(market_),
        m_quantity(quantity_),
        m_exposure(exposure_),
        m_averagePrice(averagePrice_),
        m_currentPrice(currentPrice_),
        m_profitBase(calculateProfitBase()),
        m_profitPercentage(calculateProfitPercentage())
{
}

Position::~Position() 
{
}

double Position::calculatePips()
{
    double mult = 1.0;
    
    if(m_side == "SHORT")
    {
        mult = -1.0;
    }
    
    return mult * (m_currentPrice - m_averagePrice);
}

double Position::calculateProfitBase()
{
    double pips = calculatePips();
    return pips * m_exposure / m_currentPrice;
}

double Position::calculateProfitPercentage()
{
    return m_profitBase / m_exposure * 100;
}

void Position::updatePositionPrice(const double& currentPrice_)
{
    m_currentPrice     = currentPrice_;
    m_profitBase       = calculateProfitBase();
    m_profitPercentage = calculateProfitPercentage();
}
