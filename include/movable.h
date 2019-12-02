#pragma once
#include "invaders.h"
#include "entity.h"

#ifndef INVADERS_Movable_H
#define INVADERS_Movable_H


class Movable : public Entity {
protected:
    float _speed;


public:
    Movable(){};
    explicit Movable(sf::Texture* texture);
    ~Movable();
    void move (float x, float y);
    void setSpeed(float speed);
};


#endif //INVADERS_Movable_H
