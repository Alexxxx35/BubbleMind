//
// Created by rayane on 27/02/2021.
//

#ifndef BUBBLE_MIND_WINDOWMANAGER_H
#define BUBBLE_MIND_WINDOWMANAGER_H

#include <SFML/Graphics.hpp>




class WindowManager{
public:
    ~WindowManager();
    WindowManager(WindowManager& other ) = delete;
    void operator=(const WindowManager&) = delete;
    static WindowManager& GetInstance();
    sf::RenderWindow* GetWindow();

protected:
    WindowManager();
    static WindowManager* windowManager_;
    sf::RenderWindow * window;
};
#endif //BUBBLE_MIND_WINDOWMANAGER_H
