#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.hpp"
#include "SimplexNoise.h"

class Map{

public:
    Map();
    ~Map();
    void load();
    void draw(sf::RenderWindow &);

private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    
    sf::RectangleShape square [100] [100];
    int mapSquares [100] [100]; // 1 - trawa1, 2 - trawa2, 3 - trawa3, 4 - trawa4, 5 - trawa5, 6 - trawa6, 7 - piasek1, 8 - piasek2, 9 - woda1, 10 - woda2, 11 - kamien1, 12 - kamien2
};
