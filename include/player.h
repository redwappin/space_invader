#pragma once
#include "entity.h"
#include "bullet.h"
#include "movable.h"
#include "bulletsManager.h"
#include "life.h"

/*
** Player handling
*/
class Player : public Movable
{
protected:
	void loadEntity() override;
	//Refs
	CollisionSystem* _collisionSystem;
    BulletsManager* _bulletsMngr;

    sf::Vector2f _lastPos;

    std::vector<Life> _livesSprite;
    int _lives;


public:
    static sf::Texture texture;
    bool canShoot = false;
    sf::Vector2i playerMove;
    bool isDead = false;

	Player();
	void setBulletsManager(BulletsManager* bulletsMngr);
	void Shoot();
	void update() override ;
    void Draw(sf::RenderWindow &window);
	void collideLimits() override;
	void collideOther() override;
    void setLives(int lives);
	~Player();



};
