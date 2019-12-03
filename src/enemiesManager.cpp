#include <iostream>
#include <game.h>
#include "enemiesManager.h"

/**
 * Get collision system
 * Pass it pointer to the vector that contains all enemies
 * Calculate the number of row needed for the number of enemy we want
 */
EnemiesManager::EnemiesManager(LevelConfig::EnemiesConfig _config) {
    //get ref needed
    _collisionSystem = &Game::collisionSystem;
    _enemiesArea = &Game::enemiesArea;

    _enemyNb = _config._enemyNb;
    _enemyNbByRow = _config._enemyNbByRow ;
    shootNb = _config.shootNb;
    _timeBetweenShoot = _config._timeBetweenShoot;

    //Number of row
    _rowNb = _enemyNb/_enemyNbByRow;
    spawn();
}

/**
 * Set bullets for shoot or check collision with bullets
 */
void EnemiesManager::setBulletsManager(BulletsManager *bulletsMngr) {
    _bulletsMngr = bulletsMngr;
}

/**
 * Spawn the required number of enemy
 */
void EnemiesManager::spawn() {
    for(int r = 0; r < _rowNb; r++){
        for(int i=0; i<_enemyNbByRow; i++){
            if(_enemies.size()>= _enemyNb) return;

            //start pos is the min axis of x, y
            sf::Vector2f startPos(_enemiesArea->min_width,_enemiesArea->max_height/2);

            if(!_enemies.empty()){
                //get the last enemy created
                Movable* originEnemy = *(_enemies.end()-1);

                //Start of row : get the last enemy of the line
                if( i == 0){
                    originEnemy = *(_enemies.end()-(_enemyNbByRow+i));
                }
                sf::FloatRect enemyBounds = originEnemy->getBounds();
                sf::Vector2f enemyPos = originEnemy->getPosition();
                startPos = sf::Vector2f((i>0)?enemyPos.x+ enemyBounds.width : enemyPos.x, (i==0)?enemyPos.y - enemyBounds.height : enemyPos.y);
            }
            _enemies.push_back(new Enemy());
            _enemies.back()->setPosition(startPos.x,startPos.y);
        }
    }
}

/**
 * Start a thread that handle update of all enemy
 */
void EnemiesManager::Update() {

    for(Movable* enemy : _enemies){
        enemy->update();
    }

    //check collision between playerBullets and Enemy
    _collisionSystem->checkCollision(_enemies,*_bulletsMngr->getBulletsByEntity("Player"));

    //Check collision between Enemy Area and Enemy
    sf::Vector2i colInfos = _collisionSystem->checkOneCollideLimits(_enemies,*_enemiesArea);

    //Game Over
    if(colInfos.y != 0) {

        return;
    }

    //Change dir of enemy if collide to screen edge
    else if(colInfos.x != 0){
        for(Movable* enemy : _enemies){
            dynamic_cast<Enemy*>(enemy)->setChangeDir();
        }
    }


}

void EnemiesManager::EndUpdate() {

}


/**
 * Make A random Enemy shoot
 */
void EnemiesManager::Shoot() {
    _timeSinceLastShoot += _clock.restart();
    if(_timeSinceLastShoot.asSeconds() > _timeBetweenShoot ){
        for(int i =0 ; i<shootNb; i++){
            int randomIndex = rand() % _enemies.size();
            Movable* enemy = _enemies[randomIndex];
            _bulletsMngr->Spawn("Enemy",enemy->getPosition());
        }
        _timeSinceLastShoot = sf::Time::Zero;
        _clock.restart();
    }
}


/**
 * Draw all Enemies after update done
 */
void EnemiesManager::Draw(sf::RenderWindow &window) {
    for(Movable* enemy : _enemies){
        enemy->draw(window);
    }
}

/**
 * Get current nb of enemy
 * @return
 */
int EnemiesManager::getEnemiesNb() {
    return _enemies.size();
}

/**
 * Clear all enemies to avoid memory leak
 */
void EnemiesManager::deleteEntity() {
    for(Movable* enemy : _enemies){
        delete enemy;
    }
    _enemies.clear();
}

EnemiesManager::~EnemiesManager(){

}










