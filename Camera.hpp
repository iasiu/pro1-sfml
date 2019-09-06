#pragma once
#include <SFML/Graphics.hpp>

class Camera {

public:
    Camera();
    ~Camera();
    sf::View update();

private:
    float posX;
    float posY;
    sf::View view;
};
