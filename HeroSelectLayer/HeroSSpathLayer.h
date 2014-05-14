//
//  HeroSSpathLayer.h
//  hello
//
//  Created by 吴凡 on 14-5-13.
//
//

#ifndef __hello__HeroSSpathLayer__
#define __hello__HeroSSpathLayer__

#include "cocos2d.h"
#include "Config.h"
#include "Playerinfo.h"
USING_NS_CC;
class HeroSSpathLayer: public CCLayer
{
public:
    HeroSSpathLayer();
    ~HeroSSpathLayer();
    
    virtual bool init();
    
    CREATE_FUNC(HeroSSpathLayer);
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
private:
    CCNode * node;
    
};

#endif /* defined(__hello__HeroSSpathLayer__) */
