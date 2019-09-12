#include "Map.hpp"

Map::Map(){
    this->loaded = 0;

    if(this->mapTiles.loadFromFile("Resources/tilemap.png"))
    {
        loaded = 1;
    }

}

Map::~Map(){
    for(int i=0; i<100; i++)
    {
        delete [] copyArray[i];
    }
    delete [] copyArray;
}

void Map::load(){

    if(loaded)
    {
        srand(time(NULL));
        unsigned long long int seed = 1 + rand()% 1000;

        for(int i=0; i<100; i++)
            for(int j=0; j<65; j++)
            {
                float smoothness = 30;
                this->mapSquares[i][j] = 7 + (SimplexNoise::noise(i/smoothness +seed , j/smoothness + seed) * 6);
            }
    }
}

void Map::draw(sf::RenderWindow & w, float cx, float cy){
    for(int i=(int)cx/GRID-16; i<(int)cx/GRID+17; i++)
    {
        for(int j=(int)cy/GRID-9; j<(int)cy/GRID+10; j++)
        {
            this->mapDrawer.setPosition(sf::Vector2f(i*GRID, j*GRID));
            this->mapDrawer.setTexture(mapTiles);

            //mechanizm podswietlania tile'a posz kursorem
            mapDrawer.setColor(sf::Color(255,255,255));
            if(i==cordX && j==cordY)
                mapDrawer.setColor(sf::Color(200,200,200,200));

            switch (mapSquares [i][j])
             {

                        case 1:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,0,40,40)); break;
                        }
                        case 2:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,0,40,40)); break;
                        }
                        case 3:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,40,40,40)); break;
                        }
                        case 4:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,40,40,40)); break;
                        }
                        case 5:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,80,40,40)); break;
                        }
                        case 6:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,80,40,40)); break;
                        }
                        case 7:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,80,40,40));  break;
                        }
                        case 8:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,80,40,40));  break;
                        }
                        case 9:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,120,40,40)); break;
                        }
                        case 10:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,120,40,40)); break;
                        }
                        case 11:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(0,160,40,40));  break;
                        }
                        case 12:
                        {
                            this->mapDrawer.setTextureRect(sf::IntRect(40,160,40,40));  break;
                        }
             }
            w.draw(this->mapDrawer);
        }
    }
}

void Map::checkMouseOver(float mx, float my, float cx, float cy, sf::Sprite& cursor) {

    float x = mx + cx - WIN_WIDTH/2;
    float y = my + cy - WIN_HEIGHT/2;

    std::cout <<"x: "<< x;  //pozycja myszy wzglêdem ca³ej mapy (globalna pozycja myszy)
    std::cout <<" y: "<< y << std::endl;

     this->cordX=(int)(x)/GRID;                 //koordynaty x i y tile'a na którym jest mysz
     this->cordY=(int)(y)/GRID;

    std::cout <<"Tile coordinates: "<<cordX<<" "<<cordY<<" \n";
    std::cout <<"Tile number: "<< cordX + 100 * cordY <<"\n";       //numer tile'a


    cursor.setPosition(x,y); //ustawienie pozycji kursora na pozycję tego niewidocznego
}

int ** Map::get_mapSquares()
{
    for(int i=0; i<100; i++)
    {
        copyArray[i] = new int[65];
            for(int j=0; j<65; j++)
                copyArray[i][j] = this->mapSquares[i][j];
    }

    return copyArray;
}
