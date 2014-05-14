//
//  WelcomeSceneControl.cpp
//  PeriNosePicking
//
//  Created by 陈 先生 on 14-2-25.
//
//

#include "SimpleAudioEngine.h"
#include "WelcomeSceneControl.h"
#include "Select2Layer.h"

using namespace CocosDenshion;
USING_NS_CC;
USING_NS_CC_EXT;

WelcomeSceneControl::WelcomeSceneControl(){
    
    
}
WelcomeSceneControl::~WelcomeSceneControl(){
    
    
    
}



bool WelcomeSceneControl::init(){
//    bool bRet = false;
//	do
//	{
//        
//        CC_BREAK_IF(! CCLayer::init() );
//        
//        CCDirector* pDirector = CCDirector::sharedDirector();
//        pDirector->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority+9, true);
//        
//        this->setTouchEnabled(true);
//        
//        bRet = true;
//	} while (0);
//    
//    return bRet;
    if(!CCLayer::init())
        return false;
    
    return true;
}


SEL_MenuHandler WelcomeSceneControl::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "abc", WelcomeSceneControl::onStartGame);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "backToselect", WelcomeSceneControl::backToselect);
 
    
    
    return NULL;
}

SEL_CCControlHandler WelcomeSceneControl::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    
    return NULL;
}

void WelcomeSceneControl::onStartGame(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>开战回调");
//    EmbattleLayer::battleSave();
}

void WelcomeSceneControl::backToselect(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent){
    
    CCLOG(">>>>>>>>>>返回主菜单");
    CCScene* scene = CCScene::create();
    Select2Layer* layer = Select2Layer::create();
    scene->addChild(layer);
    CCDirector::sharedDirector()->replaceScene(scene);
}



