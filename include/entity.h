#pragma once
#include "invaders.h"
/*
** Entity handling
*/
class Entity
{

protected:

	virtual void loadEntity() = 0 ;

	sf::Sprite _spriteBody;
	sf::Texture _bodyTexture;


public:
	Entity() {};
	~Entity() {};
	virtual void draw(sf::RenderWindow& _window) = 0;
	sf::Sprite getSprite();


};
