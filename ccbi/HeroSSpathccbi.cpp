//
//  HeroSSpathccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-5-13.
//
//

#include "HeroSSpathccbi.h"
USING_NS_CC;
USING_NS_CC_EXT;

HeroSSpathccbi::HeroSSpathccbi(){
    
}

HeroSSpathccbi::~HeroSSpathccbi(){
    
}

bool HeroSSpathccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler HeroSSpathccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Inventoryccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler HeroSSpathccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void HeroSSpathccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}