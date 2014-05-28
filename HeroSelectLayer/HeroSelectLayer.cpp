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
    changeData();

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
    //
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("heroSelect.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("headPic.plist");

    //灵魂石层
    _sstiao = CCTextureCache::sharedTextureCache()->addImage("soulstonetiao1.png");
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
    CCSprite *addstone = (CCSprite *)node->getChildByTag(104);
    CCSprite *soulstone = (CCSprite *)node->getChildByTag(106);
    CCSprite *jinjie = (CCSprite *)node->getChildByTag(109);
    CCSprite *xxjineng = (CCSprite *)node->getChildByTag(112);
    CCSprite *xxshuxing = (CCSprite *)node->getChildByTag(113);
    if(soulstone->boundingBox().containsPoint(h_TouchDownPoint)){
        CCLOG("灵魂石获取途径-------");
        HeroSSpathLayer* _sspath = HeroSSpathLayer::create();
        this->addChild(_sspath);
        
    }else if(addstone->boundingBox().containsPoint(h_TouchDownPoint)){
        CCLOG("增加灵魂石-------");
    if((_pinfo->player_vec[config->heroPage].stone_rate)<(attack_data[config->heroPage]._heroStone+20*(_pinfo->player_vec[config->heroPage].hero_level-1))){
        _pinfo->player_vec[config->heroPage].stone_rate +=1;
        }
    }else if(jinjie->boundingBox().containsPoint(h_TouchDownPoint)){
        CCLOG("进阶&招募界面-------");
        if(_pinfo->player_vec[config->heroPage].isOwned){
        HeroJJLayer* _jjlayer = HeroJJLayer::create();
        this->addChild(_jjlayer);
        }else{
            _pinfo->player_vec[config->heroPage].isOwned = true;
            CCSprite *herospr = (CCSprite *)scroll->getChildByTag(config->heroPage)->getChildByTag(40+config->heroPage);
            herospr->setColor(ccc3(255,255,255));
        }
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
            isbutton = false;
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
    isbutton = true;
    isSkillLayer=!isSkillLayer;
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
    
    //等级更新
    CCString *string_lvl;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_lvl= CCString::createWithFormat("%d", _pinfo->player_vec[config->heroPage].hero_level);
    }else {
        string_lvl = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *lvl = (CCLabelTTF *)node->getChildByTag(114);
    lvl->setString(string_lvl->getCString());
    
    //经验更新
    CCString *string_exp;
    int cur_exp = _pinfo->player_vec[config->heroPage].hero_exp;
    int lvlup_exp = 10*(_pinfo->player_vec[config->heroPage].hero_level)*(_pinfo->player_vec[config->heroPage].hero_level)+80;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_exp= CCString::createWithFormat("%d/%d",cur_exp,lvlup_exp);
    }else {
        string_exp = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *exp = (CCLabelTTF *)node->getChildByTag(115);
    exp->setString(string_exp->getCString());
    
    //灵魂石进阶更新
    stonelvlup();
    
    //星级更新
    for(int index = 116;index<126;index++){
        CCSprite *star = (CCSprite*)node->getChildByTag(index);
        star->setVisible(false);
    }
    for(int index = 116;index<116+_pinfo->player_vec[config->heroPage].star_level;index++){
        CCSprite *star = (CCSprite*)node->getChildByTag(index);
        star->setVisible(true);
    }
    //进阶&招募
     CCSprite *jinjie = (CCSprite *)node->getChildByTag(109);
    if(!_pinfo->player_vec[config->heroPage].isOwned){
        jinjie->initWithFile("zhaomu.png");
    }else{
        jinjie->initWithFile("jinjie.png");
    }
    
    //英雄介绍
    CCString *string_info;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_info= CCString::createWithFormat("%s", attack_data[config->heroPage]._heroInfo);
    }else {
        string_info = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *info = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(1);
    info->setString(string_info->getCString());
    
    //属性更新
    //-------HP
    CCString *string_hp;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_hp= CCString::createWithFormat("%d+", attack_data[config->heroPage]._init_hp);
    }else {
        string_hp = CCString::createWithFormat("%s", "???+");
    }
    CCLabelTTF *hp = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(2);
    hp->setString(string_hp->getCString());
    
    CCString *string_hp2;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_hp2= CCString::createWithFormat("%d", (attack_data[config->heroPage]._init_hp)*(int)(attack_data[config->heroPage]._hpAdrate)*(_pinfo->player_vec[config->heroPage].star_level));
    }else {
        string_hp2 = CCString::createWithFormat("%s", "???");
    }
    CCLabelTTF *hp2 = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(7);
    hp2->setPositionX(hp->getPositionX()+hp->getContentSize().width);
    hp2->setString(string_hp2->getCString());
    //------AP
    CCString *string_ap;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_ap = CCString::createWithFormat("%d+",attack_data[config->heroPage]._init_attack);
    }else {
        string_ap = CCString::createWithFormat("%s","???+");
    }
    CCLabelTTF *ap = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(3);
    ap->setString(string_ap->getCString());
    
    CCString *string_ap2;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_ap2 = CCString::createWithFormat("%d",(attack_data[config->heroPage]._init_attack)*(int)(attack_data[config->heroPage]._apAdrate)*(_pinfo->player_vec[config->heroPage].star_level));
    }else {
        string_ap2 = CCString::createWithFormat("%s","???");
    }
    CCLabelTTF *ap2 = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(8);
    ap2->setString(string_ap2->getCString());
    ap2->setPositionX(ap->getPositionX()+ap->getContentSize().width);
    
    //------ASP
    CCString *string_asp;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_asp = CCString::createWithFormat("%d",attack_data[config->heroPage]._attack_speed);
    }else {
        string_asp = CCString::createWithFormat("%s","???");
    }
    CCLabelTTF *asp = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(4);
    asp->setString(string_asp->getCString());
    
    //-----ADS
    CCString *string_ads;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_ads = CCString::createWithFormat("%d",attack_data[config->heroPage]._attack_range);
    }else {
        string_ads = CCString::createWithFormat("%s","???");
    }
    CCLabelTTF *ads = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(5);
    ads->setString(string_ads->getCString());
    
    //-----SP
    CCString *string_sp;
    if(_pinfo->player_vec[config->heroPage].isOwned){
        string_sp = CCString::createWithFormat("%d",attack_data[config->heroPage]._move_speed);
    }else {
        string_sp = CCString::createWithFormat("%s","???");
    }
    CCLabelTTF *sp = (CCLabelTTF *)node->getChildByTag(110)->getChildByTag(6);
    sp->setString(string_sp->getCString());
}

void HeroSelectLayer::stonelvlup(){
    CCSprite *sstiao = (CCSprite *)node->getChildByTag(108);
    float rate = ((float)(_pinfo->player_vec[config->heroPage].stone_rate)/(float)(attack_data[config->heroPage]._heroStone+20*(_pinfo->player_vec[config->heroPage].hero_level-1)) );
    sstiao->initWithTexture(_sstiao,CCRectMake(0, 0, rate*206 , 20));
    sstiao->setAnchorPoint(ccp(0,1));
}

