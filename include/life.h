//
// Created by Amryon on 03/12/2019.
//

#ifndef INVADERS_LIFE_H
#define INVADERS_LIFE_H


#include "entity.h"

/**
* Life entity
*/
class Life : public Entity
{
protected:
    void loadEntity() override;

public:
    static sf::Texture texture;
    Life();
    ~Life();
};


#endif //INVADERS_LIFE_H
