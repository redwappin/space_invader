#pragma once
#include "entity.h"
/*
** Player handling
*/
class Bullet : public Entity
{
protected:
	void loadEntity();
	float _speed;

public:
	Bullet();
	Bullet(sf::Texture* texture);
	~Bullet();
	virtual void draw(sf::RenderWindow& _window);
	virtual void setPosition(sf::Vector2f position);
	virtual void move(float x);

};
