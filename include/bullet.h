#pragma once
#include "movable.h"

/*
** Player handling
*/
class Bullet : public Movable
{
protected:
	void loadEntity() override;

public:
	Bullet();
	explicit Bullet(sf::Texture* texture);
	~Bullet();
};
