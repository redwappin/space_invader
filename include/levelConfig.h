//
// Created by mimil on 03/12/2019.
//

#ifndef INVADERS_LEVELCONFIG_H
#define INVADERS_LEVELCONFIG_H


#include <vector>
class LevelConfig {

private:
    struct LevelModel {
        int number;
        int enemy_per_row;
        int number_enemy_columns;
    };
    std::vector<LevelModel> levels;
public:
    LevelConfig();
    LevelModel findByLevelNumber(int level);
};



#endif //INVADERS_LEVELCONFIG_H
