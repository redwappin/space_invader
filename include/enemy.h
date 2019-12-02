#pragma once
#include "invaders.h"
#include "movable.h"

/*
** Enemy handling
*/
class Enemy : public Movable
{
protected:
	void loadEntity() override;
	void update();

public:
	Enemy(){};
	explicit Enemy(sf::Texture* texture, sf::Vector2f startPos);
	~Enemy();
};
