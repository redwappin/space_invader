//#include "bullet.h"
//
//
//Bullet::Bullet()
//{
//	this->loadEntity();
//	_speed = 1;
//}
//
//Bullet::~Bullet()
//{
//}
//
//
//void Bullet::draw(sf::RenderWindow& _window)
//{
//	_spriteBody.setScale(0.2f, 0.2f);
//	_window.draw(_spriteBody);
//}
//
//
//void Bullet::loadEntity()
//{
//	_bodyTexture.loadFromFile("assets/gost.png");
//	_spriteBody.setTexture(_bodyTexture);
//	_spriteBody.setOrigin(0, 0);
//	_spriteBody.setPosition(0,0);
//}
//
//void Bullet::move(float x)
//{
//	_spriteBody.move(0, x * _speed);
//}
//
//
//
