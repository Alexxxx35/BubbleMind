//
// Created by rayane on 27/02/2021.
//

#ifndef BUBBLE_MIND_ENTITYFACTORY_H
#define BUBBLE_MIND_ENTITYFACTORY_H

#include "AbstractEntity.hh"
#include "CircleEntity.h"
#include "string"
#include <SFML/Graphics.hpp>
class EntityFactory{
public:
    EntityFactory();
    ~EntityFactory();

    static AbstractEntity* CreateCircle(float x,float y,float radius ,sf::Color color, sf::Vector2i speed);


};

#endif //BUBBLE_MIND_ENTITYFACTORY_H
