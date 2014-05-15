//
//  HeroSkillccbi.h
//  hello
//
//  Created by 吴凡 on 14-5-15.
//
//

#ifndef __hello__HeroSkillccbi__
#define __hello__HeroSkillccbi__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;

class HeroSkillccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    HeroSkillccbi();
    ~HeroSkillccbi();
    
    CREATE_FUNC(HeroSkillccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    
    
    
    
    
};

class HeroSkillccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeroSkillccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(HeroSkillccbi);
    
};

#endif /* defined(__hello__HeroSkillccbi__) */
