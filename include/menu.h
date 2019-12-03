//
// Created by mimil on 03/12/2019.
//

#ifndef INVADERS_MENU_H
#define INVADERS_MENU_H

#pragma once

#include "invaders.h"
#include "player.h"
#include "bullet.h"
#include "collisionSystem.h"
#include "enemiesManager.h"
#include "life.h"
#include "timer.h"
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