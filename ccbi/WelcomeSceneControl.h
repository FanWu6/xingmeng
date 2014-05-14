//
//  WelcomeSceneControl.h
//  PeriNosePicking
//
//  Created by 陈 先生 on 14-2-25.
//
//

#ifndef __PeriNosePicking__WelcomeSceneControl__
#define __PeriNosePicking__WelcomeSceneControl__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;


class WelcomeSceneControl : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    WelcomeSceneControl();
    ~WelcomeSceneControl();
    
    CREATE_FUNC(WelcomeSceneControl);
    
    virtual bool init();
    void onStartGame(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void backToselect(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void onStartSet(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    

    
    

};

class WelcomeSceneLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WelcomeSceneLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WelcomeSceneControl);
    
};




#endif /* defined(__PeriNosePicking__WelcomeSceneControl__) */