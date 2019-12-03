#include <iostream>
#include "enemy.h"
sf::Texture Enemy::texture;

Enemy::Enemy(){
    setTexture(&texture);
    _speed = 5;
}

/**
 * Set texture to enemy's sprite
 * Set its scale
 */
void Enemy::loadEntity() {
    _spriteBody.setTexture(*_bodyTexture);
    setOrigin(getBounds().width/2,getBounds().height/2);
    setScale(0.2f,0.2f);
}

/**
 * Update enemy
 * Check if direction is changed
 * Move it
 */
void Enemy::update() {
    if (changeDir && dir_y == 0) {
        dir_y = 1;
        //swap dir
        dir_x *= -1;

        move(0, dir_y);
    } else{
        if(dir_y == 1){
            changeDir = false;
            dir_y = 0;
        }
        move(dir_x, 0);
    }
}

/**
 * Change direction
 */
void Enemy::setChangeDir() {
    changeDir =  true;
}

/**
 * Collide other object
 * Destroy it
 */
void Enemy::collideOther() {
    delete this;
}

Enemy::~Enemy() {
}





