/* 
 * File:   Position.cpp
 * Author: alexandrepetit
 * 
 * Created on June 17, 2016, 10:24 PM
 */

#include "Position.h"

/**
 * \brief Default constructor
 */
Position::Position() 
{
}

/**
 * @param side_
 * @param market_
 * @param quantity_
 * @param exposure_
 * @param averagePrice_
 * @param currentPrice_
 */
Position::Position(const std::string& side_, const std::string& market_, const std::string& units_, 
                   const double& exposure_, const double& averagePrice_, const double& currentPrice_) :
        m_side(side_),
        m_market(market_),
        m_units(units_),
        m_exposure(exposure_),
        m_averagePrice(averagePrice_),
        m_currentPrice(currentPrice_),
        m_profitBase(calculateProfitBase()),
        m_profitPercentage(calculateProfitPercentage())
{
}

/**
 * \brief Destructor
 */
Position::~Position() 
{
}

/**
 * @return Pips
 */
double Position::calculatePips()
{
    double mult = 1.0;
    
    if(m_side == "SHORT")
    {
        mult = -1.0;
    }
    
    return mult * (m_currentPrice - m_averagePrice);
}

/**
 * @return Profit base
 */
double Position::calculateProfitBase()
{
    double pips = calculatePips();
    return pips * m_exposure / m_currentPrice;
}

/**
 * @return Profit percentage
 */
double Position::calculateProfitPercentage()
{
    return m_profitBase / m_exposure * 100;
}

/**
 * @param currentPrice_
 */
void Position::updatePositionPrice(const double& currentPrice_)
{
    m_currentPrice     = currentPrice_;
    m_profitBase       = calculateProfitBase();
    m_profitPercentage = calculateProfitPercentage();
}

/**
 * @param exposureIncrease_
 */
void Position::increaseExposureBy(const double& exposureIncrease_)
{
    double newExposure = getExposure() + exposureIncrease_;
    setExposure(newExposure);
}
/**
 * @param units_
 */
void Position::setUnits(const std::string& units_) 
{
    m_units = units_;
}

/**
 * @param averagePrice_
 */
void Position::setAveragePrice(const double& averagePrice_) 
{
    m_averagePrice = averagePrice_;
}

/**
 * @param exposure_
 */
void Position::setExposure(const double& exposure_)
{
    m_exposure = exposure_;
}

/**
 * @return m_units
 */
std::string Position::getUnits() const
{
    return m_units;
}

/**
 * @return double: m_exposure
 */
double Position::getExposure() const
{
    return m_exposure;
}

/**
 * @return double: m_averagePrice
 */
double Position::getAveragePrice() const
{
    return m_averagePrice;
}

/**
 * @return std::string: m_side
 */
std::string Position::getSide() const
{
    return m_side;
}
