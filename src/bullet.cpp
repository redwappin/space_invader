#include <iostream>
#include "bullet.h"


Bullet::Bullet(sf::Texture* texture) : Movable(texture)
{
	this->loadEntity();
    setScale(0.2f, 0.2f);
	_speed = 8;
}

Bullet::~Bullet()
{
}

void Bullet::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
}




