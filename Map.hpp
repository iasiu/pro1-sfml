#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.hpp"
#include "SimplexNoise.h"
#include <ctime>

class Map{

public:
    Map();
    ~Map();
    void load();
    void draw(sf::RenderWindow &,float,float);
    void checkMouseOver(float, float, float, float, sf::RenderWindow &);
    int ** get_mapSquares();

private:
    sf::Texture mapTiles;
    sf::Sprite squareSprites [101] [66];

    SimplexNoise noise;

    bool loaded;

    int cordX;
    int cordY;

    //sf::RectangleShape square [100] [65];
    int mapSquares [100] [65]; // 1 - grass1, 2 - grass2, 3 - grass3, 4 - grass4, 5 - grass5, 6 - grass6, 7 - sand1, 8 - sand2, 9 - water1, 10 - water2, 11 - stone1, 12 - stone2
    int ** copyArray = new int * [100];
};
