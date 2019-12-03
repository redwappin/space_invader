#pragma once
#include "entity.h"
#include "bullet.h"
#include "movable.h"
#include "life.h"
/*
** Player handling
*/
class Player : public Movable
{
protected:
	void loadEntity() override;
	int _lives;
public:
	Player(){};
	explicit Player(sf::Texture* texture);
	void shoot(Bullet& bullet);
	~Player();
	int getLives();
	void setLife(int lives);

	void looseLife();
};
