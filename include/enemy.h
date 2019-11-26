#pragma once
#include "invaders.h"
#include "movable.h"

/*
** Enemy handling
*/
class Enemy : public Movable
{
protected:
	virtual void loadEntity();

public:
	Enemy(){};
	explicit Enemy(sf::Texture* texture);
	~Enemy();
};
