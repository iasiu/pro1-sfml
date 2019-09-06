#include "HandleInput.hpp"

HandleInput::HandleInput(){
    this->mouseX = 0;
    this->mouseY = 0;
    this->isLeftMousePressed = 0;
    this->isRightMousePressed = 0;
    this->dx = 0;
    this->dy = 0;
}

HandleInput::~HandleInput(){

}

void HandleInput::update(const sf::RenderWindow & w) {
    this->lastMouseX = mouseX;
    this->lastMouseY = mouseY;
    this->mouseX = sf::Mouse::getPosition(w).x;
    this->mouseY = sf::Mouse::getPosition(w).y;
    this->isLeftMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    this->isRightMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);

    if(isRightMousePressed)
    {
            this->dx = -(this->mouseX - this->lastMouseX);
            this->dy = -(this->mouseY - this->lastMouseY);
            //std::cout<<"dx: "<<this->dx<<std::endl;
            //std::cout<<"dy: "<<this->dy<<std::endl;
    }
    else
    {
        this->dx = 0;
        this->dy = 0;
    }
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

float HandleInput::getDx(){
    return this->dx;
}

float HandleInput::getDy(){
    return this->dy;
}

float HandleInput::getLastMouseX()
{
    return this->lastMouseX;
}

float HandleInput::getLastMouseY()
{
    return this->lastMouseY;
}
