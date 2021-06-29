//
// Created by andre on 28/06/21.
//

#ifndef QT_SLIDESHOW_SUBJECT_H
#define QT_SLIDESHOW_SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {
public:
    void subscribe(Observer *o) {
        observers.push_back(o);
    }

    void unsubscribe(Observer *o) {
        observers.push_back(o);
    }

    virtual void notify() = 0;

    virtual ~Subject() = default;

protected:
    std::list<Observer *> observers;
};


#endif //QT_SLIDESHOW_SUBJECT_H
