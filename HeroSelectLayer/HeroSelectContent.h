//
//  HeroSelectContent.h
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#ifndef __hello__HeroSelectContent__
#define __hello__HeroSelectContent__

#include "cocos2d.h"
#include "Config.h"
#include "Playerinfo.h"
#include "CCArmature.h"
USING_NS_CC;

class HeroSelectContentLayer: public CCLayer
{
public:
    HeroSelectContentLayer();
    ~HeroSelectContentLayer();
    
    void initSelectDate();
    //
    CCArmature *spritehero;
    
    //读取关卡
    Playerinfo *p_info;
    
    virtual bool init();
    
    CREATE_FUNC(HeroSelectContentLayer);
    
    // 初始化相关
    virtual void onEnter();
    virtual void onExit();
    
    // 触摸事件相关
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void draw();
    //
    int mUserTag;
    int setUserTag(int userTag);
    int getUserTag();
private:
    // 按下点
    CCPoint m_TouchDownPoint;
    // 抬起点 配合使用判断是否为点击事件
    CCPoint m_TouchUpPoint;
    // 当前触摸点
    CCPoint m_TouchCurPoint;
    
    vector<BattleAttackXmlDataBase> attack_data;
};

#endif /* defined(__hello__HeroSelectContent__) */
