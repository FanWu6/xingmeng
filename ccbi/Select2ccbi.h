//
//  Embattleccbi.h
//  hello
//
//  Created by 吴凡 on 14-3-18.
//
//

#ifndef __hello__Embattleccbi__
#define __hello__Embattleccbi__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Playerinfo.h"
USING_NS_CC;


class Select2ccbi : public cocos2d::CCLayer
, public cocos2d::extension::CCBSelectorResolver
{
public:
    
    
    Select2ccbi();
    ~Select2ccbi();
    Playerinfo *p_info;
    
    CREATE_FUNC(Select2ccbi);
    
    virtual bool init();
    void backtoMenu(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    //关卡选择
    void toEmbattle0(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle1(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle2(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle3(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle4(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle5(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle6(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle7(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle8(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void toEmbattle9(CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void replaceScene(int index);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char* pSelectorName);

    
    
};

class Select2ccbiLoder :public cocos2d::extension::CCLayerLoader{
    
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(Select2ccbiLoder, loader);
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Select2ccbi);
    
};
#endif /* defined(__hello__Embattleccbi__) */
