//
//  HeroSelectLayer.cpp
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#include "HeroSelectLayer.h"
#include "HeroSelectccbi.h"
#include "VisibleRect.h"
#include "Config.h"
USING_NS_CC;
USING_NS_CC_EXT;

CCScene* HeroSelectLayer::scene(){
    CCScene* scene = CCScene::create();
    HeroSelectLayer* layer = HeroSelectLayer::create();
    scene->addChild(layer,-1);
    return scene;
}

bool HeroSelectLayer::init(){
    if ( !CCLayer::init() )
    {
        return false;
    }
    //设置成-1让它的层级降低这样就可以优先被触发
    //这样就会先执行touchbegain再执行tableCellHighlight
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, false);
    this->setTouchEnabled(true);
    this->setTouchPriority(-127);
    this->setTouchMode(kCCTouchesOneByOne);
    //加载cocosbuilder
    CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("HeroSelectccbi",HeroSelectccbiLoder::loader());
    /* Create an autorelease CCBReader. */
    CCBReader * ccbReader = new cocos2d::extension::CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    ccbReader->autorelease();
    /* Read a ccbi file. */
    node = ccbReader->readNodeGraphFromFile("ccbi/HeroSelectccbi.ccbi", this);
    if(node != NULL) {
        this->addChild(node);
    }
    initData();
    scheduleUpdate();
    addScroll();
    addSprite();

    return true;
}

void HeroSelectLayer::initData(){
    //数据
    config->xmlread->readXmlbyFileBuff("xml/Card_Hero_Battle_Info.xml", &attack_data, NULL);
    
    for(int i = 0;i<20;i++){//存储英雄ID
        curOnlyID[i] = -1;
    }
    curPage = 0;//当前页
    _pinfo = new Playerinfo();//用户数据
    //
    _skillLayer = HeroSkillLayer::create();
    this->addChild(_skillLayer);
//    _skillLayer = NULL;
    isSkillLayer = false;
    isbutton = true;

}


void HeroSelectLayer::addSprite(){
    //灵魂石层
    
    //
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("heroSelect.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("headPic.plist");
    //bg
    CCSprite* bg = CCSprite::create("bg.png");
    this->addChild(bg);
    bg->setZOrder(-10);
    bg->setPosition(ccp(400,240));
    //
    CCString *string;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string= CCString::createWithFormat("%s", attack_data[config->heroPage].name);
    }else {
        string = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *name = (CCLabelTTF *)node->getChildByTag(102);
    name->setString(string->getCString());
    
    
    
    
//    shuxingFrame = CButton::create();
//    shuxingFrame->setNormalSpriteFrameName("shuxing_frame.png");
//    shuxingFrame->setPosition(ccp(700,148));
//    shuxingFrame->setOnClickListener(this, ccw_click_selector(HeroSelectLayer::shuxingonClick));
//    shuxingFrame = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("shuxing_frame.png"));
//    shuxingFrame->setAnchorPoint(ccp(0.5,0.5));
//    shuxingFrame->setPosition(ccp(700,148));
//    CCOrbitCamera *c1 = CCOrbitCamera::create(2, 1, 0, 0, 180, 0, 0);
//    shuxingFrame->runAction(c1);
//    this->addChild(shuxingFrame,1);
}

//void HeroSelectContentLayer::shuxingonClick(CCObject* pSender){
//       CCFlipX3D* flipx  = CCFlipX3D::create(1);
//}

void HeroSelectLayer::addScroll(){
//    ClipLayer* clipLayer = ClipLayer::create(CCSizeMake(677*2,128));
    scroll= HeroScrollView::create();
    for(int i = 0;i<11;i++){
        layer = HeroSelectContentLayer::create();
        layer->setTag(i);
        layer->initSelectDate();
        curOnlyID[i] = layer->getUserTag();
        scroll->addPage(layer);
        //        scroll->goToPage();
    }
    //        scroll->goToPage();
    scroll->backToPage();
    this->addChild(scroll);

}

void HeroSelectLayer::changeData(){
// CCString *string = CCString::createWithFormat("%d", curOnlyID[config->heroPage]);
    //名字更新
    CCString *string_name;
    if(_pinfo->player_vec[config->heroPage].isOwned){
         string_name= CCString::createWithFormat("%s", attack_data[config->heroPage].name);
    }else {
        string_name = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *name = (CCLabelTTF *)node->getChildByTag(102);
    name->setString(string_name->getCString());
    //头像更新
    CCString *string_head;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_head= CCString::createWithFormat("%s.png", attack_data[config->heroPage].nameStrId);
    }else {
        string_head = CCString::createWithFormat("%s.png", "MMwolfman");
    }
    CCSprite *headpic = (CCSprite *)node->getChildByTag(101);
    headpic->initWithFile(string_head->getCString());

}

void HeroSelectLayer::onEnter(){
    CCLayer::onEnter();//有menu和CCTouch必须添加
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -129, false);
}

void HeroSelectLayer::onExit(){
//    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool HeroSelectLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCLOG("----");
    h_TouchDownPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    h_TouchCurPoint = h_TouchDownPoint;
    //灵魂石获取途径窗口
    CCSprite *soulstone = (CCSprite *)node->getChildByTag(106);
    CCSprite *jinjie = (CCSprite *)node->getChildByTag(109);
    CCSprite *xxjineng = (CCSprite *)node->getChildByTag(112);
    CCSprite *xxshuxing = (CCSprite *)node->getChildByTag(113);
    if(soulstone->boundingBox().containsPoint(h_TouchDownPoint)){
        CCLOG("灵魂石获取途径-------");
        HeroSSpathLayer* _sspath = HeroSSpathLayer::create();
        this->addChild(_sspath);
        
    }else if(jinjie->boundingBox().containsPoint(h_TouchDownPoint)){
        CCLOG("进阶界面-------");
        HeroJJLayer* _jjlayer = HeroJJLayer::create();
        this->addChild(_jjlayer);
    }else if(xxjineng->boundingBox().containsPoint(h_TouchDownPoint)&&isbutton&&!isSkillLayer){
        isbutton = false;
        CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
        
            sxAndjn->setScaleX(1);
            CCOrbitCamera *c1 = CCOrbitCamera::create(2, 1, 0, 0, 180, 0, 0);
            CCLOG("2");
        CCDelayTime *delay = CCDelayTime::create(1.35);
        CCCallFuncN * skillCallback = CCCallFuncN::create(this, callfuncN_selector(HeroSelectLayer::skillCallback));
        CCCallFuncN * setvisfalse = CCCallFuncN::create(this, callfuncN_selector(HeroSelectLayer::setVisFalse));
        sxAndjn->runAction(CCSequence::create(c1,skillCallback,NULL));
        sxAndjn->runAction(CCSequence::create(delay,setvisfalse,NULL));
        _skillLayer->reverseSkill();
        
    }else if(xxshuxing->boundingBox().containsPoint(h_TouchDownPoint)&&isbutton&&isSkillLayer){
        if(isSkillLayer){
            
            CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
            sxAndjn->setScaleX(-1);
            CCDelayTime *delay = CCDelayTime::create(1.35);
            CCOrbitCamera *c1 = CCOrbitCamera::create(2, 1, 0, 0, -180, 0, 0);
            CCLOG("1");
            CCCallFuncN * shuxingCallback = CCCallFuncN::create(this, callfuncN_selector(HeroSelectLayer::shuxingCallback));
             CCCallFuncN * setvistrue = CCCallFuncN::create(this, callfuncN_selector(HeroSelectLayer::setVisTrue));
            sxAndjn->runAction(CCSequence::create(c1,shuxingCallback,NULL));
            sxAndjn->runAction(CCSequence::create(delay,setvistrue,NULL));
            _skillLayer->reverseSkill();

        }
    }
    return true;
    //探索条件
}

void HeroSelectLayer::setVisTrue(){
    CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
    sxAndjn->setVisible(true);
}

void HeroSelectLayer::setVisFalse(){
    CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
    sxAndjn->setVisible(false);
}

void HeroSelectLayer::skillCallback(){
    isbutton = true;
//    CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
    isSkillLayer=!isSkillLayer;

    
//    sxAndjn->setScaleX(1);
//    CCSprite * sxAndjn = (CCSprite *)node->getChildByTag(110);
//    sxAndjn->setVisible(false);
//    isSkillLayer = true;
}

void HeroSelectLayer::shuxingCallback(){
    isSkillLayer = false;
}

void HeroSelectLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    
    h_TouchUpPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    float offset = (h_TouchUpPoint.x -h_TouchDownPoint.x) * (h_TouchUpPoint.x - h_TouchDownPoint.x);
    if (offset < (5.0f * 5.0f)) {
          }
    
    changeData();
}


void HeroSelectLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    // 移动
    CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    //    CCPoint posPoint = CCPointMake(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
    
    h_TouchCurPoint = touchPoint;
    
}

void HeroSelectLayer::update(float dt){
    if(curPage != config->heroPage){
        curPage = config->heroPage;
        changeData();
    }
    
}
