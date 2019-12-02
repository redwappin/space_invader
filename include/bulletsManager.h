//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_BULLETSMANAGER_H
#define INVADERS_BULLETSMANAGER_H


#include "collisionSystem.h"

class BulletsManager {
private:
    CollisionSystem* _collisionSystem;
    std::vector<Bullet> _playerBullets;
    std::vector<Bullet> _enemiesBullets;

    //threads
    static std::thread t_update;
    static std::thread t_spawn;

    //Functions
    void updatePlayerBullets();
    void enemiesEnemiesBullets();

public:
    BulletsManager(){};
    void Update();
    void draw(sf::RenderWindow& window);
    ~BulletsManager();

};


#endif //INVADERS_BULLETSMANAGER_H
