#pragma once
#include "Objects.hpp"
#include "Constants.hpp"
#include "SimplexNoise.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

class Collectables : public Objects
{
public:
    Collectables();
    ~Collectables();
    void setup(int **); //inicjalizuje pozycjê drzew, kamieni i krzewow na mapie |
    void draw(sf::RenderWindow &);
    void printTiles();
private:
    int tiles[100][65];
    sf::Sprite sprite;
    sf::Texture collectablesTexture;
    bool loaded;
    int seed;

    // int type; // 1 - tree1, 2 - tree2, 3 - stone1, 4 - stone2, 5 - bush1, 6 - bush2, 7 - water

    enum type{
        blank=0,
        tree1=1,
        tree2,
        stone1,
        stone2,
        bush1,
        bush2,
        water
    }; //kiedyœ jeœli tablica tiles[][] nie bêdzie kopiowana/przekazywana poza klasê mo¿na u¿yæ tu enumClass ( dla czytelnoœci)
};
