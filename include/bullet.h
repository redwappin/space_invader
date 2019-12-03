#pragma once
#include "movable.h"

/*
** Player handling
*/
class Bullet : public Movable
{
protected:
    void loadEntity() override;

public:
	Bullet();
    void update() override;
    void collideLimits() override;
    void collideOther() override;
	~Bullet();


};
