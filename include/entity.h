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
	sf::Texture* _bodyTexture{};


public:
	Entity();
	explicit Entity(sf::Texture* texture);
	~Entity();
    void setPosition (float x, float y);
    void setOrigin (float x, float y);
    void setScale (float x, float y);
	void draw(sf::RenderWindow& _window);
	sf::Sprite getSprite();
};
