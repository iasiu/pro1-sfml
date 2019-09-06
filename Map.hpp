#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Map{

public:
    Map();
    ~Map();
    void load();
    void draw(sf::RenderWindow &);

private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
};
