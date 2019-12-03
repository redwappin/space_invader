#include <iostream>
#include "life.h"


Life::Life(sf::Texture* texture) : Entity(texture)
{
    this->loadEntity();
    setScale(0.2f, 0.2f);
}

Life::~Life()
{
}

void Life::loadEntity()
{
    _spriteBody.setTexture(*_bodyTexture);
    sf::FloatRect box = _spriteBody.getLocalBounds();
    _spriteBody.setOrigin(box.left, box.top);


}




