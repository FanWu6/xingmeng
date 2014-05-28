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
    _pinfo = new Playerinfo();//用户数据
    //技能属性1
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
    //
    CCLOG("技能");
    return true;
}

void HeroSkillLayer::update(float dt){
    if(curPage != config->heroPage){
        curPage = config->heroPage;
        scrolllabel1->removeFromParentAndCleanup(true);
        scrolllabel2->removeFromParentAndCleanup(true);
        changeData();
    }
    
}

void HeroSkillLayer::changeData(){
     _skillData = (SkillData *)m_skillList->objectAtIndex(config->heroPage);
    _bigskillData = (BigSkillData *)m_bigSkillList->objectAtIndex(config->heroPage);
    //------技能1更新
    //技能1图标
    CCSprite *skillspr1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(1);
    CCString *string_spr1 = CCString::createWithFormat("%s",_skillData->m_icon);
    skillspr1->initWithFile(string_spr1->getCString());
    //技能1名称
    CCLabelTTF *skillname1 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(2);
    CCString *string_name1 = CCString::createWithFormat("%s",_skillData->m_name);
    skillname1->setString(string_name1->getCString());
    //技能1说明
    CCSprite *skillinfo1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(4);
    CCString *string_info1 = CCString::createWithFormat("%s",_skillData->m_info);
    CCSize size = skillinfo1->getContentSize();
    scrolllabel1 = XJScrollLabel::create(string_info1->getCString(), "Helvetica", 12, kCCTextAlignmentLeft,CCSizeMake(size.width, size.height*0.7f),120);
    node2->getChildByTag(200)->addChild(scrolllabel1);
    scrolllabel1->setPosition(ccp(30,155));
    //技能1状态更新
    if(_pinfo->player_vec[config->heroPage].star_level >=2){
        CCLabelTTF *tiaojian1 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(3);
        tiaojian1->setOpacity(0);
         CCSprite *gold1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(5);
        gold1->setVisible(true);
         CCSprite *add1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(11);
        add1->setOpacity(255);
    }else{
        CCLabelTTF *tiaojian1 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(3);
        tiaojian1->setOpacity(255);
        CCSprite *gold1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(5);
        gold1->setVisible(false);
        CCSprite *add1 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(11);
        add1->setOpacity(0);
    }
    //-----技能2更新
    //技能2图标
    CCSprite *skillspr2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(6);
    CCString *string_spr2 = CCString::createWithFormat("%s",_bigskillData->m_icon);
    skillspr2->initWithFile(string_spr2->getCString());
    //技能2名称
    CCLabelTTF *skillname2 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(7);
    CCString *string_name2 = CCString::createWithFormat("%s",_bigskillData->m_name);
    skillname2->setString(string_name2->getCString());
    //技能2说明
    CCSprite *skillinfo2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(4);
    CCString *string_info2 = CCString::createWithFormat("%s",_bigskillData->m_info);
    CCSize size2 = skillinfo2->getContentSize();
    scrolllabel2 = XJScrollLabel::create(string_info2->getCString(), "Helvetica", 12, kCCTextAlignmentLeft,CCSizeMake(size2.width, size2.height*0.7f),120);
    node2->getChildByTag(200)->addChild(scrolllabel2);
    scrolllabel2->setPosition(ccp(30,30));
    //技能2状态更新
    if(_pinfo->player_vec[config->heroPage].star_level >=5){
        CCLabelTTF *tiaojian2 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(8);
        tiaojian2->setOpacity(0);
        CCSprite *gold2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(10);
        gold2->setVisible(true);
        CCSprite *add2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(12);
        add2->setOpacity(255);
    }else{
        CCLabelTTF *tiaojian2 = (CCLabelTTF *)node2->getChildByTag(200)->getChildByTag(8);
        tiaojian2->setOpacity(255);
        CCSprite *gold2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(10);
        gold2->setVisible(false);
        CCSprite *add2 = (CCSprite *)node2->getChildByTag(200)->getChildByTag(12);
        add2->setOpacity(0);
    }
    
}