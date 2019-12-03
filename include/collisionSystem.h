//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_COLLISIONSYSTEM_H
#define INVADERS_COLLISIONSYSTEM_H


#include <thread>
#include "movable.h"

class CollisionSystem {
private:
    std::vector<Movable*>::iterator movable;

public:
    CollisionSystem(){};
    void checkCollision(std::vector<Movable*>& v_objs, std::vector<Movable*>& v_targets);
    bool checkCollision(Movable* obj, std::vector<Movable*>& v_targets);
    void checkLimitsCollision(std::vector<Movable*>& v_objs, Limits &limits, sf::Vector2i dir);
    bool checkLimitsCollision(Movable* obj, Limits &limits, sf::Vector2i dir);
    sf::Vector2i checkOneCollideLimits(std::vector<Movable*>& v_objs, Limits &limits);
    ~CollisionSystem(){};

};


#endif //INVADERS_COLLISIONSYSTEM_H
