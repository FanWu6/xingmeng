//
//  HeroSSpathccbi.h
//  hello
//
//  Created by 吴凡 on 14-5-13.
//
//

#ifndef __hello__HeroSSpathccbi__
#define __hello__HeroSSpathccbi__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;

class HeroSSpathccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    HeroSSpathccbi();
    ~HeroSSpathccbi();
    
    CREATE_FUNC(HeroSSpathccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class HeroSSpathccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeroSSpathccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(HeroSSpathccbi);
    
};


#endif /* defined(__hello__HeroSSpathccbi__) */
