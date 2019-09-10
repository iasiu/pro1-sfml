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
for(int i=0;i<100;i++)
        {
            for(int j=0;j<65;j++)
                tiles[i][j];
        }
}

void Collectables::setup(int ** mapSquares)
{
    for(int i=0;i<100;i++)
        {
            for(int j=0;j<65;j++)
            {
                if(mapSquares[i][j] == 1 || mapSquares[i][j] == 2 || mapSquares[i][j] == 3 || mapSquares[i][j] == 4 || mapSquares[i][j] == 5 || mapSquares[i][j] == 6 || mapSquares[i][j] == 7 || mapSquares[i][j] == 8)
                {
                    int x=rand()%100+1;
                    if(x==1)
                    this->tiles[i][j]=3;
                    else if(x==2)
                    this->tiles[i][j]=4;
                    else if(x==3)
                    this->tiles[i][j]=5;
                }
            }
        }
}

void Collectables::draw(sf::RenderWindow & w, int ** mapSquares)
{
    if(loaded)
    {
        for(int i=1; i<99; i++)
        {
            for(int j=1; j<64; j++)
            {
                if(mapSquares[i][j] == 1 || mapSquares[i][j] == 2 || mapSquares[i][j] == 3 || mapSquares[i][j] == 4 || mapSquares[i][j] == 5 || mapSquares[i][j] == 6 || mapSquares[i][j] == 7 || mapSquares[i][j] == 8)
                {
                        float smoothness = 10;

                        int temp = SimplexNoise::noise(i/smoothness + seed, j/smoothness + seed) * 12;
                        if(temp > 10)
                        {
                           tiles[i][j]=1; //drzewko rodzaj 1

                        }
                        else if(temp < -10)
                        {
                           tiles[i][j]=2; //drzewko rodzaj 2
                        }

                }
            }
        }


        for(int i=1;i<99;i++)
        {
            for(int j=1;j<64;j++)
            {
                switch(tiles[i][j])
                {
                case 0:
                    {
                        break;
                    }
                case 1:
                    {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(0, 0, 40, 80));
                            w.draw(tree);
                            break;
                    }
                case 2:
                    {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(40, 0, 40, 80));
                            w.draw(tree);
                            break;
                    }
                case 3:
                    {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(0, 80, 40, 40));
                            w.draw(tree);
                            break;
                    }
                case 4:
                    {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(40, 80, 40, 40));
                            w.draw(tree);
                            break;
                    }
                case 5:
                    {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(0, 120, 40, 40));
                            w.draw(tree);
                            break;
                    }

                }
            }
        }


    }
}
