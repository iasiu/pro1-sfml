#pragma once
#include <SFML/Graphics.hpp>

class HandleInput{

public:
    HandleInput();
    ~HandleInput();
    void update(const sf::RenderWindow &);
    float getPosX();
    float getPosY();
    bool getIsLeftPressed();
    bool getIsRightPressed();

private:
    float mouseX;
    float mouseY;
    bool isLeftMousePressed;
    bool isRightMousePressed;
};
