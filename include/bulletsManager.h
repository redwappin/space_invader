//
// Created by Amryon on 01/12/2019.
//

#ifndef INVADERS_BULLETSMANAGER_H
#define INVADERS_BULLETSMANAGER_H


#include "collisionSystem.h"

class BulletsManager {
private:
    std::map<std::string,std::vector<Movable*>> m_bullets;
    CollisionSystem* _collisionSystem;

    //Functions
    void updateWork();
    void moveBullets(std::string entityName, std::vector<Movable*>* bullets );

public:
    BulletsManager();
    static std::map<std::string,sf::Texture>textures;
    void Update();
    void EndUpdate();
    void Draw(sf::RenderWindow& window);
    void Spawn(std::string entityName, sf::Vector2f startPos);
    std::vector<Movable*>* getBulletsByEntity(std::string name);
    ~BulletsManager();
    void deleteEntity();
};


#endif //INVADERS_BULLETSMANAGER_H
