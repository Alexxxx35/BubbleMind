#ifndef IOBSERVABLE
#define IOBSERVABLE
#include "IObserver.hh"

class IObservable{

    public :
        virtual void AddObserver(IObserver*)=0;
        virtual void RemoveObserver(IObserver*)=0;
        virtual ~IObservable(){};

};

#endif