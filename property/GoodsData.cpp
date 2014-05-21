//
//  GoodsData.cpp
//  GameDemo_box2d
//
//  Created by 吴凡 on 14-4-2.
//
//

#include "GoodsData.h"

/* 基础资源 */
GoodsRes::GoodsRes(){

}
GoodsRes::~GoodsRes(){

}

/* 卡牌 */
GoodsCards::GoodsCards(){

}
GoodsCards::~GoodsCards(){

}

/* 卡牌灵魂石 */
GoodsCardsStone::GoodsCardsStone(){

}
GoodsCardsStone::~GoodsCardsStone(){

}
/* 道具 */
GoodsProp::GoodsProp(){

}
GoodsProp::~GoodsProp(){

}

/* 宝箱 */
GoodsBox::GoodsBox(){

}
GoodsBox::~GoodsBox(){

}

/* 礼包 */
GoodsGift::GoodsGift(){

}
GoodsGift::~GoodsGift(){

}

/* 奖励 */
RewardCell::RewardCell(){
    
}
RewardCell::~RewardCell(){
    
}

/* 技能 */
SkillData::SkillData(){
    
    m_happenType = new CCArray();
    m_hurtType = new CCArray();
    m_effectType = new CCArray();
}
SkillData::~SkillData(){
    if (m_happenType) {
        m_happenType->release();
        m_happenType = NULL;
    }
    if (m_hurtType) {
        m_hurtType->release();
        m_hurtType = NULL;
    }
    if (m_effectType) {
        m_effectType->release();
        m_effectType = NULL;
    }
}
/* 大技能 */
BigSkillData::BigSkillData(){
    
    m_happenType = new CCArray();
    m_targetType = new CCArray();
    m_hurtType = new CCArray();
    m_effectType = new CCArray();
    
    m_happenType_now = new CCArray();
    m_targetType_now = new CCArray();
    m_hurtType_now = new CCArray();
    m_effectType_now = new CCArray();
}
BigSkillData::~BigSkillData(){
    
    if (m_happenType) {
        m_happenType->release();
        m_happenType = NULL;
    }
    if (m_targetType) {
        m_targetType->release();
        m_targetType = NULL;
    }
    if (m_hurtType) {
        m_hurtType->release();
        m_hurtType = NULL;
    }
    if (m_effectType) {
        m_effectType->release();
        m_effectType = NULL;
    }
    
    if (m_happenType_now) {
        m_happenType_now->release();
        m_happenType_now = NULL;
    }
    if (m_targetType_now) {
        m_targetType_now->release();
        m_targetType_now = NULL;
    }
    if (m_hurtType_now) {
        m_hurtType_now->release();
        m_hurtType_now = NULL;
    }
    if (m_effectType_now) {
        m_effectType_now->release();
        m_effectType_now = NULL;
    }
}

HappenTypeData::HappenTypeData(){
    m_cd = 0;
}
HappenTypeData::~HappenTypeData(){
    
}
TargetTypeData::TargetTypeData(){
    
}
TargetTypeData::~TargetTypeData(){
    
}
HurtTypeData::HurtTypeData(){
    
}
HurtTypeData::~HurtTypeData(){
    
}
EffectTypeData::EffectTypeData(){
    
}
EffectTypeData::~EffectTypeData(){
    
}




