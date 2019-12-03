#pragma once
#include "invaders.h"
#include "entity.h"

#ifndef INVADERS_Movable_H
#define INVADERS_Movable_H


class Movable : public Entity {
protected:
    float _speed;
    void loadEntity() override;


public:
    Movable(){};
    ~Movable();
    void move (float x, float y);
    void setSpeed(float speed);
    virtual void update(){};
    virtual void collideLimits(){};
    virtual void collideOther(){};
};


#endif //INVADERS_Movable_H
