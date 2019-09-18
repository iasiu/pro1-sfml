#pragma once

#include <iostream>

#include "Map.hpp"
#include "HandleInput.hpp"
#include "Objects.hpp"
#include "Collectables.hpp"
#include "Camera.hpp"
#include "Constants.hpp"
#include "Buildings.h"

class Game {

public:
    Game();
    ~Game();
    void printToConsole(const sf::RenderWindow &);
    void printMap(sf::RenderWindow &);
    void update(sf::RenderWindow &);

    void setCursorTex(bool yes);

private:
    Map gameMap;
    HandleInput handleMouseInput;
    Camera camera;
    Collectables col;
    Buildings castles;

    sf::Texture cursorTex;
    sf::Sprite cursor;

};
