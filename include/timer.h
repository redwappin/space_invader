#pragma once
#include "invaders.h"
/*
** Timer handling
*/
class Timer
{
protected:
    sf::Font* _font;
    sf::Text _time_text;

    void loadTimer();

public:
    Timer();
    explicit Timer(sf::Font* font);
    ~Timer();
    void display(sf::RenderWindow& _window, sf::Time& time);
};
