//
// Created by Amryon on 01/12/2019.
//

#include <iostream>
#include "collisionSystem.h"


/**
 * Check beetween two movables vector if they collide
 * @param v_objs : movables vector
 * @param v_targets : movables vector
 */
void CollisionSystem::checkCollision(std::vector<Movable*> &v_objs, std::vector<Movable*> &v_targets) {
    for(int i = 0; i < v_objs.size(); i++){
        bool result = checkCollision(v_objs[i], v_targets);
        if(result){
            delete v_objs[i];
            v_objs.erase(v_objs.begin()+i);
        }
    }

}

/**
 * Check if multiples of movable collide a movable
 * true : Destroy target movable
 * @param obj : movable
 * @param v_targets : movables vector
 * @return true : can destroy object
 *          false : object doesn't collide
 */
bool CollisionSystem::checkCollision(Movable* obj, std::vector<Movable*> &v_targets) {
    sf::FloatRect boundsO = obj->getBounds();

    for(int i = 0; i < v_targets.size(); i++){
        if (boundsO.contains(v_targets[i]->getPosition()))
        {
            delete v_targets[i];
            v_targets.erase(v_targets.begin()+i);
            return true;
        }
    }
    return false;
}

/**
 *Check if multiples movable move outside the limits
 * true : Destroy it
 * @param v_objs : movables vector
 * @param limits : where they can move
 * @param dir : movement direction
 */
void CollisionSystem::checkLimitsCollision(std::vector<Movable*> &v_objs, Limits &limits, sf::Vector2i dir) {

    for ( int i = 0; i < v_objs.size(); i++ )
    {
        bool result = checkLimitsCollision(v_objs[i], limits,dir);
        if(result){
            delete v_objs[i];
            v_objs.erase(v_objs.begin()+i);
        }
    }

}

/**
 * Check if an object move outside the limits
 * @param obj : movable
 * @param limits : where it can move
 * @param dir : movement direction
 * @return true : can destroy object
 *          false : object doesn't collide
 */
bool CollisionSystem::checkLimitsCollision(Movable *obj, Limits &limits, sf::Vector2i dir) {
    sf::Vector2f pos = obj->getPosition();
    bool  isCollide = false;
    if(dir.x>0){
        isCollide = pos.x > limits.max_width;
    }else if(dir.x<0){
        isCollide = pos.x < limits.min_width;
    }

    if(dir.y>0){
        isCollide = pos.y > limits.max_height;
    }else if(dir.y<0){

        isCollide = pos.y < limits.min_height;
    }
    return isCollide;
}

/**
 * Check if one of a vector of Movable collide with limits
 * true : return collision infos
 * @param v_objs : obj of movables
 * @param limits : limits where they can move
 * @return informations of a collision
 *          (0,0) if no collision occur
 */
sf::Vector2i CollisionSystem::checkOneCollideLimits(std::vector<Movable*> &v_objs, Limits &limits) {
    sf::Vector2i colInfos(0,0);
    for (Movable* movable : v_objs){
        sf::Vector2f offset (movable->getBounds().width/2, movable->getBounds().height/2);
        sf::Vector2f pos = movable->getPosition();
        if(pos.x + offset.x > limits.max_width) colInfos.x = 1;
        if(pos.x < limits.min_width) colInfos.x = -1;
        if(pos.y + offset.y > limits.max_height) colInfos.y = 1;
        if(pos.y < limits.min_height) colInfos.y = -1;

        if(colInfos.x != 0 || colInfos.y !=0) return colInfos;
    }

    return colInfos;
}



