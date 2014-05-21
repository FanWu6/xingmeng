//
//  HeroSkillLayer.h
//  hello
//
//  Created by 吴凡 on 14-5-15.
//
//

#ifndef __hello__HeroSkillLayer__
#define __hello__HeroSkillLayer__

#include "cocos2d.h"
#include "Config.h"
#include "Playerinfo.h"
#include "GoodsData.h"
USING_NS_CC;
class HeroSkillLayer: public CCLayer
{
public:
    HeroSkillLayer();
    ~HeroSkillLayer();
    
    virtual bool init();
    
    CREATE_FUNC(HeroSkillLayer);
public:
    // 初始化相关
    virtual void onEnter();
    virtual void onExit();
    
    // 触摸事件相关
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	
public:
    void addsprite();
    void backonClick();
    bool layervisable;
    CCMenu *menu;
    
    void reverseSkill();
    void skillCallBack();
    bool isSkillLayer;
    
    void setVisTrue();
    void setVisFalse();
    
    virtual void update(float dt);
    int curPage;
    void changeData();
public:
    CCNode * node2;
    
public:
    SkillData *_skillData;
    BigSkillData *_bigskillData;
private:
    Playerinfo *_pinfo;
    
};

#endif /* defined(__hello__HeroSkillLayer__) */
