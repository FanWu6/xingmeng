//
//  Embattleccbi.cpp
//  hello
//
//  Created by 吴凡 on 14-3-18.
//
//

#include "Select2ccbi.h"
#include "EmbattleLayer.h"
#include "SelectLayer.h"

//using namespace CocosDenshion;
USING_NS_CC;
USING_NS_CC_EXT;


Select2ccbi::Select2ccbi(){
    p_info = new Playerinfo();
    p_info->read_planet(config->CurPlanetIndex);
}

Select2ccbi::~Select2ccbi(){
    
}

bool Select2ccbi::init(){
    if(!CCLayer::init())
        return false;
    
    return true;
}

SEL_MenuHandler Select2ccbi::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backtoMenu", Select2ccbi::backtoMenu);
    
    
    
    return NULL;
}

SEL_CCControlHandler Select2ccbi::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle0", Select2ccbi::toEmbattle0);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle1", Select2ccbi::toEmbattle1);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle2", Select2ccbi::toEmbattle2);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle3", Select2ccbi::toEmbattle3);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle4", Select2ccbi::toEmbattle4);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle5", Select2ccbi::toEmbattle5);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle6", Select2ccbi::toEmbattle6);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle7", Select2ccbi::toEmbattle7);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle8", Select2ccbi::toEmbattle8);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "toEmbattle9", Select2ccbi::toEmbattle9);
    return NULL;
}

void Select2ccbi::backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    CCScene* scene = CCScene::create();
    SelectLayer* layer = SelectLayer::create();
    scene->addChild(layer);
    CCDirector::sharedDirector()->replaceScene(scene);
    
    CCLOG(">>>>>>>>>>------back");
    
}
void Select2ccbi::replaceScene(int index){
    CCLOG(">>>>>>>>>>------toEm");
    
    config->CurLevelIndex = index;
    if(p_info->maxlevel_flag[config->CurPlanetIndex]>index){
    CCScene* scene = CCScene::create();
    EmbattleLayer* layer = EmbattleLayer::create();
    scene->addChild(layer);
    CCDirector::sharedDirector()->replaceScene(scene);
    }
}
void Select2ccbi::toEmbattle0(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(0);
}
void Select2ccbi::toEmbattle1(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(1);
}
void Select2ccbi::toEmbattle2(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(2);
}
void Select2ccbi::toEmbattle3(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(3);
}
void Select2ccbi::toEmbattle4(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(4);
}
void Select2ccbi::toEmbattle5(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(5);
}
void Select2ccbi::toEmbattle6(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(6);
}
void Select2ccbi::toEmbattle7(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(7);
}
void Select2ccbi::toEmbattle8(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(8);
}
void Select2ccbi::toEmbattle9(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    replaceScene(9);
}

