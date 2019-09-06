#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Camera {

public:
    Camera();
    ~Camera();
    sf::View update(float, float);
    float getPosX();
    float getPosY();

private:
    float posX;
    float posY;
    sf::View view;
};
