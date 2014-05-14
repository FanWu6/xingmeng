//
//  HeroJJLayer.cpp
//  hello
//
//  Created by 吴凡 on 14-5-14.
//
//

#include "HeroJJLayer.h"
#include "Resource.h"
#include "jjLayerccbi.h"

HeroJJLayer::HeroJJLayer(){
    
}

HeroJJLayer::~HeroJJLayer(){
    
}

bool HeroJJLayer::init(){
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    this->setTouchPriority(-128);
    this->setTouchMode(kCCTouchesOneByOne);
    //加载cocosbuilder
    CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("jjLayerccbi",jjLayerccbiLoder::loader());
    /* Create an autorelease CCBReader. */
    CCBReader * ccbReader = new cocos2d::extension::CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    ccbReader->autorelease();
    /* Read a ccbi file. */
    node = ccbReader->readNodeGraphFromFile("ccbi/jjLayerccbi.ccbi", this);
    if(node != NULL) {
        this->addChild(node);
    }
    layervisable = false;
    addsprite();
    return true;
}

void HeroJJLayer::addsprite(){
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("jjLayer.plist");
    CCSprite *jjcancel = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jjcancel.png"));
    CCSprite *jjcancel_click = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jjcancel.png_click_s.png"));
    CCMenuItemSprite *back = CCMenuItemSprite::create(jjcancel, jjcancel_click,this,menu_selector(HeroJJLayer::backonClick));
    menu = CCMenu::create(back,NULL);
    //    menu->setAnchorPoint(ccp(0, 0));
    menu->setPosition(ccp(501, 318));
    this->addChild(menu);
    menu->setZOrder(10);
}

void HeroJJLayer::backonClick(){
    CCLOG("~~~~~~");
    //    if(layervisable){
    //    this->setVisible(false);
    //    this->setTouchEnabled(false);
    //        menu->setTouchEnabled(false);
    //        layervisable = false;
    //    }else{
    //        this->setVisible(true);
    //        this->setTouchEnabled(true);
    //        menu->setTouchEnabled(true);
    //        layervisable = true;
    //    }
    this->removeFromParent();
    
}

void HeroJJLayer::onEnter()
{
    CCLayer::onEnter();
    //    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
}

void HeroJJLayer::onExit()
{
    CCLayer::onExit();
}

void HeroJJLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

void HeroJJLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //    CCLOG("~~~~~~");
}

bool HeroJJLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}