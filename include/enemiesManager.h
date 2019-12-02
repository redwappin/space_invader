//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_ENEMIESMANAGER_H
#define INVADERS_ENEMIESMANAGER_H


#include "enemy.h"
#include "collisionSystem.h"

class EnemiesManager {
private:
    //Main var
    std::vector<Enemy> _enemies;
    CollisionSystem* _collisionSystem;
    Limits* _enemiesArea;

    //threads
    static std::thread t_update;
    static std::thread t_spawn;

    //Spawn infos
    int _enemyNb = 0;
    int _expectedEnemyNb = 20;
    int _enemyNbByRow =5 ;

    //Functions
    void updateAll();
    void enemiesShoot();

public:
    sf::Texture* enemyTexture;

    EnemiesManager();
    void update();
    void spawn();
    void draw(sf::RenderWindow& window);
    ~EnemiesManager(){};
};


#endif //INVADERS_ENEMIESMANAGER_H
