#include "Collectables.hpp"

Collectables::Collectables()
{
    if(this->collectablesTexture.loadFromFile("Resources/collectablesSprite.png"))
        this->loaded = 1;

        srand(time(NULL));
        this->seed = std::rand()%200;

}

Collectables::~Collectables()
{

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
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(0, 0, 40, 80));
                            w.draw(tree);
                        }
                        else if(temp < -10)
                        {
                            this->tree.setTexture(collectablesTexture);
                            this->tree.setPosition(i*GRID,j*GRID-GRID);
                            tree.setTextureRect(sf::IntRect(40, 0, 40, 80));
                            w.draw(tree);
                        }

                }
            }
        }
        for(int i=0; i<500; i++)
        {

        }
    }
}
