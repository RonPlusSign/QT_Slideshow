//
// Created by andre on 28/06/21.
//

#ifndef QT_SLIDESHOW_OBSERVER_H
#define QT_SLIDESHOW_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};


#endif //QT_SLIDESHOW_OBSERVER_H
