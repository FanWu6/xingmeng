//
//  Inventoryccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-4-21.
//
//

#include "Inventoryccbi.h"
USING_NS_CC;
USING_NS_CC_EXT;

Inventoryccbi::Inventoryccbi(){
    
}

Inventoryccbi::~Inventoryccbi(){
    
}

bool Inventoryccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler Inventoryccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Inventoryccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler Inventoryccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void Inventoryccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}