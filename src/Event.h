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
    Event(const std::string& type_, const std::string& instrument_);
    virtual ~Event();
    Event& operator=(const Event &rhs);
    
    std::string getEventType() const;
    void setEventType(const std::string& type_);
    
    std::string getInstrument() const;
    void setInstrument(const std::string& instrument_);

protected:
    std::string m_eventType;
    std::string m_instrument;

};

typedef std::queue<std::unique_ptr<Event>> eventsQueue;

#endif /* EVENT_H */

