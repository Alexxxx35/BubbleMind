//
// Created by rayane on 26/02/2021.
//

#include "CircleEntity.h"

CircleEntity::CircleEntity(int x, int y , int radius , sf::Color col, sf::Vector2i speed) : AbstractEntity() {
    circle.setRadius(radius);
    circle.setPosition(x,y);
    circle.setFillColor(col);
    this->speed=speed;
}

CircleEntity::CircleEntity(sf::CircleShape circle) {
    this->circle=circle;
}


CircleEntity::~CircleEntity() noexcept {}

void CircleEntity::Draw() {
    WindowManager::GetInstance().GetWindow()->draw(this->circle);
}
void CircleEntity::Update() {
    sf::Vector2u dimensions =WindowManager::GetInstance().GetWindow()->getSize();
    /* TEST DE COLLISION BORD DE LA WINDOW */
    if(circle.getPosition().x<=0 || circle.getPosition().x+2*circle.getRadius() >= dimensions.x){
        this->SetSpeed(sf::Vector2i(-GetSpeed().x,GetSpeed().y));
    }
    if(circle.getPosition().y<=0 || circle.getPosition().y+2*circle.getRadius() >= dimensions.y){
        this->SetSpeed(sf::Vector2i(GetSpeed().x,-GetSpeed().y));
    }
    this->circle.setPosition(this->circle.getPosition().x + this->speed.x,this->circle.getPosition().y + this->speed.y);
}


std::string CircleEntity::Serialize() {return "circle";}

sf::CircleShape CircleEntity::getCircle() {
    return this->circle;
}


int CircleEntity::GetX() {
    return getCircle().getPosition().x;
}

int CircleEntity::GetY() {
    return getCircle().getPosition().y;
}

void CircleEntity::SetX(int x) {
    getCircle().setPosition(x,GetY());
}
void CircleEntity::SetY(int y) {
    getCircle().setPosition(GetX(),y);
}

sf::Vector2i CircleEntity::GetSpeed() {
    return this->speed;
}

void CircleEntity::SetSpeed(sf::Vector2i speed) {
    this->speed = speed;
}
