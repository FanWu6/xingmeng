//
//  Playerinfo.h
//  hello
//
//  Created by 吴凡 on 14-3-24.
//
//

#ifndef __hello__Playerinfo__
#define __hello__Playerinfo__

#define myData CCUserDefault::sharedUserDefault()

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

//卡牌info
typedef struct
{
    bool isOwned;//是否拥有
    bool flag;//是否摆放
    int hero_index;//英雄编号
    int hero_level;//英雄等级
    int hero_exp;//英雄经验
    int star_level;//英雄星级
    int stone_rate;//当前升介比例
    float  putPos_x;
    float  putPos_y;
    float appearenceTime;
}Play_hero;

class Playerinfo{
public:
    //basic info
    Playerinfo();
    ~Playerinfo();
    
//    bool isOwned[13];//是否拥有
    int player_lvl;//玩家等级
    int player_gold;//玩家金钱

    vector<Play_hero> player_vec;
    
    void save_BData();
    void save_HData(int index);//传入需要保存的英雄编号
    void read_BData();
    void read_HData();
    //保存关卡
    void save_planet(int planet_index);
    void read_planet(int planet_index);
    int passedlevel_star[40];//通关的星级
    int maxlevel_flag[4];//每个星球可玩的关
};
#endif /* defined(__hello__Playerinfo__) */
