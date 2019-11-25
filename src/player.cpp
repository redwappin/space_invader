#include "player.h"


Player::Player()
{
	this->loadEntity();
	_speed = 1;
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow &_window)
{
	_spriteBody.setScale(0.2f, 0.2f);
	_window.draw(_spriteBody);
}

void Player::loadEntity()
{
	_bodyTexture.loadFromFile("assets/gost.png");
	_spriteBody.setTexture(_bodyTexture);
	_spriteBody.setOrigin(0, 0);
	_spriteBody.setPosition(500 / 2.0f, 900 / 2.0f );
}

void Player::move(float x)
{
	_spriteBody.move(x*_speed, 0);
}


void Player::shoot() 
{
	
}



