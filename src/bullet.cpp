#include <iostream>
#include "bullet.h"

Bullet::Bullet()
{
    _speed = 8;
}

void Bullet::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
    setOrigin(getBounds().width/2,getBounds().height/2);
    setScale(0.2f, 0.2f);
}

void Bullet::update() {

}

void Bullet::collideLimits() {
    delete this;
}

void Bullet::collideOther() {
    delete this;
}

Bullet::~Bullet()
{
}






