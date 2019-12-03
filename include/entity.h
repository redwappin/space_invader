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
	void setTexture(sf::Texture* texture);
    void setPosition (float x, float y);
    void setOrigin (float x, float y);
    void setScale (float x, float y);
    sf::Vector2f getPosition();
    sf::FloatRect getBounds();
    sf::Vector2f getOrigin();

    void draw(sf::RenderWindow& _window);

    virtual ~Entity();
};
