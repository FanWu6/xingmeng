//
//  Playerinfo.cpp
//  hello
//
//  Created by 吴凡 on 14-3-24.
//
//

#include "Playerinfo.h"
#include "Config.h"
Playerinfo::Playerinfo(){
    player_lvl = 1;
    player_gold = 0;
    
    Play_hero playhero;
//    player_vec.clear();
    //初始化英雄信息
    for(int i=0;i<11;i++){
//        if(i<11){
//        playhero.isOwned = true;
//        }else{
//            playhero.isOwned = false;
//        }
        if(i==0||i==1||i==2){
            playhero.isOwned = true;
        }else{
             playhero.isOwned = false;
        }
        
        playhero.flag = false;
        playhero.hero_index = i;
        playhero.hero_level = 1;
        playhero.hero_exp = 0;
        playhero.star_level = 1;
        playhero.stone_rate = 0;
        playhero.putPos_x = 0;
        playhero.putPos_y = 0;
        playhero.appearenceTime = 0;
        
        player_vec.push_back(playhero);
    }
    //初始化关卡信息
    
    maxlevel_flag[0] = 1;
    maxlevel_flag[1] = 0;
    maxlevel_flag[2] = 0;
    maxlevel_flag[3] = 0;
    for(int i = 0;i<40;i++){
        passedlevel_star[i] = 0;
    }
    
}

Playerinfo::~Playerinfo(){
    
}

void Playerinfo::save_BData(){
    myData->setIntegerForKey("player_lvl",player_lvl);
    myData->setIntegerForKey("player_gold",player_gold);
    
    myData->flush();
}

void Playerinfo::read_BData(){
   player_lvl = myData->getIntegerForKey("player_lvl", player_lvl);
    player_gold = myData->getIntegerForKey("player_gold", player_gold);
}

void Playerinfo::save_HData(int index){
    CCString *strf = CCString::createWithFormat("flag%d",index);
    CCString *strx = CCString::createWithFormat("putPos_x%d",index);
    CCString *stry = CCString::createWithFormat("putPos_y%d",index);
    CCString *strt = CCString::createWithFormat("app_time%d",index);
    myData->setBoolForKey(strf->getCString(), player_vec[index].flag);
    myData->setFloatForKey(strx->getCString(), player_vec[index].putPos_x);
    myData->setFloatForKey(stry->getCString(), player_vec[index].putPos_y);
    
//    player_vec[index].appearenceTime = (player_vec[index].putPos_x-10.0f)/544.0f*15.0f;
    myData->setFloatForKey(strt->getCString(), player_vec[index].appearenceTime);
    myData->flush();
}

void Playerinfo::read_HData(){
    for(int i = 0;i<11;i++){
        CCString *strf = CCString::createWithFormat("flag%d",i);
        player_vec[i].flag = myData->getBoolForKey(strf->getCString(), player_vec[i].flag);
        CCString *strx = CCString::createWithFormat("putPos_x%d",i);
        CCString *stry = CCString::createWithFormat("putPos_y%d",i);
        CCString *strt = CCString::createWithFormat("app_time%d",i);
        player_vec[i].putPos_x = myData->getFloatForKey(strx->getCString(), player_vec[i].putPos_x);
        player_vec[i].putPos_y = myData->getFloatForKey(stry->getCString(), player_vec[i].putPos_y);
        player_vec[i].appearenceTime = myData->getFloatForKey(strt->getCString(), player_vec[i].appearenceTime);
    }
}

//保存大关卡数据
void Playerinfo::save_planet(int planet_index){
    CCString *pas_idx = CCString::createWithFormat("passedidx%d",(planet_index*10)+config->CurLevelIndex);
//    CCLOG("curLE====%d",planet_index);
    CCString *max_idx = CCString::createWithFormat("maxidx%d",planet_index);
    myData->setIntegerForKey(pas_idx->getCString(),passedlevel_star[(planet_index*10)+config->CurLevelIndex]);
    myData->setIntegerForKey(max_idx->getCString(),maxlevel_flag[planet_index]);
    
    myData->flush();
}
void Playerinfo::read_planet(int planet_index){
        for (int j = 0;j<10;j++){
        CCString *pas_idx = CCString::createWithFormat("passedidx%d",(planet_index*10)+j);
        passedlevel_star[(planet_index*10)+j] = myData->getIntegerForKey(pas_idx->getCString(),passedlevel_star[(planet_index*10)+j]);
        }
        CCString *max_idx = CCString::createWithFormat("maxidx%d",planet_index);
        maxlevel_flag[planet_index] = myData->getIntegerForKey(max_idx->getCString(),maxlevel_flag[planet_index]);
    
}

//