#include "Camera.hpp"

Camera::Camera(){
    this->posX = 500;
    this->posY = 500;
}

Camera::~Camera(){

}

sf::View Camera::update(float dx, float dy) {
    this->posX += dx;
    this->posY += dy;
    this->view.setCenter(this->posX, this->posY);

    if(this->posX <= 500)
        this->posX = 500;
    else if(this->posX >= 3500)
        this->posX = 3500;

    if(this->posY <= 500)
        this->posY = 500;
    else if(this->posY >= 3500)
        this->posY = 3500;

    return this->view;
}

float Camera::getPosX(){
    return this->posX;
}

float Camera::getPosY(){
    return this->posY;
}
