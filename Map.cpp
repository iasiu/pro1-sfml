#include "Map.hpp"

Map::Map(){
    this->loaded = 0;

    if(this->mapTiles.loadFromFile("Resources/tilemap.png"))
    {
        loaded = 1;
    }

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

    if(loaded)
    {
        for(int i=0; i<100; i++)
            for(int j=0; j<65; j++)
            {

                float smoothness = 30;
                this->mapSquares[i][j] = 7 + (SimplexNoise::noise(i/smoothness, j/smoothness) * 6);

                this->squareSprites[i][j].setPosition(sf::Vector2f(i*GRID, j*GRID));
                this->squareSprites[i][j].setTexture(mapTiles);
                // this->square[i][j].setSize(sf::Vector2f(GRID, GRID));
                //this->square[i][j].setPosition(i*GRID, j*GRID);

                switch (mapSquares [i][j]) {
                    case 1 ... 8:
                    {
                        int randNum = 1 + std::rand()%8;

                        if(randNum == 1)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(0,0,40,40));
                        }
                        else if(randNum == 2)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(40,0,40,40));
                        }
                        else if(randNum == 3)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(0,40,40,40));
                        }
                        else if(randNum == 4)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(40,40,40,40));
                        }
                        else if(randNum == 5 || randNum == 6)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(0,80,40,40));
                        }
                        else if(randNum == 7 || randNum == 8)
                        {
                            this->squareSprites[i][j].setTextureRect(sf::IntRect(40,80,40,40));
                        }
                        break;
                    }

                    case 9 ... 10:
                        {
                            int randNum = 1 + std::rand()%2;

                            if(randNum == 1)
                            {
                                this->squareSprites[i][j].setTextureRect(sf::IntRect(0,120,40,40));
                            }
                            else if(randNum == 2)
                            {
                                this->squareSprites[i][j].setTextureRect(sf::IntRect(40,120,40,40));
                            }

                            break;
                        }


                    case 11 ... 12:
                        {
                            int randNum = 1 + std::rand()%2;

                            if(randNum == 1)
                            {
                                this->squareSprites[i][j].setTextureRect(sf::IntRect(0,160,40,40));
                            }
                            else if(randNum == 2)
                            {
                                this->squareSprites[i][j].setTextureRect(sf::IntRect(40,160,40,40));
                            }

                            break;
                        }



                    default:
                        break;
            }

        }
    }
}

void Map::draw(sf::RenderWindow & w){
    //w.draw(this->mapSprite);

    for(int i=0; i<100; i++)
        for(int j=0; j<65; j++)
        {
            //w.draw(this->square[i][j]);
            w.draw(this->squareSprites[i][j]);
        }
}

void Map::checkMouseOver(float mx, float my, float cx, float cy, sf::RenderWindow & w) {

    float x = mx + cx - WIN_WIDTH/2;
    float y = my + cy - WIN_HEIGHT/2;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    sf::FloatRect rect [100][100];

    sf::RectangleShape checkRect;
    checkRect.setFillColor(sf::Color::Black);
    checkRect.setOutlineColor(sf::Color::Black);
    checkRect.setOutlineThickness(2);

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<65; j++)
        {
            rect[i][j] = squareSprites[i][j].getLocalBounds();
            rect[i][j].left = i * GRID;
            rect[i][j].top = j * GRID;
            sf::Color col = sf::Color(0,0,0, 10);

            if(rect[i][j].contains(x, y))
            {
             //   fCol.a = 150;
            //    square[i][j].setFillColor(fCol);
                //squareSprites[i][j].setColor(col);
            }
            else
            {
             //   fCol.a = 255;
            //    square[i][j].setFillColor(fCol);
                //squareSprites[i][j].setColor(sf::Color(0,0,0,0));
            }
        }
    }
}
