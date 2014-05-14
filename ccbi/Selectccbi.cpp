//
//  Embattleccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-3-18.
//
//

#include "Selectccbi.h"



//using namespace CocosDenshion;
USING_NS_CC;
USING_NS_CC_EXT;

Selectccbi::Selectccbi(){
    
}

Selectccbi::~Selectccbi(){
    
}

bool Selectccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler Selectccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Selectccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler Selectccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void Selectccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}
