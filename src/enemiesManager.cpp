//
// Created by Amryon on 01/12/2019.
//

#include <iostream>
#include <game.h>
#include "enemiesManager.h"

std::thread EnemiesManager::t_update;

/**
 * Get collision system
 * Pass it pointer to the vector that contains all enemies
 * Calculate the number of row needed for the number of enemy we want
 */
EnemiesManager::EnemiesManager() {
    _collisionSystem = &Game::collisionSystem;
    _enemiesArea = &Game::enemiesArea;

    _collisionSystem->SetEnemies(&_enemies);
}

/**
 * Spawn the required number of enemy
 */
void EnemiesManager::spawn() {
    for(int i=0; i<_enemyNbByRow; i++){
        if(_enemies.size()>= _expectedEnemyNb) return;

        sf::Vector2f startPos(_enemiesArea->min_width,_enemiesArea->min_height);
        if(i == 0 && _enemies.size()>=_enemyNbByRow){
            Enemy topLineEnemy = *(_enemies.end()-(_enemyNbByRow+i)-1);
            sf::FloatRect enemyBounds = topLineEnemy.getBounds();
            sf::Vector2f enemyPos = topLineEnemy.getPosition();
            startPos = sf::Vector2f(enemyPos.x, enemyPos.y + enemyBounds.height);
        }

        if(i>0){
            Enemy lastEnemy = *(_enemies.end()-1);
            sf::FloatRect enemyBounds = lastEnemy.getBounds();
            sf::Vector2f enemyPos = lastEnemy.getPosition();
            startPos = sf::Vector2f(enemyPos.x + enemyBounds.width, enemyPos.y);
        }


        _enemies.emplace_back(enemyTexture,startPos);
    }
}

/**
 * Start a thread that handle update of all enemy
 */
void EnemiesManager::update() {
    t_update = std::thread(&EnemiesManager::updateAll, this);
}

/**
 * Update all Enemies before check their collisions
 */
void EnemiesManager::updateAll() {
    std::vector<Enemy>::iterator enemy;
    for(enemy=_enemies.begin();  enemy!=_enemies.end(); ++enemy){
        (*enemy).move(-1,0);
    }
    //_collisionSystem->CheckEnemiesCol();
}

/**
 *
 */
void EnemiesManager::enemiesShoot() {

}



/**
 * Draw all Enemies after update done
 */
void EnemiesManager::draw(sf::RenderWindow &window) {
    if(t_update.joinable()) t_update.join();
    std::vector<Enemy>::iterator enemy;
    for(enemy=_enemies.begin();  enemy!=_enemies.end(); ++enemy){
        (*enemy).draw(window);
    }
}




