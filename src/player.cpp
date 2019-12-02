#include "player.h"
#include "bullet.h"
#include <iostream>
using namespace std;

Player::Player(sf::Texture* texture) : Movable(texture)
{
	this->loadEntity();
    setScale(0.2f, 0.2f);
	_speed = 5;

}

void Player::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
	setPosition(500 / 2.0f, 800);
}

void Player::shoot(Bullet &bullet) {
    bullet.setPosition(getPosition().x,getPosition().y);
}

Player::~Player()
{

}








