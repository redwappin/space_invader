#pragma once
#include "entity.h"
#include "bullet.h"
#include "movable.h"
/*
** Player handling
*/
class Player : public Movable
{
protected:
	virtual void loadEntity();
	float _speed;



public:
	Player(){};
	explicit Player(sf::Texture* texture);
	~Player();
};
