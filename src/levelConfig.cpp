//
// Created by Amryon on 03/12/2019.
//

/**
 * All tconfig for each level
 * To set levels values and increase difficulty
 */
#include "levelConfig.h"
LevelConfig::LevelConfig(){
    auto level1 = LevelModel{ 1, 10 ,5,1,5};
    auto level2 = LevelModel{ 2,20,5,2,4};
    auto level3 = LevelModel{ 3,30,5,3,3};
    levels.emplace_back(level1);
    levels.emplace_back(level2);
    levels.emplace_back(level3);
}
LevelConfig::LevelModel LevelConfig::findByLevelNumber(int level) {
    for(int i = 0 ; i < levels.size(); i++)
    {
        if(levels[i].number == level)
            return levels[i];
    }
    return LevelModel() ;
}
