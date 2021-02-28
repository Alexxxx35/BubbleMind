//
// Created by rayane on 27/02/2021.
//
#include "EntityFactory.h"


EntityFactory::EntityFactory() {}

EntityFactory::~EntityFactory() {}

AbstractEntity * EntityFactory::CreateCircle(float x, float y, float radius, sf::Color col, sf::Vector2i speed) {
    return new CircleEntity(x,y,radius,col ,speed);
}
