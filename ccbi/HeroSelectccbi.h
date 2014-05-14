//
//  Inventoryccbi.h
//  hello
//
//  Created by 吴凡 on 14-4-21.
//
//

#ifndef __hello__HeroSelectccbi__
#define __hello__HeroSelectccbi__


#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;


class HeroSelectccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    HeroSelectccbi();
    ~HeroSelectccbi();
    
    CREATE_FUNC(HeroSelectccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void onStartSet(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class HeroSelectccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeroSelectccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(HeroSelectccbi);
    
};



#endif /* defined(__hello__HeroSelectccbi__) */
