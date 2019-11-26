#pragma once
#include "entity.h"
#include "bullet.h"
/*
** Player handling
*/
class Player : public Entity
{
protected:
	virtual void loadEntity();
	float _speed;



public:
	Player();
	Player(sf::Texture* texture);
	~Player();
	virtual void draw(sf::RenderWindow& _window);
	virtual void move(float x);
	void shoot(Bullet& bullet);
};
