//
//  jjLayerccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-5-14.
//
//

#include "jjLayerccbi.h"
USING_NS_CC;
USING_NS_CC_EXT;

jjLayerccbi::jjLayerccbi(){
    
}

jjLayerccbi::~jjLayerccbi(){
    
}

bool jjLayerccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler jjLayerccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Inventoryccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler jjLayerccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void jjLayerccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}