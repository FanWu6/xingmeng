//
//  HeroSelectScrollView.cpp
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#include "HeroSelectScrollView.h"
#include "Config.h"
#include "VisibleRect.h"
const int TOUCH_INS = 5;

bool HeroScrollView::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        m_Page = 0;//总页数
        m_CurPage = 0;//当前显示页
        Curpage = 0;//将当前页传到上层
        m_PageLayer = CCArray::create();//页层
        m_PageLayer->retain();
        bRet = true;
    } while (0);
    CCLog("m_page=======%d",m_Page);
    CCLog("m_cur=======%d",m_CurPage);
    //    m_CurPage = config->currentLevel/6;
    this->setPosition(ccp(0,50));
    //
    this->setTouchEnabled(true);
    this->setTouchPriority(-127);
    this->setTouchMode(kCCTouchesOneByOne);
//    this->registerWithTouchDispatcher();
    //
    scheduleUpdate();
    return bRet;
}
//
void HeroScrollView::onEnter()
{
    CCLayer::onEnter();
    //    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -129, false);
}

void HeroScrollView::onExit()
{
//    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool HeroScrollView::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCRect touchrect =  CCRectMake(0, 283, 800, 127);
    m_TouchDownPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    m_TouchCurPoint = m_TouchDownPoint;
//    CCLOG("---touchx===%f",m_TouchCurPoint.x);
//    CCLOG("---touchy===%f",m_TouchCurPoint.y);
    if(touchrect.containsPoint(m_TouchDownPoint)){
        return true;
    }else{
        return false;
    }
}

void HeroScrollView::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    // 移动
    CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    CCPoint posPoint = CCPointMake(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
    setPosition(posPoint);
    //------移动时动态改变大小以及位置
//    for(int i = 0;i<11;i++){
//    CCPoint popos = this->convertToWorldSpace( ((CCLayer*) m_PageLayer->objectAtIndex(0))->getChildByTag(0 + 40)->getPosition());
//    float scale = 1-((fabsf(popos.x-400.0f)/400.0f)*(fabsf(popos.x-400.0f)/400.0f));
//        if(scale>0.5){
//    ((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40)->setScale(scale);
//        }
//    }

//    CCLOG("--x等于======%f",popos.x);
    //-----------
    m_TouchCurPoint = touchPoint;

}

void HeroScrollView::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    m_TouchUpPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    // 计算按下和抬起的偏移量
    float offset = (m_TouchUpPoint.x - m_TouchDownPoint.x) * (m_TouchUpPoint.x - m_TouchDownPoint.x);
    
    if (offset < (TOUCH_INS * TOUCH_INS)) {
        // 点击
        // 向子Layer发送Click消息
        //        ((CCLayer*) m_PageLayer->objectAtIndex(config->currentLevel/6))->ccTouchBegan(pTouch, pEvent);
    }
    else {
        // 滑动结束
        int offset =m_TouchUpPoint.x - m_TouchDownPoint.x; //偏移的距离
//        if (offset > 667 / 8) {
//            // 上一页
//            
//            if (m_CurPage > 0) {
//                --m_CurPage;
//            }
//        }
//        else if (offset < -667 / 8 ) {
//            // 下一页
//            if (m_CurPage < (m_Page - 1)) {
//                ++m_CurPage;
//            }
//        }
        CCPoint popos_begin = this->convertToWorldSpace( ((CCLayer*) m_PageLayer->objectAtIndex(0))->getChildByTag(0 + 40)->getPosition());
        CCPoint popos_last = this->convertToWorldSpace( ((CCLayer*) m_PageLayer->objectAtIndex(m_Page-1))->getChildByTag(m_Page-1 + 40)->getPosition());
        //如果翻过第一页，则返回第一页;翻过最后一页，则返回最后一页；否则停在哪页返回哪页
        if((popos_begin.x-400.0f)>0){
            m_CurPage = 0;
            
        }else if((popos_last.x-400.0f)<0){
            m_CurPage = m_Page -1;
            
        }else{
            for(int i =0;i<m_Page;i++){
                CCPoint popos = this->convertToWorldSpace( ((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40)->getPosition());
                float abs_instance = fabsf(popos.x-400.0f);
                if(abs_instance<667/7/2){
                    m_CurPage = i;
                    break;
                }
                
            }
        }
    
    
        //      储存当前关卡
        // 执行跳转动画
        goToPage();
        CCLOG("offset == %d , m_curpage==%d",offset,m_CurPage);
    }
}

void HeroScrollView::resetLevelScale(){
    //设置页面缩放
    
//    if(m_CurPage == 0){
//        ((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage + 1))->getChildByTag(m_CurPage + 40 + 1)->setScale(0.50f);
//    }else if(m_CurPage < 3){
//        ((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage - 1))->getChildByTag(m_CurPage + 40 - 1)->setScale(0.50f);
//        ((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage + 1))->getChildByTag(m_CurPage + 40 + 1)->setScale(0.50f);
//    }else if(m_CurPage == 3){
//        ((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage - 1))->getChildByTag(m_CurPage + 40 - 1)->setScale(0.50f);
//    }
}

void HeroScrollView::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

void HeroScrollView::goToPage()
{
    CCMoveTo *moveTo = CCMoveTo::create(0.2f, ccpAdd(VisibleRect::leftBottom(), ccp(-m_CurPage * (677/7) , 50)));
    
    this->runAction(moveTo);
    CCLOG("m_curpage==%d",m_CurPage);//
    resetLevelScale();
    config->heroPage = m_CurPage;
//    ((CCLayer*) m_PageLayer->objectAtIndex(m_CurPage))->getChildByTag(m_CurPage + 40)->setScale(1.0f);
}

void HeroScrollView::backToPage(){
    //返回
    int a = config->heroPage;
    m_CurPage = config->heroPage;
    //滑动位移
    int length = 50;
    CCMoveTo *moveTo = CCMoveTo::create(0.2f, ccpAdd(VisibleRect::leftBottom(), ccp(-(a) * (677/7 + length), 50)));
    this->runAction(moveTo);
    CCLOG("m_curpage==FFFFFFFFFFFFF%d",a);
    resetLevelScale();
//    ((CCLayer*) m_PageLayer->objectAtIndex(a))->getChildByTag(a + 40)->setScale(1.0f);
    
}

void HeroScrollView::addPage(cocos2d::CCLayer *pPageLayer)
{
    if (pPageLayer) {
        // 设置成一页大小
        pPageLayer->setContentSize(CCSizeMake(SCREEN_WIDTH, SCREEN_HEIGHT));
        
        pPageLayer->setPosition(ccpAdd(VisibleRect::leftBottom(), ccp( SCREEN_WIDTH * -m_CurPage, 0)));
        
        this->addChild(pPageLayer);
        // 添加到页
        m_PageLayer->addObject(pPageLayer);
        m_Page = m_PageLayer->count();
        
        CCLOG("m_page == %d",m_Page);
    }
}

int HeroScrollView::getCurPage(){
    return m_CurPage;
}

void HeroScrollView::update(float dt){
    for(int i = 0;i<m_Page;i++){
        CCPoint popos = this->convertToWorldSpace( ((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40)->getPosition());
        float scale = 1-((fabsf(popos.x-400.0f)/400.0f)*(fabsf(popos.x-400.0f)/400.0f));
            ((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40)->setScale(scale);
        ((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40)->setPositionY(240+(1-scale)*100);

        CCSprite *xx = (CCSprite *)((CCLayer*) m_PageLayer->objectAtIndex(i))->getChildByTag(i + 40);
        xx->setOpacity(255*scale);
    }
}