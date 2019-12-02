#include "entity.h"

Entity::Entity() {
}

Entity::Entity(sf::Texture* texture) {
    _bodyTexture = texture;
}

void Entity::draw(sf::RenderWindow &_window) {
    _window.draw(_spriteBody);
}


void Entity::setOrigin(float x, float y) {
    _spriteBody.setOrigin(x,y);
}

void Entity::setPosition(float x, float y) {
    _spriteBody.setPosition(x,y);
}

void Entity::setScale(float x, float y) {
    _spriteBody.setScale(x,y);
}

sf::Vector2f Entity::getPosition() {
    return _spriteBody.getPosition();
}

sf::FloatRect Entity::getBounds() {
    return _spriteBody.getGlobalBounds();
}

Entity::~Entity()
{
}










