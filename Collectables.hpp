#pragma once
#include "Objects.hpp"
#include "Constants.hpp"
#include "SimplexNoise.h"
#include <SFML/Graphics.hpp>
#include <ctime>

class Collectables : public Objects
{
public:
    Collectables();
    ~Collectables();
    void setup(int **);
    void draw(sf::RenderWindow &, int **);
private:
    int type; // 1 - tree1, 2 - tree2, 3 - stone1, 4 - stone2, 5 - bush1, 6 - bush2, 7 - water
    int tiles[100][65];
    sf::Sprite tree;
    sf::Texture collectablesTexture;
    bool loaded;
    int seed;
};
