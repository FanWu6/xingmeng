//
//  Inventoryccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-4-21.
//
//

#include "HeroSelectccbi.h"
USING_NS_CC;
USING_NS_CC_EXT;

HeroSelectccbi::HeroSelectccbi(){
    
}

HeroSelectccbi::~HeroSelectccbi(){
    
}

bool HeroSelectccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler HeroSelectccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Inventoryccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler HeroSelectccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void HeroSelectccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}