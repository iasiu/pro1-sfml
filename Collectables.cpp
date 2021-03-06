#include "Collectables.hpp"

Collectables::Collectables()
{
    if(this->collectablesTexture.loadFromFile("Resources/collectablesSprite.png"))
        this->loaded = 1;

        srand(time(NULL));
        this->seed = std::rand()%200;

        for(int i=0;i<MAP_SIZE_X;i++)
        {
            for(int j=0;j<MAP_SIZE_Y;j++)
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
    for(int i=0;i<MAP_SIZE_X;i++)
        {
            for(int j=1;j<MAP_SIZE_Y;j++)
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
                        else if(temp<=10 && temp>=-10)
                        {
                           int x=rand()%100+1; //to 100 wskazuje jak cz�sto si� pojawiaj� collectablesy (so we can make it to constants.hpp)

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
        for(int i=0;i<MAP_SIZE_X;i++) //zostawiam taki zakres bo i tak od 0 i do 100 nie ma co rysowa� (bo setup ma takie same zakresy)
        {
            for(int j=1;j<MAP_SIZE_Y;j++)
            {
                //je�li przek�adamy wydajno�� ponad czytelno�� to, to si� powinno znale�� w ka�dym case'ie (opr�cz blank) zamiast tutaj
                switch(tiles[i][j])
                {
                case blank:
                    {
                            break;
                    }
                case tree1:
                    {
                            this->sprite.setPosition(i*GRID,j*GRID-GRID);
                             this->sprite.setTexture(collectablesTexture);
                            sprite.setTextureRect(sf::IntRect(0, 0, 40, 80));  w.draw(sprite);
                            break;
                    }
                case tree2:
                    {
                            this->sprite.setPosition(i*GRID,j*GRID-GRID);
                             this->sprite.setTexture(collectablesTexture);
                            sprite.setTextureRect(sf::IntRect(40, 0, 40, 80));  w.draw(sprite);
                            break;
                    }
                case stone1:
                    {
                            this->sprite.setPosition(i*GRID,j*GRID);
                             this->sprite.setTexture(collectablesTexture);
                            sprite.setTextureRect(sf::IntRect(0, 80, 40, 40));  w.draw(sprite);
                            break;
                    }
                case stone2:
                    {
                            this->sprite.setPosition(i*GRID,j*GRID);
                             this->sprite.setTexture(collectablesTexture);
                            sprite.setTextureRect(sf::IntRect(40, 80, 40, 40));  w.draw(sprite);
                            break;
                    }
                case bush1:
                    {
                            this->sprite.setPosition(i*GRID,j*GRID);
                             this->sprite.setTexture(collectablesTexture);
                            sprite.setTextureRect(sf::IntRect(0, 120, 40, 40));  w.draw(sprite);
                            break;
                    }
                }
            }
        }
    }
}

void Collectables::printTiles(){
    for(int i = 0; i<MAP_SIZE_X; i++)
    {
        for(int j = 0; j<MAP_SIZE_Y; j++)
        {
            std::cout<<"Tile: "<<i<<" "<<j<<" "<<this->tiles[i][j]<<std::endl;
        }
    }
}

int** Collectables::get_tiles()
{
    for(int i=0; i<MAP_SIZE_X; i++)
    {
        copyArray[i] = new int[MAP_SIZE_Y];
            for(int j=0; j<MAP_SIZE_Y; j++)
                copyArray[i][j] = this->tiles[i][j];
    }

    return copyArray;
}
