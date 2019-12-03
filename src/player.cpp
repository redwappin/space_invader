#include "player.h"
#include "bullet.h"
#include <iostream>
#include <game.h>

using namespace std;

sf::Texture Player::texture;

/**
 * Constructor
 * get collision system
 */
Player::Player()
{
    _collisionSystem = &Game::collisionSystem;
    setTexture(&texture);
	_speed = 5;

}

/**
 * Set bullets for shoot or check collision with bullets
 */
void Player::setBulletsManager(BulletsManager *bulletsMngr) {
    _bulletsMngr = bulletsMngr;
}

/**
 * Set texture to player's sprite
 * set its start position
 * Set its scale
 */
void Player::loadEntity()
{
	_spriteBody.setTexture(*_bodyTexture);
    setScale(0.2f, 0.2f);
    setOrigin(getBounds().width/2,getBounds().height/2);
}

/**
 * Update player
 * Move it
 */
void Player::update() {
    if(isDead) return;
    _lastPos = getPosition();
    move(playerMove.x,playerMove.y);

    //Check collision with limits
    bool colResult = _collisionSystem->checkLimitsCollision(this,Game::windowsSize,playerMove);
    if(colResult) collideLimits();

    //Check collision with enemies bullets
    colResult = _collisionSystem->checkCollision(this,*_bulletsMngr->getBulletsByEntity("Enemy"));
    if(colResult) collideOther();
}

/**
 * Shoot a bullet
 */
void Player::Shoot() {
    _bulletsMngr->Spawn("Player",getPosition());
    canShoot = false;

}

void Player::Draw(sf::RenderWindow &window){
    draw(window);
    for (Life life: _livesSprite) {
        life.draw(window);
    }
}

/**
 * Collide window limits
 * Reset it to the last pos
 */
void Player::collideLimits() {
    setPosition(_lastPos.x,_lastPos.y);
}

/**
 * Collide other object
 * lose life
 * No life : die
 */
void Player::collideOther() {
    this->_lives-= 1;
    _livesSprite.erase(_livesSprite.end());
    if(_lives == 0) isDead = true;
}

/**
 * Set number of player lives
 * Instantiate a Life for each lives
 * Set pos of each lives
 * @param lives
 */
void Player::setLives(int lives) {
    _lives = lives;
    for(int i = 0; i< lives; i++){
        _livesSprite.emplace_back();

        sf::Vector2f pos(Game::uiArea.max_width-100 , Game::uiArea.min_height);
        if(i>0){
            pos.x =_livesSprite[i-1].getPosition().x - _livesSprite[i-1].getBounds().width;
        }
        _livesSprite.back().setPosition(pos.x,pos.y);
        std::cout << pos.x;
    }
}

Player::~Player()
{

}














