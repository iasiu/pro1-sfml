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

private:
    Map gameMap;
    HandleInput handleInput;

};
