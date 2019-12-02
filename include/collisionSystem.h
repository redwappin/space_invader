//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_COLLISIONSYSTEM_H
#define INVADERS_COLLISIONSYSTEM_H


#include <thread>
#include "movable.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"

class CollisionSystem {
private:
    static std::thread t_playerMove;
    static std::thread t_player_bullet;
    static std::thread t_enemy_bullet;
    static std::thread t_bulletsMove;
    static std::thread t_enemiesMove;

    Player* _player;
    std::vector<Enemy>* _enemies;
    std::vector<Bullet>* _playerBullets;
    std::vector<Bullet>* _enemyBullets;

    Limits _windowSize;
    Limits _enemyArea;

    void checkCollision(std::vector<Movable>& v_objs, std::vector<Movable>& v_targets);
    void checkCollision(Movable& obj, std::vector<Movable> &v_targets);
    void checkCollision(std::vector<Movable>& v_objs, Limits& limits);
    void checkCollision(Movable& obj, Limits& limits);

public:
    CollisionSystem(){};
    void CheckPlayerCol();
    void CheckEnemiesCol();
    void CheckBulletsCol();
    void CheckEnemiesBulletsCol();
    void CheckPlayerBulletsCol();

    void SetEnemies(std::vector<Enemy>* enemies);
    void SetPlayer(Player* player);
    void SetPlayerBullets(std::vector<Bullet>* bullets);
    void SetEnemyBullets(std::vector<Bullet>* bullets);
    void SetLimits(Limits& window, Limits& enemyArea);
};


#endif //INVADERS_COLLISIONSYSTEM_H
