//
//  HeroSkillccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-5-15.
//
//

#include "HeroSkillccbi.h"
USING_NS_CC;
USING_NS_CC_EXT;

HeroSkillccbi::HeroSkillccbi(){
    
}

HeroSkillccbi::~HeroSkillccbi(){
    
}

bool HeroSkillccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler HeroSkillccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    //    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Inventoryccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler HeroSkillccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void HeroSkillccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    
}