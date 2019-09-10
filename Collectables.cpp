#include "Collectables.hpp"

Collectables::Collectables()
{
    if(this->collectablesTexture.loadFromFile("Resources/collectablesSprite.png"))
        this->loaded = 1;

        srand(time(NULL));
        this->seed = std::rand()%200;

        for(int i=0;i<100;i++)
        {
            for(int j=0;j<65;j++)
            {
                tiles[i][j]=0;
            }

        }

}

Collectables::~Collectables()
{

}

void Collectables::setup(int ** mapSquares)
{
    for(int i=0;i<99;i++)
        {
            for(int j=0;j<64;j++)
            {
                if(mapSquares[i][j]>=1 && mapSquares[i][j]<=6)
                {
                        float smoothness = 10;
                        int temp = SimplexNoise::noise(i/smoothness + seed, j/smoothness + seed) * 12;
                        if(temp > 10)
                        {
                           tiles[i][j]=tree1;

                        }
                        else if(temp < -10)
                        {
                           tiles[i][j]=tree2;
                        }
                        else
                        {
                           int x=rand()%100+1; //to 100 wskazuje jak czêsto siê pojawiaj¹ collectablesy (so we can make it to constants.hpp)

                            if(x==1)
                            this->tiles[i][j]=stone1;
                            else if(x==2)
                            this->tiles[i][j]=stone2;
                            else if(x==3 || x==4)
                            this->tiles[i][j]=bush1;
                        }
                }
            }
        }
}

void Collectables::draw(sf::RenderWindow & w)
{
    if(loaded)
    {
        for(int i=1;i<99;i++) //zostawiam taki zakres bo i tak od 0 i do 100 nie ma co rysowaæ (bo setup ma takie same zakresy)
        {
            for(int j=1;j<64;j++)
            {
                this->sprite.setTexture(collectablesTexture); //jeœli przek³adamy wydajnoœæ ponad czytelnoœæ to, to siê powinno znaleŸæ w ka¿dym case'ie (oprócz blank) zamiast tutaj
                this->sprite.setPosition(i*GRID,j*GRID-GRID);
                switch(tiles[i][j])
                {
                case blank:
                    {
                            break;
                    }
                case tree1:
                    {
                            sprite.setTextureRect(sf::IntRect(0, 0, 40, 80));  w.draw(sprite);
                            break;
                    }
                case tree2:
                    {
                            sprite.setTextureRect(sf::IntRect(40, 0, 40, 80));  w.draw(sprite);
                            break;
                    }
                case stone1:
                    {
                            sprite.setTextureRect(sf::IntRect(0, 80, 40, 40));  w.draw(sprite);
                            break;
                    }
                case stone2:
                    {
                            sprite.setTextureRect(sf::IntRect(40, 80, 40, 40));  w.draw(sprite);
                            break;
                    }
                case bush1:
                    {
                            sprite.setTextureRect(sf::IntRect(0, 120, 40, 40));  w.draw(sprite);
                            break;
                    }
                }
            }
        }
    }
}
