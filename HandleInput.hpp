#pragma once
#include <SFML/Graphics.hpp>

class HandleInput{

public:
    HandleInput();
    ~HandleInput();
    void updatePos(const sf::RenderWindow &);
    void updateButtonPressed();
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
