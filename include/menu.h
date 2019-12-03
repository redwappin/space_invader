#pragma once
#include "invaders.h"

#ifndef INVADERS_MENU_H
#define INVADERS_MENU_H

/*
** Menu handling
*/
class Menu
{
private:
    sf::Font* _font;

    std::vector<sf::Text> _boxes;
    void load();


public:
    Menu();
    explicit Menu(sf::Font* font);
    ~Menu();
    std::vector<sf::Text> getBoxes();
    void display(sf::RenderWindow& _window);
};

#endif //INVADERS_MENU_H