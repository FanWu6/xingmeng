//
//  Embattleccbi.h
//  hello
//
//  Created by 吴凡 on 14-3-18.
//
//

#ifndef __hello__Embattleccbi__
#define __hello__Embattleccbi__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;


class Selectccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    Selectccbi();
    ~Selectccbi();
    
    CREATE_FUNC(Selectccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void onStartSet(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class SelectccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SelectccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Selectccbi);
    
};
#endif /* defined(__hello__Embattleccbi__) */
