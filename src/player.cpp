#include "player.h"
#include "bullet.h"
#include <iostream>
using namespace std;

Player::Player(sf::Texture* texture) : Movable(texture)
{
	this->loadEntity();
    setScale(0.2f, 0.2f);
	_speed = 5;
	_lives = 3;
}

void Player::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
}

void Player::shoot(Bullet &bullet) {
    bullet.setPosition(getPosition().x,getPosition().y);
}

Player::~Player()
{

}

void Player::looseLife() {
    this->_lives-= 1;
}

int Player::getLives() {
    return _lives;
}

void Player::setLife(int lives) {
 _lives = lives;
}








