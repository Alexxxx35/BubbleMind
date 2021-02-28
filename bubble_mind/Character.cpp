#include "Character.hh"
using json = nlohmann::json;

Character::Character() : AbstractEntity(){}
Character::~Character(){}


void Character::SetX(double NewX) {
    X=NewX;
    this->NotifyAll();
}

double Character::GetX() const{
    return X;
}

void Character::SetY(double NewY) {
    
    Y=NewY;
    this->NotifyAll();
}

double Character::GetY() const{
    return Y;
}

void Character::SetLife(int NewLife) {
    Life=NewLife;
    this->NotifyAll();
}

int Character::GetLife() const{
    return Life;
}

void Character::AddObserver(IObserver* observer){
    this->observers.push_back(observer);
}

void Character::RemoveObserver(IObserver* observer){
    this->observers.remove(observer);
}

void Character::NotifyAll(){
    for (IObserver* observer : observers){
        observer->Notify(this);
    } 
}

