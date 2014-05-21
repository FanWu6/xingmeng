//
//  HeroSelectLayer.h
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#ifndef __hello__HeroSelectLayer__
#define __hello__HeroSelectLayer__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "HeroSelectContent.h"
#include "HeroSelectScrollView.h"
#include "Playerinfo.h"
#include "cocos-widget.h"
#include "HeroSSpathLayer.h"
#include "HeroJJLayer.h"
#include "HeroSkillLayer.h"
using namespace cocos2d::cocoswidget;
USING_NS_CC;

class HeroSelectLayer : public cocos2d::CCLayer
{
private:
    HeroSelectContentLayer* layer;//
    HeroScrollView *scroll;
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    //滑动
    virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
    //update
    virtual void update(float dt);
    
    CREATE_FUNC(HeroSelectLayer);
    //数据
    void initData();
    //界面
    void addSprite();
    //{
    //}
    void addScroll();
    void changeData();//更新数据
    //
    void stonelvlup();//灵魂石进阶更新
    CCTexture2D *_sstiao;
    //
    int curPage;
    int curOnlyID[20];
    //skillcallback
    HeroSkillLayer *_skillLayer;
    void skillCallback();
    bool isSkillLayer;
    bool isbutton;
    void shuxingCallback();
    //
    void setVisTrue();
    void setVisFalse();
 
private:
    // 按下点
    CCPoint h_TouchDownPoint;
    // 抬起点 配合使用判断是否为点击事件
    CCPoint h_TouchUpPoint;
    // 当前触摸点
    CCPoint h_TouchCurPoint;
    
private:
    vector<BattleAttackXmlDataBase> attack_data;
    
    Playerinfo *_pinfo;
private:
    CCNode * node;
};

#endif /* defined(__hello__HeroSelectLayer__) */
