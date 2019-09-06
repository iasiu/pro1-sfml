#include "Game.hpp"

Game::Game(){
    std::cout<<"Game started"<<std::endl;
    this->gameMap.load();
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
    gameMap.draw(w);
}

void Game::update(sf::RenderWindow & w) {
    handleMouseInput.update(w);
    w.setView(camera.update(handleMouseInput.getDx(),handleMouseInput.getDy()));
}
