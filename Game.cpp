#include "Game.hpp"

Game::Game(){
    std::cout<<"Game started"<<std::endl;
}

Game::~Game(){
    std::cout<<"Game ended"<<std::endl;
}

void Game::printToConsole(const sf::RenderWindow & w) {
    handleMouseInput.updatePos(w);
    handleMouseInput.updateButtonPressed();
    std::cout<<"x: "<<handleMouseInput.getPosX()<<std::endl;
    std::cout<<"y: "<<handleMouseInput.getPosY()<<std::endl;
    std::cout<<"L: "<<handleMouseInput.getIsLeftPressed()<<std::endl;
    std::cout<<"R: "<<handleMouseInput.getIsRightPressed()<<std::endl;
}
