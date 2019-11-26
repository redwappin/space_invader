#include "player.h"
#include "bullet.h"
#include <iostream>
using namespace std;


Player::Player()
{
}

Player::Player(sf::Texture* texture)
{
	_bodyTexture = texture;
	this->loadEntity();
	_speed = 1;
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow& _window)
{
	_spriteBody.setScale(0.1f, 0.1f);
	_window.draw(_spriteBody);
}

void Player::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
	_spriteBody.setPosition(1200/2.0f, 800);
	_spriteBody.setOrigin(0, 0);
}

void Player::move(int direction)
{
	_spriteBody.move(sf::Vector2f(direction * _speed, 0));
}

void Player::shoot(Bullet& bullet)
{
	bullet.setPosition(_spriteBody.getPosition());

}


void Player::setSpeed(float speed)
{
	_speed = speed;

}






