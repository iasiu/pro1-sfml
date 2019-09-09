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
        srand(time(NULL));
        unsigned long long int seed = 1 + rand()% 200;

        for(int i=0; i<100; i++)
            for(int j=0; j<65; j++)
            {

                float smoothness = 50;
                this->mapSquares[i][j] = 7 + (SimplexNoise::noise(i/smoothness +seed , j/smoothness + seed) * 6);

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
    {
        for(int j=0; j<65; j++)
        {
            //w.draw(this->square[i][j]);
            w.draw(this->squareSprites[i][j]);
        }
    }

}

void Map::checkMouseOver(float mx, float my, float cx, float cy, sf::RenderWindow & w) {

    float x = mx + cx - WIN_WIDTH/2;
    float y = my + cy - WIN_HEIGHT/2;

    std::cout <<  std::endl <<"x: "<< x;  //pozycja myszy wzglêdem ca³ej mapy (globalna pozycja myszy)
    std::cout <<" y: "<< y << std::endl;

     this->cordX=(int)(x)/GRID;                 //koordynaty x i y tile'a na którym jest mysz
     this->cordY=(int)(y)/GRID;

    std::cout <<"Tile coordinates: "<<cordX<<" "<<cordY<<" \n";
    std::cout <<"Tile number: "<< cordX + 100 * cordY <<"\n";       //numer tile'a


//mechanizm podœwietlania aktualnie najechanego muszk¹ tile'a
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<65; j++)
        {
           squareSprites[i][j].setColor(sf::Color(255,255,255));
        }
    }
    if((cordX>-1 && cordX<100) && (cordY>-1 && cordY<65))
      squareSprites[cordX][cordY].setColor(sf::Color(200,200,200,200));

    //TODO: return sf::vector2i(cordX,cordY)
}
