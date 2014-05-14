//
//  HeroSSpathLayer.cpp
//  hello
//
//  Created by 吴凡 on 14-5-13.
//
//

#include "HeroSSpathLayer.h"
#include "Resource.h"
#include "HeroSSpathccbi.h"
USING_NS_CC;

HeroSSpathLayer::HeroSSpathLayer(){
    
}

HeroSSpathLayer::~HeroSSpathLayer(){
    
}

bool HeroSSpathLayer::init(){
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    this->setTouchPriority(-128);
    this->setTouchMode(kCCTouchesOneByOne);
    //加载cocosbuilder
    CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("HeroSSpathccbi",HeroSSpathccbiLoder::loader());
    /* Create an autorelease CCBReader. */
    CCBReader * ccbReader = new cocos2d::extension::CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    ccbReader->autorelease();
    /* Read a ccbi file. */
    node = ccbReader->readNodeGraphFromFile("ccbi/sspathccbi.ccbi", this);
    if(node != NULL) {
        this->addChild(node);
    }
    layervisable = false;
    addsprite();
    return true;
}

void HeroSSpathLayer::addsprite(){
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hero_sspath.plist");
    CCSprite *back_s = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("back_s.png"));
    CCSprite *back_click_s = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("back_click_s.png"));
    CCMenuItemSprite *back = CCMenuItemSprite::create(back_s, back_click_s,this,menu_selector(HeroSSpathLayer::backonClick));
    menu = CCMenu::create(back,NULL);
//    menu->setAnchorPoint(ccp(0, 0));
    menu->setPosition(ccp(396, 82));
    this->addChild(menu);
    menu->setZOrder(10);
}

void HeroSSpathLayer::backonClick(){
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

void HeroSSpathLayer::onEnter()
{
    CCLayer::onEnter();
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
}

void HeroSSpathLayer::onExit()
{
    CCLayer::onExit();
}

void HeroSSpathLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

void HeroSSpathLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
//    CCLOG("~~~~~~");
}

bool HeroSSpathLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

