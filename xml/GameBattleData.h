//
//  GameBattleData.h
//  GameDemo_box2d
//
//  Created by 王伟 on 13-12-31.
//
//

#ifndef __GameDemo_box2d__GameBattleData__
#define __GameDemo_box2d__GameBattleData__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;



typedef struct
{
    int _OnlyId;
    char _big_pic[20];
    char _head_pic[20];
    char _DNA_pic[20];
    int _star;//卡牌品质0:铜1:银2:金
    int _nature;//普通0|勇敢1|精明2|胆小3|
    int _init_level;//初始等级
    int _max_level;//最大等级
    int _clone_cost;//克隆价格
    int _init_attack;//初始攻击
    int _attack_growth;//攻击成长
    int _init_hp;//初始血量
    int _hp_growth;//血量成长值
    int _attack_speed;//攻击速度(攻击一次需要的时间 毫秒)
    int _move_speed;//移动速度(一秒内移动单位:方格 标准:100X60)
    int _bullet_speed;//子弹速度
    int _bullet_effectR;//子弹影响半径(标准单位)
    int _bullet_type;//子弹类型(1:aoe点到面 2:指向性 点到点 3:跟踪性 点到物体)
    int _attack_range;//攻击距离(单位:方格 标准:100X60)
    int _no_attack_range;//盲区范围(单位:方格 标准:100X60)
    int _skill_id_1;//技能id
    int _skill_id_2;
    int _skill_id_3;
    int _big_skill_id;//必杀技能id
    char _big_skill_pic[20];
    char _big_skill_CG[20];
    char _comment[100];

    int _Orientation;
    char name[20];//const char *name;
    char nameStrId[20];//const char *nameStrId;
//    std::string nameStrId;
    char bulletName[30];

    float _now_hp_limit;
    float _now_hp;
    float _now_attack;
    float _now_attack_limit;
    int _now_level;
    
    float _now_move_speed;
    float _now_attack_range;//当前换算后的攻击距离
    float _now_no_attack_range;
    
    float box_x;
    float box_y;
    float box_w;
    float box_h;
    
    float norm_h;//标准高度
    
    int num_o_x;//跳出数字的x轴偏移量
    int num_o_y;//跳出数字的y轴偏移量
    
    int bullet_o_x;//子弹射出的x轴偏移量
    int bullet_o_y;//子弹射出的y轴偏移量
    
    char sound_attack[40];//人物普通攻击声音
    char sound_dead[40];//人物死亡声音
    
}BattleDefenseXmlDataBase;//卡牌战斗信息 xml数据结构

typedef struct
{
    int _OnlyId;
    char _big_pic[20];
    char _head_pic[20];
    char _DNA_pic[20];
    int _star;//卡牌品质0:铜1:银2:金
    int _nature;//普通0|勇敢1|精明2|胆小3|
    int _init_level;//初始等级
    int _max_level;//最大等级
    int _clone_cost;//克隆价格
    int _init_attack;//初始攻击
    int _attack_growth;//攻击成长
    int _init_hp;//初始血量
    int _hp_growth;//血量成长值
    int _attack_speed;//攻击速度(攻击一次需要的时间 毫秒)
    int _move_speed;//移动速度(一秒内移动单位:方格 标准:100X60)
    int _bullet_speed;//子弹速度
    int _bullet_effectR;//子弹影响半径(标准单位)
    int _bullet_type;//子弹类型(1:aoe点到面 2:指向性 点到点 3:跟踪性 点到物体)
    int _attack_range;//攻击距离(单位:方格 标准:100X60)
    int _no_attack_range;//盲区范围(单位:方格 标准:100X60)
    int _skill_id_1;//技能id
    int _skill_id_2;
    int _skill_id_3;
    int _big_skill_id;//必杀技能id
    char _big_skill_pic[20];
    char _big_skill_CG[20];
    char _comment[100];
    
    int _Orientation;
    char name[20];//const char *name;
    char nameStrId[20];//const char *nameStrId;
//    std::string nameStrId;
    char bulletName[30];
    
    float _now_hp_limit;
    float _now_hp;
    float _now_attack;
    float _now_attack_limit;
    int _now_level;
    
    float _now_move_speed;
    float _now_attack_range;//当前换算后的攻击距离
    float _now_no_attack_range;
    
    float box_x;
    float box_y;
    float box_w;
    float box_h;
    
    float norm_h;//标准高度
    
    int num_o_x;//跳出数字的x轴偏移量
    int num_o_y;//跳出数字的y轴偏移量
    
    int bullet_o_x;//子弹射出的x轴偏移量
    int bullet_o_y;//子弹射出的y轴偏移量
    
    char sound_attack[40];//人物普通攻击声音
    char sound_dead[40];//人物死亡声音
    
    char _heroInfo[100];//英雄介绍
    int _heroStone;//进阶所需灵魂石数
    float _hpAdrate;
    float _apAdrate;
    
    int _stoneFind_FBtype;//灵魂石掉落副本类型(0普通，1精英)
    int _stoneFind_FBplanet;//灵魂石掉落星球(0则不为关卡掉落，1234为星球编号)
    int _stone_FBnumber;//灵魂石掉落关卡（1——10）
    
}BattleAttackXmlDataBase;//卡牌战斗信息 xml数据结构


#endif /* defined(__GameDemo_box2d__GameBattleData__) */
