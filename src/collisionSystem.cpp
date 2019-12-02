//
// Created by Amryon on 01/12/2019.
//

#include "collisionSystem.h"

void CollisionSystem::checkCollision(std::vector<Movable> &v_objs, std::vector<Movable> &v_targets) {
    std::vector<Movable>::iterator obj;
    for(obj=v_objs.begin();  obj!=v_targets.end(); ++obj){
        checkCollision((*obj), v_targets);
    }
}

void CollisionSystem::checkCollision(Movable &obj, std::vector<Movable> &v_targets) {
    sf::FloatRect boundingBox = obj.getBounds();
    std::vector<Movable>::iterator target;

    for(target=v_targets.begin();  target!=v_targets.end(); ++target){
        if (boundingBox.intersects((*target).getBounds()))
        {
            v_targets.erase(target);
        }
    }
}

void CollisionSystem::checkCollision(Movable &obj, Limits &limits) {

}

void CollisionSystem::checkCollision(std::vector<Movable> &v_objs, Limits &limits) {

}

void CollisionSystem::CheckPlayerCol() {
    //if(t_playerMove.joinable()) t_playerMove.join();
    //t_playerMove = std::thread(&CollisionSystem::checkCollision(_player,_windowSize), this);
}

void CollisionSystem::SetEnemies(std::vector<Enemy> *enemies) {
    _enemies = enemies;
}

