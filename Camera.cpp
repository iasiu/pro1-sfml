#include "Camera.hpp"

Camera::Camera(){
    this->posX = WIN_WIDTH/2;
    this->posY = WIN_HEIGHT/2;
}

Camera::~Camera(){

}

sf::View Camera::update(float dx, float dy) {
    this->posX += dx;
    this->posY += dy;
    this->view.setCenter(this->posX, this->posY);
    this->view.setSize(WIN_WIDTH, WIN_HEIGHT);

    if(this->posX <= WIN_WIDTH/2)
        this->posX = WIN_WIDTH/2;
    else if(this->posX >= MAP_SIZE_X * GRID - WIN_WIDTH/2)
        this->posX = MAP_SIZE_X * GRID - WIN_WIDTH/2;

    if(this->posY <= WIN_HEIGHT/2)
        this->posY = WIN_HEIGHT/2;
    else if(this->posY >= MAP_SIZE_Y * GRID - WIN_HEIGHT/2)
        this->posY = MAP_SIZE_Y * GRID - WIN_HEIGHT/2;

    return this->view;
}

float Camera::getPosX(){
    return this->posX;
}

float Camera::getPosY(){
    return this->posY;
}
