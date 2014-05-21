//
//  XmlTool.h
//  GameDemo
//
//  Created by 王伟 on 13-7-9.
//
//

#ifndef __GameDemo__XmlTool__
#define __GameDemo__XmlTool__
#include "cocos2d.h"
#include "tinyxml.h"
#include "cocos-ext.h"
//#include "DefendScene.h"

//#include "MonsterExploreData.h"

#include "GameBattleData.h"

//#include "TeamIndexData.h"

#include "GoodsData.h"

USING_NS_CC_EXT;
USING_NS_CC;

class EasyXmlTool{
public:
    EasyXmlTool();
    ~EasyXmlTool();
    
//    void readXmlbyFileBuff(const char* FileName,vector<buildFightData> *v);
//    void readXmlbyFileBuff(const char* FileName,vector<armyFightData> *v);
//    void readXmlbyFileBuff(const char* FileName,vector<MonsterExploreXmlDataBase> *v);
    void readXmlbyFileBuff(const char* FileName,vector<BattleDefenseXmlDataBase> *v,CCSize *unit);
    void readXmlbyFileBuff(const char* FileName,vector<BattleAttackXmlDataBase> *v,CCSize *unit);
//    void readXmlbyFileBuff(const char* FileName,vector<TeamIndexXmlDataBase> *v);
//    
//    void readXmlbyFileBuff(const char* FileName,vector<BattleBgXmlDataBase> *v);
//    void readXmlbyFileBuff(const char* FileName,vector<ExploreBgXmlDataBase> *v);
    
    /* 读取物品数据 */
    void readResXmlbyFileBuff(const char* FileName,CCArray *_c);
    void readCardsXmlbyFileBuff(const char* FileName,CCArray *_c);
    void readCardsStoneXmlbyFileBuff(const char* FileName,CCArray *_c);
    void readPropXmlbyFileBuff(const char* FileName,CCArray *_c);
    void readBoxXmlbyFileBuff(const char* FileName,CCArray *_c);
    void readGiftXmlbyFileBuff(const char* FileName,CCArray *_c);
    
    void readRewardXmlbyFileBuff(const char* FileName,CCArray *_c);
    
    /* 读取技能列表 */
    void readSkillXmlbyFileBuff(const char* FileName,CCArray *_c);
    /* 读取big技能列表 */
    void readBigSkillXmlbyFileBuff(const char* FileName,CCArray *_c);
    
    void writeBuildXmlToFile(const char* FileName);
    
    void initNow(BattleDefenseXmlDataBase *database,CCSize *unit);
    void initNow(BattleAttackXmlDataBase *database,CCSize *unit);
    

};

#endif /* defined(__GameDemo__XmlTool__) */
