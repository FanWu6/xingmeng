//
//  Inventoryccbi.h
//  hello
//
//  Created by 吴凡 on 14-4-21.
//
//

#ifndef __hello__Inventoryccbi__
#define __hello__Inventoryccbi__


#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;


class Inventoryccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    Inventoryccbi();
    ~Inventoryccbi();
    
    CREATE_FUNC(Inventoryccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void onStartSet(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class InventoryccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InventoryccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Inventoryccbi);
    
};



#endif /* defined(__hello__Inventoryccbi__) */
