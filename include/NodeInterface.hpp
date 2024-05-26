//
// Created by John on 5/26/2024.
//

#ifndef LOGICGATES_EDITOR_QT_NODEINTERFACE_HPP
#define LOGICGATES_EDITOR_QT_NODEINTERFACE_HPP

enum State {DISABLED, OFF, ON};

// Here we will implement our Observer Pattern
class IObserver
{
public:
    virtual ~IObserver()= default;
    virtual void Update(State state) = 0;
};

class ISubject
{
public:
    virtual ~ISubject()= default;
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};


#endif //LOGICGATES_EDITOR_QT_NODEINTERFACE_HPP
