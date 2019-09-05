#pragma once

#include <iostream>

#include "Map.hpp"
#include "HandleInput.hpp"
#include "Objects.hpp"
#include "Constants.hpp"

class Game {

public:
    Game();
    ~Game();
    void printToConsole(const sf::RenderWindow &);

private:
    Map gameMap;
    HandleInput handleMouseInput;

};
