#include "Buildings.h"

Buildings::Buildings()
{
    tiles[MAP_SIZE_X][MAP_SIZE_Y]={0};


     if(this->castleTexture.loadFromFile("Resources/castleSprite.png"))
        this->loaded = 1;


    this->castlePlayer.setTexture(castleTexture);
    this->castleEnemy.setTexture(castleTexture);
    this->castlePlayer.setTextureRect(sf::IntRect(0, 0, 4*GRID, 4*GRID));
    this->castleEnemy.setTextureRect(sf::IntRect(4*GRID, 0, 4*GRID, 4*GRID));
}

void Buildings::setup(int** mapTiles,int** colTiles)
{

    for(int i=0;i<MAP_SIZE_X;i++)
    {
        for(int j=0;j<MAP_SIZE_Y;j++)
        {
            if(colTiles[i][j]==0 && mapTiles[i][j]>=1 && mapTiles[i][j]<=8)
            {
                tiles[i][j]=0; //tam gdzie jest trawa i nie ma drzew, kamieni ani krzaakow
            }
            else
            {
                tiles[i][j]=1;  //tam gdzie nie mozna narysowac zamku

                if(colTiles[i][j]==1 || colTiles[i][j]==2)
                    tiles[i][j-1]=1; //o kratke wyzej nad drzewanu tez przypal
            }


        }
    }

    //MECHANIZM SZUKANIA PUSTEGO MIEJSCA DLA ZAMKOW
    bool first{false};
    bool second{false};
    for(int y=0;y<MAP_SIZE_Y-4;y++)
    {
        for(int x=0;x<MAP_SIZE_X-4;x++)
        {
            int i=MAP_SIZE_X-4-x; //dla enemy zamku szukamy od drugiej strony miejsca
            int j=MAP_SIZE_Y-4-y;

            //ten if <=> jesli jeszcze nie znaleziono miejsca to zobacz czy 16 kratkowy kwadrat gdzie aktualny tiles[x][y] to lewy gorny rog jest caly pusty
            if(first!=true && tiles[x][y]==0 && tiles[x+1][y]==0 && tiles[x][y+1]==0 && tiles[x+1][y+1]==0 && tiles[x+2][y]==0 && tiles[x+2][y+1]==0 && tiles[x+2][y+2]==0 && tiles[x+1][y+2]==0
               && tiles[x][y+2]==0 && tiles[x][y+3]==0 && tiles[x+1][y+3]==0 && tiles[x+2][y+3]==0 && tiles[x+3][y]==0 && tiles[x+3][y+1]==0 && tiles[x+3][y+2]==0 && tiles[x+3][y+3]==0)
               {
                    posPlayer=sf::Vector2i(x,y); //jesli tak to zapisz pozycje
                    first=true;                 //i zglos ze znaleziono miejsce
               }
            //ten if <=> to samo ale od dupy strony (zmienne i oraz j mozna wymienic na odpowiednio MAP_SIZE_X-4-x i MAP_SIZE_Y-4-y)
            if(second!=true && tiles[i][j]==0 && tiles[i-1][j]==0 && tiles[i][j-1]==0 && tiles[i-1][j-1]==0 && tiles[i-2][j]==0 && tiles[i-2][j-1]==0 && tiles[i-2][j-2]==0 && tiles[i-1][j-2]==0
               && tiles[i][j-2]==0 && tiles[i][j-3]==0 && tiles[i-1][j-3]==0 && tiles[i-2][j-3]==0 && tiles[i-3][j]==0 && tiles[i-3][j-1]==0 && tiles[i-3][j-2]==0 && tiles[i-3][j-3]==0)
                {
                    posEnemy=sf::Vector2i(i,j);
                    second=true;
                } //te wielkie ify mozna zrobic w petli ale nie chce misie
        }
        if(first&&second) //jak znaleziono miejsce dla obu zamkow to po chuj szukac
            break;
    }

    castlePlayer.setPosition(posPlayer.x*GRID,posPlayer.y*GRID);
    castleEnemy.setPosition(posEnemy.x*GRID-3*GRID,posEnemy.y*GRID-3*GRID); //tak trzeba zrobic bo w posEnemy jest prawy dolny rog
}

void Buildings::draw(sf::RenderWindow & w)
{
    w.draw(this->castlePlayer);
    w.draw(this->castleEnemy);
}
