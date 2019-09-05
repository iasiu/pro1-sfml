#include "HandleInput.hpp"

HandleInput::HandleInput(){
    this->mouseX = 0;
    this->mouseY = 0;
    this->isLeftMousePressed = 0;
    this->isRightMousePressed = 0;
}

HandleInput::~HandleInput(){

}

void HandleInput::updatePos(const sf::RenderWindow & w) {
    this->mouseX = sf::Mouse::getPosition(w).x;
    this->mouseY = sf::Mouse::getPosition(w).y;
}

void HandleInput::updateButtonPressed() {
    this->isLeftMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    this->isRightMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

float HandleInput::getPosX() {
    return this-> mouseX;
}

float HandleInput::getPosY() {
    return this-> mouseY;
}

bool HandleInput::getIsLeftPressed() {
    return this->isLeftMousePressed;
}

bool HandleInput::getIsRightPressed() {
    return this->isRightMousePressed;
}
