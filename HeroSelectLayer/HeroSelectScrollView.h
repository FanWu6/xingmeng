//
//  HeroSelectScrollView.h
//  hello
//
//  Created by 吴凡 on 14-4-22.
//
//

#ifndef __hello__HeroSelectScrollView__
#define __hello__HeroSelectScrollView__

#include "cocos2d.h"
USING_NS_CC;

class HeroScrollView: public CCLayer
{
private:
    // 按下点
    CCPoint m_TouchDownPoint;
    // 抬起点 配合使用判断是否为点击事件
    CCPoint m_TouchUpPoint;
    // 当前触摸点
    CCPoint m_TouchCurPoint;
    
    
private:
    // 总页数
    int m_Page;
    // 当前显示页
    int m_CurPage;
    
public:
    // 存储所有页层
    CCArray *m_PageLayer;
    
private:
    // 跳转页
    void resetLevelScale();
public:
    //    ScrollView();
    //    ~ScrollView();
    
    virtual bool init();
    
    CREATE_FUNC(HeroScrollView);
    
public:
    // 初始化相关
    virtual void onEnter();
    virtual void onExit();
    
    // 触摸事件相关
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    //
    virtual void update(float dt);
public:
    // 添加页
    void addPage(CCLayer *pPageLayer);
    void goToPage();
    void backToPage();//返回关卡选择
    int Curpage;
    int getCurPage();
    
    void resetLevelPoint();
    
    bool isJudgment;
    bool iscurscale;
    float curscale;
    bool isleftScroll;
    
};

#endif /* defined(__hello__HeroSelectScrollView__) */
