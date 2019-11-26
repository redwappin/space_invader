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
	_spriteBody.setScale(0.05f, 0.05f);
	_window.draw(_spriteBody);
}

void Player::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
	_spriteBody.setOrigin(0, 0);
	_spriteBody.setPosition(500 / 2.0f, 900 / 2.0f);
}

void Player::move(float x)
{
	_spriteBody.move(x * _speed, 0);
}

void Player::shoot(Bullet& bullet)
{
	bullet.setPosition(_spriteBody.getPosition());

}






