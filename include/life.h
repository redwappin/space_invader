#pragma once
#include "entity.h"

/*
** Life handling
*/
class Life : public Entity
{
protected:
    void loadEntity() override;

public:
    Life();
    explicit Life(sf::Texture* texture);
    ~Life();
};
