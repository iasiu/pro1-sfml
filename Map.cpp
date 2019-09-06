#include "Map.hpp"

Map::Map(){
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            this->mapSquares[i][j] = 0;
        }
}

Map::~Map(){

}

void Map::load(){
    if(this->mapTexture.loadFromFile("Resources/thesettllers100x100.png"))
    {
        this->mapSprite.setTexture(mapTexture);
        this->mapSprite.setTextureRect(sf::IntRect(0,0, 4000, 4000));
        this->mapSprite.setPosition(0, 0);
    }
}

void Map::draw(sf::RenderWindow & w){
    w.draw(this->mapSprite);
}
