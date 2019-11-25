#pragma once
/*
** Drawable interface
*/
class IDrawable
{
public:
	virtual void draw(sf::RenderWindow& _window) = 0;
};
