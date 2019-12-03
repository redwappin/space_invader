//
// Created by Amryon on 03/12/2019.
//

#ifndef INVADERS_LEVELCONFIG_H
#define INVADERS_LEVELCONFIG_H


#include <vector>
class LevelConfig {

public:

    struct EnemiesConfig {
        int _enemyNb = 0;
        int _enemyNbByRow =0 ;
        int shootNb = 0;
        float _timeBetweenShoot = 0;
    };

    struct LevelModel {
        int number =0;
        EnemiesConfig enemiesconf;
    };
    std::vector<LevelModel> levels;
    LevelConfig();
    LevelModel findByLevelNumber(int level);
};


#endif //INVADERS_LEVELCONFIG_H
