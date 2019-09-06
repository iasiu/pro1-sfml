#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class HandleInput{

public:
    HandleInput();
    ~HandleInput();
    void update(const sf::RenderWindow &);
    float getPosX();
    float getPosY();
    bool getIsLeftPressed();
    bool getIsRightPressed();
    float getDx();
    float getDy();
    float getLastMouseX();
    float getLastMouseY();

private:
    float mouseX;
    float mouseY;
    float lastMouseX;
    float lastMouseY;
    bool isLeftMousePressed;
    bool isRightMousePressed;
    float dx;
    float dy;
};
