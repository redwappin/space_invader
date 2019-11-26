#pragma once
#include "invaders.h"
#include "entity.h"
#include "bullet.h"

#ifndef INVADERS_Movable_H
#define INVADERS_Movable_H


class Movable : public Entity {
protected:
    float _speed;
    virtual void loadEntity() = 0 ;


public:
    Movable(){};
    explicit Movable(sf::Texture* texture) : Entity (texture){};
    ~Movable();
    void move (float x, float y);
    void shoot(Bullet& bullet);
};


#endif //INVADERS_Movable_H
