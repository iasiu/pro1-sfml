#pragma once
#include "Objects.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Buildings : Objects
{
public:
    Buildings();
    void setup(int**,int**);
    void draw(sf::RenderWindow &);


private:
    sf::Sprite castlePlayer;
    sf::Sprite castleEnemy;
    sf::Texture castleTexture;

    bool loaded;

    int tiles[MAP_SIZE_X][MAP_SIZE_Y]; //0 - jak jest pusto na mapie // 1 - jak nie

    sf::Vector2i posPlayer; //pozycje zamkow (w kratkach)
    sf::Vector2i posEnemy;
};
