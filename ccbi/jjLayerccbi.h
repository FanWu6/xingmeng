//
//  jjLayerccbi.h
//  hello
//
//  Created by 吴凡 on 14-5-14.
//
//

#ifndef __hello__jjLayerccbi__
#define __hello__jjLayerccbi__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;

class jjLayerccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    jjLayerccbi();
    ~jjLayerccbi();
    
    CREATE_FUNC(jjLayerccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class jjLayerccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(jjLayerccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(jjLayerccbi);
    
};


#endif /* defined(__hello__jjLayerccbi__) */
