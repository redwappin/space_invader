//
// Created by mimil on 03/12/2019.
//

#include "levelConfig.h"

LevelConfig::LevelConfig(){
    auto level1 = LevelModel{ 1, 5 ,4};
    auto level2 = LevelModel{ 2,5,4};
    auto level3 = LevelModel{ 3,5,4};
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
