//
//  HeroSkillLayer.cpp
//  hello
//
//  Created by 吴凡 on 14-5-15.
//
//

#include "HeroSkillLayer.h"
#include "Resource.h"
#include "HeroSkillccbi.h"

HeroSkillLayer::HeroSkillLayer(){
    
}

HeroSkillLayer::~HeroSkillLayer(){
    
}

bool HeroSkillLayer::init(){
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    this->setTouchPriority(-128);
    this->setTouchMode(kCCTouchesAllAtOnce);
    //加载cocosbuilder
    CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("HeroSkillccbi",HeroSkillccbiLoder::loader());
    /* Create an autorelease CCBReader. */
    CCBReader * ccbReader = new cocos2d::extension::CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    ccbReader->autorelease();
    /* Read a ccbi file. */
    node2 = ccbReader->readNodeGraphFromFile("ccbi/HeroSkillccbi.ccbi", this);
    if(node2 != NULL) {
        this->addChild(node2);
    }
    this->setVisible(false);
    isSkillLayer = true;
    layervisable = false;
    curPage = 0;//当前页
    addsprite();
    changeData();
    scheduleUpdate();
    return true;
}

void HeroSkillLayer::addsprite(){
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("headPic.plist");
//    CCSprite *jjcancel = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jjcancel.png"));
//    CCSprite *jjcancel_click = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jjcancel.png_click_s.png"));
//    CCMenuItemSprite *back = CCMenuItemSprite::create(jjcancel, jjcancel_click,this,menu_selector(HeroJJLayer::backonClick));
//    menu = CCMenu::create(back,NULL);
//    //    menu->setAnchorPoint(ccp(0, 0));
//    menu->setPosition(ccp(501, 318));
//    this->addChild(menu);
//    menu->setZOrder(10);
}

void HeroSkillLayer::backonClick(){
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

void HeroSkillLayer::reverseSkill(){
    CCSprite * skillLayer = (CCSprite *)node2->getChildByTag(200);
    CCOrbitCamera *c1;
    if(isSkillLayer){
        skillLayer->setScaleX(-1);
        c1 = CCOrbitCamera::create(2, 1, 0, 0, -180, 0, 0);
        CCLOG("2");
        CCDelayTime *delay = CCDelayTime::create(1.35);
        CCCallFuncN * skillCallback = CCCallFuncN::create(this, callfuncN_selector(HeroSkillLayer::skillCallBack));
        CCCallFuncN * setvistrue = CCCallFuncN::create(this, callfuncN_selector(HeroSkillLayer::setVisTrue));
        skillLayer->runAction(CCSequence::create(c1,skillCallback,NULL));
        skillLayer->runAction(CCSequence::create(delay,setvistrue,NULL));
        

    }else{
        skillLayer->setScaleX(1);
        c1 = CCOrbitCamera::create(2, 1, 0, 0, 180, 0, 0);
        CCLOG("1");
        CCDelayTime *delay = CCDelayTime::create(1.35);
        CCCallFuncN * skillCallback = CCCallFuncN::create(this, callfuncN_selector(HeroSkillLayer::skillCallBack));
        CCCallFuncN * setvisfalse = CCCallFuncN::create(this, callfuncN_selector(HeroSkillLayer::setVisFalse));
        skillLayer->runAction(CCSequence::create(c1,skillCallback,NULL));
        skillLayer->runAction(CCSequence::create(delay,setvisfalse,NULL));

    }
    
}
void HeroSkillLayer::setVisTrue(){
    this->setVisible(true);
}

void HeroSkillLayer::setVisFalse(){
    this->setVisible(false);
}

void HeroSkillLayer::skillCallBack(){
    isSkillLayer=!isSkillLayer;
}

void HeroSkillLayer::onEnter()
{
    CCLayer::onEnter();
    //    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
}

void HeroSkillLayer::onExit()
{
    CCLayer::onExit();
}

void HeroSkillLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

void HeroSkillLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //    CCLOG("~~~~~~");
}

bool HeroSkillLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void HeroSkillLayer::update(float dt){
    if(curPage != config->heroPage){
        curPage = config->heroPage;
        changeData();
    }
    
}

void HeroSkillLayer::changeData(){
    //------技能1更新
    //技能1图标
    _skillData = (SkillData *)m_skillList->objectAtIndex(config->heroPage);
    CCSprite *skillspr1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(1);
    CCString *string_spr1 = CCString::createWithFormat("%s",_skillData->m_icon);
    CCLOG("--------%s",_skillData->m_icon);
    skillspr1->initWithFile(string_spr1->getCString());
    
    
}