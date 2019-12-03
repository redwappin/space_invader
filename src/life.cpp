//
// Created by Amryon on 03/12/2019.
//

#include "life.h"

sf::Texture Life::texture;

Life::Life()
{
    setTexture(&texture);
}


void Life::loadEntity()
{
    _spriteBody.setTexture(*_bodyTexture);
    setScale(0.2f, 0.2f);
    sf::FloatRect box = _spriteBody.getLocalBounds();
    _spriteBody.setOrigin(box.left, box.top);
}

Life::~Life()
{
}
