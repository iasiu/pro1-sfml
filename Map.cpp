#include "Map.hpp"

Map::Map(){

}

Map::~Map(){

}

void Map::draw(sf::RenderWindow & w){
    sf::Texture mapTexture;
    if(mapTexture.loadFromFile("Resources/thesettllers100x100.png"))
    {
        sf::Sprite mapSprite;
        mapSprite.setTexture(mapTexture);
        mapSprite.setTextureRect(sf::IntRect(0,0, 4000, 4000));
        mapSprite.setPosition(0, 0);
        w.draw(mapSprite);
    }

}
