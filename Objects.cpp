#include "Objects.hpp"

Objects::Objects(){
    this->posX = 0;
    this->posY = 0;
}

Objects::~Objects(){

}

float Objects::get_posX()
{
    return this->posX;
}

float Objects::get_posY()
{
    return this->posY;
}

void Objects::set_posX(float x)
{
    this->posX = x;
}

void Objects::set_posY(float y)
{
    this->posY = y;
}
