//
//  HeroSelectContent.cpp
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#include "HeroSelectContent.h"
#include "VisibleRect.h"
#include "Resource.h"
#include "CCArmatureDataManager.h"
USING_NS_CC;

HeroSelectContentLayer::HeroSelectContentLayer()
{
}

HeroSelectContentLayer::~HeroSelectContentLayer()
{
}

bool HeroSelectContentLayer::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayerColor::create());
        setContentSize(CCSizeMake(677/7, 138));
        
        bRet = true;
    } while (0);
    
    //读取关卡数据
    p_info = new Playerinfo();
    //    p_info->read_planet(config->CurPlanetIndex);
    //读取英雄骨骼动画
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMangel.png", "armature/MMangel.plist", "armature/MMangel.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMchuyin.png", "armature/MMchuyin.plist", "armature/MMchuyin.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMdeath.png", "armature/MMdeath.plist", "armature/MMdeath.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMdoraemon.png", "armature/MMdoraemon.plist", "armature/MMdoraemon.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMgunsgirl.png", "armature/MMgunsgirl.plist", "armature/MMgunsgirl.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMIronman.png", "armature/MMIronman.plist", "armature/MMIronman.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMmagicians.png", "armature/MMmagicians.plist", "armature/MMmagicians.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMmrblack.png", "armature/MMmrblack.plist", "armature/MMmrblack.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMsoldier.png", "armature/MMsoldier.plist", "armature/MMsoldier.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMvampire.png", "armature/MMvampire.plist", "armature/MMvampire.xml");
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/MMwolfman.png", "armature/MMwolfman.plist", "armature/MMwolfman.xml");
    //读取XML
    config->xmlread->readXmlbyFileBuff("xml/Card_Hero_Battle_Info.xml", &attack_data, NULL);
    p_info->read_HData();

    return bRet;
}

void HeroSelectContentLayer::initSelectDate(){
    int tag=getTag();
    p_info->read_planet(tag);
    CCString * str = CCString::createWithFormat("%s",attack_data[tag].nameStrId);
    spritehero  = CCArmature::create(str->getCString());
    spritehero->getAnimation()->play("stand");
    if(!p_info->player_vec[tag].isOwned){
        spritehero->setColor(ccc3(0,0,0));
//        ccBlendFunc cbl = {GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA};
//        spritehero->setBlendFunc(cbl);
    }
    //
    float _s = 90.0f/attack_data[tag].box_h;
//    spritehero->setAnchorPoint(ccp(0.5,0));
    //缩放
    spritehero->setScale(_s);
    spritehero->setContentSize(CCSize(spritehero->getContentSize().width*_s,spritehero->getContentSize().height*_s));
    float _anchor_x = (attack_data[tag].box_x*_s+attack_data[tag].box_w*_s/2)/spritehero->getContentSize().width;
    float _anchor_y = attack_data[tag].box_y*_s/spritehero->getContentSize().height;
    spritehero->setAnchorPoint(ccp(_anchor_x,_anchor_y));
    
    
    spritehero->setPosition(ccpAdd(VisibleRect::center(), ccp((677/7)  * tag, 0)));
    
    this->addChild(spritehero);
    //设置TAG
    spritehero->setTag(40+tag);
    this->setUserTag(attack_data[tag]._OnlyId);
}

void HeroSelectContentLayer::draw(){
    CCLayer::draw();
}

void HeroSelectContentLayer::onEnter()
{
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void HeroSelectContentLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool HeroSelectContentLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_TouchDownPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    m_TouchCurPoint = m_TouchDownPoint;
    return true;
}

void HeroSelectContentLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    // 移动
    CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    //    CCPoint posPoint = CCPointMake(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
    
    m_TouchCurPoint = touchPoint;
    
}

void HeroSelectContentLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_TouchUpPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    float offset = (m_TouchUpPoint.x - m_TouchDownPoint.x) * (m_TouchUpPoint.x - m_TouchDownPoint.x);
    p_info->read_planet(config->CurPlanetIndex);
    if (offset < (5.0f * 5.0f)) {
//        if(spriteLevel->boundingBox().containsPoint(pTouch->getLocation())){
//            if(p_info->maxlevel_flag[config->CurPlanetIndex]!=0){
//                CCScene* scene = CCScene::create();
//                Select2Layer* layer = Select2Layer::create();
//                scene->addChild(layer);
//                CCDirector::sharedDirector()->replaceScene(scene);
//            }
//        }
    }
    
}

void HeroSelectContentLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

int HeroSelectContentLayer::getUserTag(){
    return mUserTag;
}

int HeroSelectContentLayer::setUserTag(int userTag){
    mUserTag = userTag;
}

//

