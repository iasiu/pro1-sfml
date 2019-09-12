#include "Game.hpp"

Game::Game(){
   std::cout<<"Game started"<<std::endl;
    this->gameMap.load();
    col.setup(gameMap.get_mapSquares());

    if(this->cursorTex.loadFromFile("Resources/cursorSprite.png"))
    {
        this->cursor.setTexture(cursorTex);
        this->cursor.setTextureRect(sf::IntRect(0,0,40,40));
    }

    //this->col.printTiles();

}

Game::~Game(){
    std::cout<<"Game ended"<<std::endl;
}

void Game::printToConsole(const sf::RenderWindow & w) {
    std::cout<<"x: "<<handleMouseInput.getPosX()<<std::endl;
    std::cout<<"y: "<<handleMouseInput.getPosY()<<std::endl;
    std::cout<<"L: "<<handleMouseInput.getIsLeftPressed()<<std::endl;
    std::cout<<"R: "<<handleMouseInput.getIsRightPressed()<<std::endl;
}

void Game::printMap(sf::RenderWindow & w) {
    gameMap.draw(w,camera.getPosX(),camera.getPosY());
    col.draw(w);
    w.draw(this->cursor);
}

void Game::update(sf::RenderWindow & w) {
    handleMouseInput.update(w);
    setCursorTex(handleMouseInput.getIsRightPressed());
    w.setView(camera.update(handleMouseInput.getDx(),handleMouseInput.getDy()));
    gameMap.checkMouseOver(handleMouseInput.getPosX(), handleMouseInput.getPosY(), camera.getPosX(), camera.getPosY(),this->cursor);
}

void Game::setCursorTex(bool yes)
{
    sf::IntRect result = !yes ? sf::IntRect(0,0,40,40) : sf::IntRect(40,0,40,40);
    this->cursor.setTextureRect(result);
}

