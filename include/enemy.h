#pragma once
#include "invaders.h"
#include "movable.h"

/*
** Enemy handling
*/
class Enemy : public Movable
{
protected:
	void loadEntity() override;
	int dir_x = 1;
	int dir_y = 0;
    bool changeDir = false;

public:
    static sf::Texture texture;
    void update() override ;
    void collideOther() override;
    void setChangeDir();
	Enemy();
	~Enemy();
};
