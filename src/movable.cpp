//
// Created by Amryon on 26/11/2019.
//

#include "movable.h"

void Movable::move(float x, float y) {
    _spriteBody.move(x * _speed, y);
}

void Movable::shoot(Bullet &bullet) {
    bullet.setPosition(_spriteBody.getPosition());
}

Movable::~Movable() {

}