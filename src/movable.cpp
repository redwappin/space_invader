#include <iostream>
#include "movable.h"
#include "bullet.h"



void Movable::move(float x, float y) {
    _spriteBody.move(x * _speed, y*_speed);
}

void Movable::setSpeed(float speed)
{
    _speed = speed;

}
Movable::~Movable() {

}

void Movable::loadEntity() {

}

