//
//  GoodsData.h
//  GameDemo_box2d
//
//  Created by 吴凡 on 14-4-2.
//
//

#ifndef __GameDemo_box2d__GoodsData__
#define __GameDemo_box2d__GoodsData__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

/* 基础资源 */
class GoodsRes :public CCObject
{
public:
    GoodsRes();
    ~GoodsRes();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
};

/* 卡牌 */
class GoodsCards :public CCObject
{
public:
    GoodsCards();
    ~GoodsCards();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
    int m_targetId;//卡牌物品对应的heroId
};

/* 卡牌灵魂石 */
class GoodsCardsStone :public CCObject
{
public:
    GoodsCardsStone();
    ~GoodsCardsStone();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
    int m_targetId;//卡牌物品对应的CardsId
    int m_composeCount;//合成卡牌需要的灵魂石数量
    
};

/* 道具 */
class GoodsProp :public CCObject
{
public:
    GoodsProp();
    ~GoodsProp();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
    int m_add_exp;//道具加成经验
    int m_add_hp;//道具加成血
    int m_add_atk;//道具加成攻击
    
    
};

/* 宝箱 */
class GoodsBox :public CCObject
{
public:
    GoodsBox();
    ~GoodsBox();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
    int m_keyId;//钥匙道具id
    int m_reward_id;//奖励id
};

/* 礼包 */
class GoodsGift :public CCObject
{
public:
    GoodsGift();
    ~GoodsGift();
    
public:
    int m_prop_id;//物品id
    char m_name[20];//物品名
    char m_icon[40];//图片资源名称
    int m_quality;//物品品质
    int m_fontColor;//物品字体颜色
    char m_info[20];//说明
    int m_uselevel;//可以使用的等级
    int m_sell_type;//售出类型
    int m_price;//售价
    int m_life;//持续时间 秒
    int m_total;//堆叠上限
    int m_reward_id;//奖励id
};

/* 奖励 */
class RewardCell :public CCObject
{
public:
    RewardCell();
    ~RewardCell();
    
public:
    int m_reward_id;//奖励id
    char m_name[80];//物品名
    int m_type;//类型
    char m_info[80];//说明
    int m_typenum;//奖励种类
    char m_prop_list1[20];//可获得物品列表 物品id|数量|获取概率
    char m_prop_list2[20];
    char m_prop_list3[20];
    char m_prop_list4[20];
    char m_prop_list5[20];
};

class SkillData :public CCObject
{
public:
    SkillData();
    ~SkillData();
    
public:
    int m_skill_id;//技能id
    char m_name[40];//技能名
    char m_icon[40];//图标资源名称
    int m_level;//技能等级
    int m_range;//技能范围
    char m_info[200];//技能描述
    char m_action[20];//对应人物的flash动画 动作名
    char m_self_eff[20];//释放技能时 自己身上的特效
    char m_target_eff[20];//释放技能时 目标身上的特效
    int m_skill_type;//技能类型 1:ai主动释放 2:被动释放
    
    CCArray *m_happenType;
    CCArray *m_hurtType;
    CCArray *m_effectType;
    
};

//xml读取出来的东西
class BigSkillData :public CCObject
{
public:
    BigSkillData();
    ~BigSkillData();
    
public:
    int m_skill_id;//技能id
    char m_name[40];//技能名
    char m_icon[40];//图标资源名称
    int m_level;//技能等级
    int m_range;//技能范围
    char m_info[200];//技能描述
    char m_action[20];//对应人物的flash动画 动作名
    char m_self_eff[20];//释放技能时 自己身上的特效
    char m_target_eff[20];//释放技能时 目标身上的特效
    
    int m_highlight_time;//大技能高亮持续时间 秒
    int m_highlight_cd;//大技能高亮间隔时间 秒
    int m_scene_time;//大招特效场景持续时间 秒
    int m_auto_fire_time;//大招自动触发时间 秒
    char m_highlight_eff[40];//点击高亮名
    char m_show_head_1[40];//大招场景特效人物头像
    char m_show_head_2[40];//大招场景特效人物头像
    char m_name_pic[40];//技能名艺术字
    
    int m_runType;//结算方式
    int m_runTime;//过程结算时长
    
    /*应用数值*/
    int m_cd_l;//技能cd等级增量 毫秒
    CCArray *m_happenType;
    CCArray *m_targetType;
    CCArray *m_hurtType;
    CCArray *m_effectType;
    
    
    //now 当前等级段位算换后的值
    CCArray *m_happenType_now;
    CCArray *m_targetType_now;
    CCArray *m_hurtType_now;
    CCArray *m_effectType_now;
};

class HappenTypeData :public CCObject
{
public:
    HappenTypeData();
    ~HappenTypeData();
    
public:
    int m_happentype_id;//触发类型id
    int m_parameter;//条件参数
    int m_cd;//毫秒 内置技能cd 0的时候表示可以释放 当m_happentype_id＝2的时候才起作用
    
};
class TargetTypeData :public CCObject
{
public:
    TargetTypeData();
    ~TargetTypeData();
    
public:
    int m_targettype_id;//触发类型id
    int m_parameter;//条件参数
    
};
class HurtTypeData :public CCObject
{
public:
    HurtTypeData();
    ~HurtTypeData();
    
public:
    int m_hurttype_id;//伤害类型id
    int m_parameter;//条件参数
    
};
class EffectTypeData :public CCObject
{
public:
    EffectTypeData();
    ~EffectTypeData();
    
public:
    int m_effecttype_id;//附加效果
    int m_parameter;//条件参数
    int m_time;//持续时间 秒
    
};




#endif /* defined(__GameDemo_box2d__GoodsData__) */
