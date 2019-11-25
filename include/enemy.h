#pragma once
#include "invaders.h"
#include "entity.h"

/*
** Enemy handling
*/
class Enemy : public Entity
{
protected:
	virtual void loadEntity();
	float _speed;

public:
	Enemy();
	~Enemy();
	virtual void draw(sf::RenderWindow& _window);
	virtual void move(float x);
};
