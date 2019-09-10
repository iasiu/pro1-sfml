#pragma once

class Objects{

public:
    Objects();
    ~Objects();
    float get_posX();
    float get_posY();
    void set_posX(float);
    void set_posY(float);

private:
    float posX;
    float posY;
};
