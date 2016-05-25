/* 
 * File:   Event.h
 * Author: alexandrepetit
 *
 * Created on May 7, 2016, 3:18 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include <memory>
#include <queue>
#include <string>

/**
 * \class Event
 * \brief Generates an Event object
 */
class Event {
public:
    Event();
    Event(std::string type_, std::string instrument_);
    virtual ~Event();
    
    std::string getType() const;
    void setType(std::string type_);
    
    std::string getInstrument() const;
    void setInstrument(std::string instrument_);

protected:
    std::string m_type;
    std::string m_instrument;

};

typedef std::queue<std::unique_ptr<Event>> eventsQueue;

#endif /* EVENT_H */

