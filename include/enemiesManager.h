//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_ENEMIESMANAGER_H
#define INVADERS_ENEMIESMANAGER_H


#include "enemy.h"
#include "collisionSystem.h"
#include "levelConfig.h"

class EnemiesManager {
private:


//Struct to get EnemiesConfig
    //Main var
    std::vector<Movable*> _enemies;
    CollisionSystem* _collisionSystem;
    Limits* _enemiesArea;
    BulletsManager* _bulletsMngr;

    //Internal Timer
    sf::Clock _clock;
    sf::Time _timeSinceLastShoot = sf::Time::Zero;
    float _timeBetweenShoot = 10;

    //iterator
    std::vector<Movable*>::iterator enemy;

    //Spawn infos
    int _rowNb = 0;
    int _enemyNb = 20;
    int _enemyNbByRow =5 ;

    //Difficulty Infos
    int shootNb = 1;

    //Functions
    void spawn();

public:
    EnemiesManager(){};
    explicit EnemiesManager(LevelConfig::EnemiesConfig _config);
    void setBulletsManager(BulletsManager *bulletsMngr);
    void Update();
    void EndUpdate();
    void Shoot();
    void Draw(sf::RenderWindow& window);
    ~EnemiesManager();

    void deleteEntity();
    int getEnemiesNb();
};


#endif //INVADERS_ENEMIESMANAGER_H
