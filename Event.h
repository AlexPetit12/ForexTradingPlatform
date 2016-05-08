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
    Event(std::string type_, std::string instrument_);
    virtual ~Event();
    
    std::string getType();
    void setType(std::string type_);
    
    std::string getInstrument();
    void setInstrument(std::string instrument_);

protected:
    std::string m_type;
    std::string m_instrument;

};

#endif /* EVENT_H */

