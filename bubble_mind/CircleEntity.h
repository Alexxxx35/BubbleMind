//
// Created by rayane on 26/02/2021.
//
#include "AbstractEntity.hh"
#include "WindowManager.h"
#include <SFML/Graphics.hpp>
#include "TimeManager.hh"


#ifndef BUBBLE_MIND_CIRCLEENTITY_H
#define BUBBLE_MIND_CIRCLEENTITY_H
class CircleEntity : public AbstractEntity {
public:
    CircleEntity(int x, int y,int radius , sf::Color,sf::Vector2i speed);
    CircleEntity(sf::CircleShape circle);
    ~CircleEntity();
    void Draw() override;
    void Update() override;
    std::string Serialize() override;
    sf::CircleShape getCircle();

    void SetX(int x);
    void SetY(int y);
    int GetX(void);
    int GetY(void);
    sf::Vector2i GetSpeed();
    void SetSpeed(sf::Vector2i);

private:
    sf::CircleShape circle;
    sf::Vector2i speed;
};
#endif //BUBBLE_MIND_CIRCLEENTITY_H
