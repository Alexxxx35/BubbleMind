#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "EntityFactory.h"
#include "Scene.hh"
#include "TimeManager.hh"
#include <iostream>
#include <stdlib.h>

int main() {

    WindowManager &windowManager = WindowManager::GetInstance();
    Scene scene;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text("Frame Rate :", font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(24);
    TimeManager::GetInstance().Start();
    int frameCount = 0;
    sf::Vector2i positionClick;
    sf::Vector2i positionRelease;
    while (windowManager.GetWindow()->isOpen()) {
        windowManager.GetWindow()->clear();
        frameCount++;
        TimeManager::GetInstance().Update();
        unsigned int time = TimeManager::GetInstance().GetStartedTime();
        sf::Event event;
        while (windowManager.GetWindow()->pollEvent(event)) {

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                windowManager.GetWindow()->close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {

                positionClick = sf::Mouse::getPosition(*windowManager.GetWindow());
                std::cout << positionClick.x << " " << positionClick.y << std::endl;

            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
                positionRelease = sf::Mouse::getPosition(*windowManager.GetWindow());
                //std::cout << localPosition.x << " " << localPosition.y << std::endl;
                int def_x = (positionRelease.x - positionClick.x) * (positionRelease.x - positionClick.x);
                int def_y = (positionRelease.y - positionClick.y) * (positionRelease.y - positionClick.y);
                int radius = sqrt(def_x + def_y);
                //std::cout << positionRelease.x << " " << positionRelease.y << " " << 1.0 / radius << std::endl;
                int speedness = (100/(radius+0.001))*(TimeManager::GetInstance().GetElapsedTime());
                int direction_x = rand()%100>50?1:-1;
                int direction_y = rand()%100>50?1:-1;
                std::cout << direction_x << " " << direction_y << std::endl;

                AbstractEntity *circle = EntityFactory::CreateCircle(positionClick.x - radius, positionClick.y - radius,
                                                                     radius,
                                                                     sf::Color(rand() % 255, rand() % 255,
                                                                               rand() % 255),
                                                                     sf::Vector2i(rand() % speedness*direction_x,
                                                                                  rand() % speedness *direction_y));
                scene.AddEntity(circle);

            }
            if (event.mouseButton.button == sf::Mouse::Left) {
                positionClick = sf::Mouse::getPosition(*windowManager.GetWindow());
                std::list<AbstractEntity *> list = scene.GetEntities();
                for (AbstractEntity *entity: list) {
                    CircleEntity *circle = (CircleEntity *) entity;
                    sf::Vector2f position = circle->getCircle().getPosition();
                    int radius = circle->getCircle().getRadius();
                    // test is point inside circle : (x - center_x)^2 + (y - center_y)^2 < radius^2
                    int x_part = (positionClick.x - (position.x + radius)) * (positionClick.x - (position.x + radius));
                    int y_part = (positionClick.y - (position.y + radius)) * (positionClick.y - (position.y + radius));
                    if (x_part + y_part < radius * radius) {
                        scene.RemoveEntity(entity);
                        break;
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                std::list<AbstractEntity *> list = scene.GetEntities();
                for (AbstractEntity *entity: list) {
                    scene.RemoveEntity(entity);
                }
            }
        }


        if (time > 1000) {
            text.setString("Frame Rate :" + std::to_string(frameCount));
            frameCount = 0;
            TimeManager::GetInstance().Start();


        }

        scene.Update();
        windowManager.GetWindow()->draw(text);
        windowManager.GetWindow()->display();

    }
    return 0;
}
