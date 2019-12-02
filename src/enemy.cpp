#include "enemy.h"

Enemy::Enemy(sf::Texture *texture, sf::Vector2f startPos) : Movable(texture){
    this->loadEntity();
    setScale(0.2f,0.2f);
    setPosition(startPos.x,startPos.y);
    _speed = 5;
}

void Enemy::loadEntity() {
    _spriteBody.setTexture(*_bodyTexture);
}

Enemy::~Enemy() {
}




