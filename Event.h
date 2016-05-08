/* 
 * File:   Event.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:18 PM
 */

#include <string>

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    Event();
    //Event(std::string type_, std::string instrument_, std::string time_,
    //        double bid_, double ask_);
    Event(std::string type_, std::string instrument_);
    virtual ~Event();
    
    std::string getType();
    //std::string m_type;
    //std::string m_instrument;

protected:
    std::string m_type;
    std::string m_instrument;
    //std::string m_time;
    //double      m_bid;
    //double      m_ask;
    
private:

};

#endif /* EVENT_H */

