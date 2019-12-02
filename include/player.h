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
	void loadEntity() override;

public:
	Player(){};
	explicit Player(sf::Texture* texture);
	void shoot(Bullet& bullet);
	~Player();
};
