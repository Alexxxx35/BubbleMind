//
// Created by rayane on 27/02/2021.
//

#include "WindowManager.h"

WindowManager* WindowManager::windowManager_= nullptr;

WindowManager::WindowManager() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Hello SFML");
    this->window->setFramerateLimit(60);

}

WindowManager::~WindowManager() {}

WindowManager& WindowManager::GetInstance(){
    if(windowManager_==nullptr){
        windowManager_=new WindowManager();
    }
    return *windowManager_;
}

sf::RenderWindow* WindowManager::GetWindow() {
    return this->window;
}