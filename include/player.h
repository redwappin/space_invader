#pragma once
#include "entity.h"

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
	~Player();
	virtual void draw(sf::RenderWindow& _window);
	virtual void move(float x);
	virtual void shoot();
};
