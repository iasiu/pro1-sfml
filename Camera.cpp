#include "Camera.hpp"

Camera::Camera(){

}

Camera::~Camera(){

}

sf::View Camera::update() {
    this->view.move(0.5, 0.5);
    /*
    this->view.setCenter(this->posX, this->posY);
    */
    return this->view;
}
