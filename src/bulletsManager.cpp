//
// Created by Amryon on 01/12/2019.
//

#include <game.h>
#include <iostream>
#include "bulletsManager.h"

std::map<std::string,sf::Texture> BulletsManager::textures;

BulletsManager::BulletsManager(){
    //get ref needed
    _collisionSystem = &Game::collisionSystem;
}

/**
 * Unlock update thread
 */
void BulletsManager::Update() {
    updateWork();
}

/**
 * Worker for update thread
 * Move bullets
 * Test collision between bullets after update
 */
void BulletsManager::updateWork(){
    for(auto& [key, value] : m_bullets){
        moveBullets(key, &value);
    }

}

/**
 * Wait for main update thread join
 */
void BulletsManager::EndUpdate(){
}

/**
 * Update all bullets of an entity
 * Check if bullets out of windows
 */
void BulletsManager::moveBullets(std::string entityName, std::vector<Movable*> *bullets ) {
    float y = (entityName == "Enemy")? 1 : -1;
    float x = 0;
    for(Movable* bullet : *bullets){
        bullet->move(x,y);
    }

    //Check if bullets is outside limits
    _collisionSystem->checkLimitsCollision(m_bullets[entityName], Game::windowsSize, sf::Vector2i(x, y));
}

/**
 * Draw bullets
 * @param window
 */
void BulletsManager::Draw(sf::RenderWindow &window) {
    for(auto& [key, value] : m_bullets){
        for(Movable* bullet : value){
            bullet->draw(window);
        }
    }
}

/**
 *  Spawn a bullet
 * @param entityName : Name of entity that spawn the bullets
 * @param startPos : Start pos of spawn bullet
 */
void BulletsManager::Spawn(std::string entityName, sf::Vector2f startPos) {
    m_bullets[entityName].push_back(new Bullet());
    m_bullets[entityName].back()->setTexture(&textures[entityName]);
    m_bullets[entityName].back()->setPosition(startPos.x,startPos.y);


}

std::vector<Movable *> *BulletsManager::getBulletsByEntity(std::string name) {
    return &m_bullets[name];
}

/**
 * Clear all bullets to avoid memory leak
 */
void BulletsManager::deleteEntity() {
    for(auto& [key, value] : m_bullets){
        for(Movable* bullet : value){
            delete bullet;
        }
        value.clear();
    }
    m_bullets.clear();
}


BulletsManager::~BulletsManager() {

}






