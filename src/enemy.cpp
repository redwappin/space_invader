#include "enemy.h"

Enemy::Enemy(sf::Texture *texture) : Movable(texture){
    this->loadEntity();
    _speed = 5;
}

void Enemy::loadEntity() {
    _spriteBody.setTexture(*_bodyTexture);
    _spriteBody.setOrigin(0, 0);
    _spriteBody.setPosition(500 / 2.0f, 900 / 2.0f);
}

Enemy::~Enemy() {

}


