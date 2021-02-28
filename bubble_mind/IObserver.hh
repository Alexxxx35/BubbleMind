#ifndef IOBSERVER
#define IOBSERVER

class IObservable;

class IObserver{

    public:
        virtual void Notify(IObservable*)=0;
        virtual ~IObserver(){};


};

#endif