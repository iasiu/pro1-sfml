#pragma once
#include <SFML/Graphics.hpp>

class HandleInput{

public:
    HandleInput();
    ~HandleInput();
    void updatePos(const sf::RenderWindow &);
    float getPosX();
    float getPosY();

private:
    float mouseX;
    float mouseY;
    bool isLeftMousePressed;
    bool isRightMousePressed;
};
