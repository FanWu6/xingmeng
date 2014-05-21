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
    initData();
    addsprite();
    changeData();
    return true;
}

void HeroSSpathLayer::initData(){
    //数据
    config->xmlread->readXmlbyFileBuff("xml/Card_Hero_Battle_Info.xml", &attack_data, NULL);
    
    curPage = 0;//当前页
    _pinfo = new Playerinfo();//用户数据
    //
}


void HeroSSpathLayer::addsprite(){
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hero_sspath.plist");
    CCSprite *back_s = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("back_s.png"));
    CCSprite *back_click_s = cocos2d::CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("back_click_s.png"));
    CCMenuItemSprite *back = CCMenuItemSprite::create(back_s, back_click_s,this,menu_selector(HeroSSpathLayer::backonClick));
    menu = CCMenu::create(back,NULL);
    menu->setPosition(ccp(396, 82));
    this->addChild(menu);
    menu->setZOrder(10);
}

void HeroSSpathLayer::backonClick(){
//    CCLOG("~~~~~~");
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

void HeroSSpathLayer::changeData(){
    //名字更新
    CCString *string_name;
    string_name= CCString::createWithFormat("%s", attack_data[config->heroPage].name);
    CCLabelTTF *name = (CCLabelTTF *)node->getChildByTag(1);
    name->setString(string_name->getCString());
    
    //头像更新
    CCString *string_head;
    string_head= CCString::createWithFormat("%s.png", attack_data[config->heroPage].nameStrId);
    CCSprite *headpic = (CCSprite *)node->getChildByTag(2);
    headpic->initWithFile(string_head->getCString());
    
    //灵魂石数量更新
    CCString *string_stone;
    string_stone = CCString::createWithFormat("(%d/%d)",_pinfo->player_vec[config->heroPage].stone_rate,attack_data[config->heroPage]._heroStone+20*(_pinfo->player_vec[config->heroPage].hero_level-1));
    CCLabelTTF *stone = (CCLabelTTF *)node->getChildByTag(12);
    stone->setString(string_stone->getCString());
    
    //途径资料
    CCString *path_planet1 = CCString::createWithFormat("失落的星球");
    CCString *path_planet2 = CCString::createWithFormat("高兴的星球");
    CCString *path_planet3 = CCString::createWithFormat("不失落的星球");
    CCString *path_planet4 = CCString::createWithFormat("坑爹的星球");
    
    CCString *path_type1 = CCString::createWithFormat("（普通）");
    CCString *path_type2 = CCString::createWithFormat("（精英）");
    //途径1更新
    CCLabelTTF *pathplante1 = (CCLabelTTF *)node->getChildByTag(3);
    switch (attack_data[config->heroPage]._stoneFind_FBplanet) {
        case 1:{pathplante1->setString(path_planet1->getCString());break;}
        case 2:{pathplante1->setString(path_planet2->getCString());break;}
        case 3:{pathplante1->setString(path_planet3->getCString());break;}
        case 4:{pathplante1->setString(path_planet4->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathtype1 = (CCLabelTTF *)node->getChildByTag(4);
    switch (attack_data[config->heroPage]._stoneFind_FBtype) {
        case 0:{pathtype1->setString(path_type1->getCString());break;}
        case 1:{pathtype1->setString(path_type2->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathFBnum1 = (CCLabelTTF *)node->getChildByTag(5);
    CCString *path_FBnum1 = CCString::createWithFormat("第%d小关",attack_data[config->heroPage]._stone_FBnumber);
    pathFBnum1->setString(path_FBnum1->getCString());
    
    //途径2更新
    CCLabelTTF *pathplante2 = (CCLabelTTF *)node->getChildByTag(6);
    switch (attack_data[config->heroPage]._stoneFind_FBplanet) {
        case 1:{pathplante2->setString(path_planet1->getCString());break;}
        case 2:{pathplante2->setString(path_planet2->getCString());break;}
        case 3:{pathplante2->setString(path_planet3->getCString());break;}
        case 4:{pathplante2->setString(path_planet4->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathtype2 = (CCLabelTTF *)node->getChildByTag(7);
    switch (attack_data[config->heroPage]._stoneFind_FBtype) {
        case 0:{pathtype2->setString(path_type1->getCString());break;}
        case 1:{pathtype2->setString(path_type2->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathFBnum2 = (CCLabelTTF *)node->getChildByTag(8);
    CCString *path_FBnum2 = CCString::createWithFormat("第%d小关",attack_data[config->heroPage]._stone_FBnumber);
    pathFBnum2->setString(path_FBnum2->getCString());
    
    //途径3更新
    CCLabelTTF *pathplante3 = (CCLabelTTF *)node->getChildByTag(9);
    switch (attack_data[config->heroPage]._stoneFind_FBplanet) {
        case 1:{pathplante3->setString(path_planet1->getCString());break;}
        case 2:{pathplante3->setString(path_planet2->getCString());break;}
        case 3:{pathplante3->setString(path_planet3->getCString());break;}
        case 4:{pathplante3->setString(path_planet4->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathtype3 = (CCLabelTTF *)node->getChildByTag(10);
    switch (attack_data[config->heroPage]._stoneFind_FBtype) {
        case 0:{pathtype3->setString(path_type1->getCString());break;}
        case 1:{pathtype3->setString(path_type2->getCString());break;}
        default:{break;}
    }
    CCLabelTTF *pathFBnum3 = (CCLabelTTF *)node->getChildByTag(11);
    CCString *path_FBnum3 = CCString::createWithFormat("第%d小关",attack_data[config->heroPage]._stone_FBnumber);
    pathFBnum3->setString(path_FBnum3->getCString());

}
