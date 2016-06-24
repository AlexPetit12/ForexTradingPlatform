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
    Position(const std::string& side_, const std::string& market_, const std::string& units_,
             const double& exposure_, const double& averagePrice_, const double& currentPrice_);
    virtual ~Position();
    
    double calculatePips();
    double calculateProfitBase();
    double calculateProfitPercentage();
    void   updatePositionPrice(const double& currentPrice_);
    void increaseExposureBy(const double& exposureIncrease_);
    
    // Setters
    void setUnits(const std::string& units_);
    void setExposure(const double& exposure_);
    void setAveragePrice(const double& averagePrice_);
    
    // Getters
    std::string getUnits() const;
    double getExposure() const;
    double getAveragePrice() const;
    std::string getSide() const;
    
private:
    std::string m_side;
    std::string m_market;
    std::string m_units;
    double      m_exposure;
    double      m_averagePrice;
    double      m_currentPrice;
    double      m_profitBase;
    double      m_profitPercentage;
};

#endif /* POSITION_H */

