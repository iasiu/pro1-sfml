#include "Map.hpp"

Map::Map(){
    
}

Map::~Map(){

}

void Map::load(){
    /*if(this->mapTexture.loadFromFile("Resources/thesettllers100x100a.png"))
    {
        this->mapSprite.setTexture(mapTexture);
        this->mapSprite.setTextureRect(sf::IntRect(0,0, 4000, 4000));
        this->mapSprite.setPosition(0, 0);
    }*/
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            this->mapSquares[i][j] = 1 + (std::rand() % 60);
            
            this->square[i][j].setSize(sf::Vector2f(40, 40));
            this->square[i][j].setPosition(i*40, j*40);
            
            switch (mapSquares [i][j]) {
                case 1 ... 8:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 9 ... 16:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 17 ... 24:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 25 ... 32:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 33 ... 40:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 41 ... 48:
                    this->square[i][j].setFillColor(sf::Color::Green);
                    break;
                    
                case 49 ... 52:
                    this->square[i][j].setFillColor(sf::Color::Yellow);
                    break;
                    
                case 53 ... 56:
                    this->square[i][j].setFillColor(sf::Color::Yellow);
                    break;
                    
                case 57:
                    this->square[i][j].setFillColor(sf::Color::Blue);
                    break;
                    
                case 58:
                    this->square[i][j].setFillColor(sf::Color::Blue);
                    break;
                    
                case 59:
                    this->square[i][j].setFillColor(sf::Color::Cyan);
                    break;
                    
                case 60:
                    this->square[i][j].setFillColor(sf::Color::Cyan);
                    break;
                    
                default:
                    break;
            }
            
        }
}

void Map::draw(sf::RenderWindow & w){
    //w.draw(this->mapSprite);
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            w.draw(this->square[i][j]);
}
