#include "bullet.h"


Bullet::Bullet(sf::Texture* texture)
{
	_bodyTexture = texture;
	this->loadEntity();
	_speed = 1;
}

Bullet::~Bullet()
{
}


void Bullet::draw(sf::RenderWindow& _window)
{
	_spriteBody.setScale(0.1f, 0.1f);
	_window.draw(_spriteBody);
}


void Bullet::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
	_spriteBody.setOrigin(0, 0);
}

void Bullet::move(float x)
{
	_spriteBody.move(0, x * _speed);
}

void Bullet::setPosition(sf::Vector2f position) {
	_spriteBody.setPosition(position);
}




