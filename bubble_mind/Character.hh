#ifndef DEF_CHARACTER
#define DEF_CHARACTER
#include "AbstractEntity.hh"
#include "IObservable.hh"
#include "IObserver.hh"
#include "list"
#include "json.hpp"

class Character : public AbstractEntity,IObservable
{
    public:
        virtual ~Character();
        virtual double GetX() const;
        virtual void SetX(double);
        virtual double GetY() const;
        virtual void SetY(double);
        virtual int GetLife() const;
        virtual void SetLife(int);
        virtual void AddObserver(IObserver*) override;
        virtual void RemoveObserver(IObserver*) override;
        void NotifyAll();
        virtual std::string Serialize() =0;
        

    private:
        std::list<IObserver*> observers;
        double X;
        double Y;
        int Life;

    protected:
        Character();

};

#endif

