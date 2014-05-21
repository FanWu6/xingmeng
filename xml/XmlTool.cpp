//
//  XmlTool.cpp
//  GameDemo
//
//  Created by 吴凡 on 13-7-9.
//
//

#include "XmlTool.h"

EasyXmlTool::EasyXmlTool()
{
    
}
EasyXmlTool::~EasyXmlTool()
{
    
}
void EasyXmlTool::initNow(BattleDefenseXmlDataBase *database,CCSize *unit){
    
    database->_now_level = database->_init_level;
//    database->_now_attack = database->_init_attack+database->_attack_growth*database->_now_level;
//    database->_now_hp = database->_init_hp+database->_hp_growth*database->_now_level;
//    database->_now_hp_limit = database->_now_hp;
//    database->_now_attack_limit = database->_now_attack;
//    
//    database->_now_move_speed = database->_move_speed * unit->width;
//    database->_now_attack_range = database->_attack_range * unit->width;
//    database->_now_no_attack_range = 0;//database->_no_attack_range * unit->width;
    
}
void EasyXmlTool::initNow(BattleAttackXmlDataBase *database,CCSize *unit){
    
    database->_now_level = database->_init_level;
//    database->_now_attack = database->_init_attack+database->_attack_growth*database->_now_level;
//    database->_now_hp = database->_init_hp+database->_hp_growth*database->_now_level;
//    database->_now_hp_limit = database->_now_hp;
//    database->_now_attack_limit = database->_now_attack;
//    
//    database->_now_move_speed = database->_move_speed * unit->width;
//    database->_now_attack_range = database->_attack_range * unit->width;
//    database->_now_no_attack_range = 0;//database->_no_attack_range * unit->width;
}

void EasyXmlTool::writeBuildXmlToFile(const char* FileName)
{
    TiXmlDocument *saveDoc = new TiXmlDocument();
    TiXmlElement *RootElement = new TiXmlElement("buildings");
    saveDoc->LinkEndChild(RootElement);
    TiXmlElement *buildingElement = new TiXmlElement("building");
    RootElement->LinkEndChild(buildingElement);
    buildingElement->SetAttribute("type", "3");
    /*
     TiXmlElement *buildingElement = new TiXmlElement("building");
     RootElement->LinkEndChild(buildingElement);
     buildingElement->SetAttribute("type", "3");
     */
    TiXmlElement *levelElement = new TiXmlElement("level");
    TiXmlElement *idElement = new TiXmlElement("id");
    TiXmlElement *nameElement = new TiXmlElement("name");
    buildingElement->LinkEndChild(levelElement);
    buildingElement->LinkEndChild(idElement);
    buildingElement->LinkEndChild(nameElement);
    
    TiXmlText *levelContent = new TiXmlText("1");
    TiXmlText *idContent = new TiXmlText("1");
    TiXmlText *nameContent = new TiXmlText("火塔");
    levelElement->LinkEndChild(levelContent);
    idElement->LinkEndChild(idContent);
    nameElement->LinkEndChild(nameContent);
    
    saveDoc->SaveFile(FileName);
    
}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<MonsterExploreXmlDataBase> *v)
//{
//    CCLOG("#######read %s #########",FileName);
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        
//        TiXmlElement* event = rootElement->FirstChildElement();
//        while (event) {
//            TiXmlAttribute* heroAttribute = event->FirstAttribute();
//            MonsterExploreXmlDataBase data;
//            memset(&data,0, sizeof(data));
//            while (heroAttribute) {
//                if (strcmp(heroAttribute->Name(), "event_id")==0){
//                    data.event_id = heroAttribute->IntValue();
//                }else if (strcmp(heroAttribute->Name(), "event_type")==0) {
//                    //                    strcpy(data->_DNA_pic, heroAttribute->Value());
//                    data.event_type = heroAttribute->IntValue();
//                }else if (strcmp(heroAttribute->Name(), "event_name")==0) {
//                    strcpy(data.event_name, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "orientation")==0) {
//                    data.event_orientation = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "nameStrId")==0) {
//                    strcpy(data.event_nameStrId, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "effectStrId")==0) {
//                    strcpy(data.event_effectStrId, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_type")==0) {
//                    data.s_type = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_icon")==0) {
//                    strcpy(data.s_iconStr, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_info")==0) {
//                    strcpy(data.s_infoStr, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_life")==0) {
//                    data.s_life = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_cost")==0) {
//                    data.s_cost = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_team")==0) {
//                    data.s_team = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "reward_id")==0) {
//                    data.event_reward_id = heroAttribute->IntValue();
//                    
//                }
//                
//                
//                heroAttribute = heroAttribute->Next();//移动到下一个属性
//            }
//            v->push_back(data);
//            event = event->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<armyFightData> *v)
//{
//    CCLOG("#######armyFightData#########");
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        
//        TiXmlElement* armying = rootElement->FirstChildElement();
//        while (armying) {
//            TiXmlAttribute* armyingType = armying->FirstAttribute();
//            armyFightData data;
//            memset(&data,0, sizeof(data));
//            while (armyingType) {
//                const char* type = armyingType->Name();//获取属性的名字
//                if (strcmp(type, "type")==0) {
//                    //如果属性名字为"type"
//                    int type1 = armyingType->IntValue();
//                    data.armytype = type1;
//                    if (type1 == 3) {
//                        
//                    }else if (type1 == 2){
//                        
//                    }else if (type1 == 1){
//                        TiXmlElement* star = armying->FirstChildElement();
//                        
//                        while (star) {
//                            TiXmlAttribute* starAttribute = star->FirstAttribute();
//                            while ( starAttribute ) {
//                                CCLOG("%s : %s",starAttribute->Name(),starAttribute->Value());
//                                if (strcmp(starAttribute->Name(), "name")==0) {
//                                    strcpy(data.name, starAttribute->Value());
//                                }else if (strcmp(starAttribute->Name(), "level")==0){
//                                    data.armyStarlevel = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "id")==0){
//                                    data.armyCardId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "skillid")==0){
//                                    data.armySkillId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "orientation")==0){
//                                    data.armyOrientation = starAttribute->IntValue();//1:向左 2:向右
//                                }else if (strcmp(starAttribute->Name(), "nameStrId")==0){
//                                    strcpy(data.name_strId, starAttribute->Value());
//                                }
//                                
//                                starAttribute = starAttribute->Next();
//                            }
//                            TiXmlElement* armyDate = star->FirstChildElement();
//                            int i=0;
//                            while (armyDate) {
//                                //CCLOG("%s : %s",armyDate->Value(),armyDate->GetText());
//                                
//                                switch(i)
//                                {
//                                    case ENUMLeaderShip:
//                                        data.LeaderShip = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMUpperLimit:
//                                        data.UpperLimit = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMExp:
//                                        data.Exp = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMmergeExp:
//                                        data.mergeExp = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMEnergyBase:
//                                        data.EnergyBase = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        data.EnergyAdd = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMEnergyType:
//                                        data.EnergyType = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMHpBase:
//                                        data.HpBase = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMHpAdd:
//                                        data.HpAdd = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMATKBase:
//                                        data.ATKBase = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMATKAdd:
//                                        data.ATKAdd = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMASPDBase:
//                                        data.ASPDBase = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMARNGBase:
//                                        data.ARNGBase = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMMove:
//                                        data.Move = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        data.CoverAreaBuff = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMAttackType:
//                                        data.AttackType = atoi(armyDate->GetText());
//                                        break;
//                                    case ENUMHighOffset:
//                                        data.HighOffset = atoi(armyDate->GetText());
//                                        break;
//                                    default:
//                                        break;
//                                }
//                                i++;
//                                
//                                armyDate = armyDate->NextSiblingElement();
//                            }
//                            v->push_back(data);
//                            star=star->NextSiblingElement();
//                        }
//                    }
//                }
//                armyingType = armyingType->Next();//移动到下一个属性
//            }
//            
//            armying = armying->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<buildFightData> *v)
//{
//    CCLOG("#######buildFightData#########");
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        
//        TiXmlElement* building = rootElement->FirstChildElement();
//        while (building) {
//            TiXmlAttribute* buildingType = building->FirstAttribute();
//            buildFightData data;
//            memset(&data,0, sizeof(data));
//            while (buildingType) {
//                const char* type = buildingType->Name();//获取属性的名字
//                if (strcmp(type, "type")==0) {
//                    //如果属性名字为"type"
//                    int type1 = buildingType->IntValue();
//                    data.buildtype = type1;
//                    if (type1 == 1) {
//                        TiXmlElement* star = building->FirstChildElement();
//                        
//                        while (star) {
//                            TiXmlAttribute* starAttribute = star->FirstAttribute();
//                            while ( starAttribute ) {
//                                CCLOG("%s : %s",starAttribute->Name(),starAttribute->Value());
//                                if (strcmp(starAttribute->Name(), "name")==0) {
//                                    strcpy(data.name, starAttribute->Value());
//                                }else if (strcmp(starAttribute->Name(), "level")==0){
//                                    data.buildStarlevel = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "id")==0){
//                                    data.buildCardId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "skillid")==0){
//                                    data.buildSkillId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "orientation")==0){
//                                    data.buildOrientation = starAttribute->IntValue();//1:向左 2:向右
//                                }else if (strcmp(starAttribute->Name(), "nameStrId")==0){
//                                    strcpy(data.name_strId, starAttribute->Value());
//                                }
//                                
//                                starAttribute = starAttribute->Next();
//                            }
//                            TiXmlElement* buildDate = star->FirstChildElement();
//                            int i=0;
//                            while (buildDate) {
//                                //CCLOG("%s : %s",buildDate->Value(),buildDate->GetText());
//                                
//                                switch(i)
//                                {
//                                    case ENUMLeaderShip:
//                                        data.LeaderShip = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMUpperLimit:
//                                        data.UpperLimit = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMExp:
//                                        data.Exp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMmergeExp:
//                                        data.mergeExp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyBase:
//                                        data.EnergyBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        data.EnergyAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyType:
//                                        data.EnergyType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpBase:
//                                        data.HpBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpAdd:
//                                        data.HpAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKBase:
//                                        data.ATKBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKAdd:
//                                        data.ATKAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMASPDBase:
//                                        data.ASPDBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMARNGBase:
//                                        data.ARNGBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMMove:
//                                        data.Move = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        data.CoverAreaBuff = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMAttackType:
//                                        data.AttackType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHighOffset:
//                                        data.HighOffset = atoi(buildDate->GetText());
//                                        break;
//                                    default:
//                                        break;
//                                }
//                                i++;
//                                
//                                buildDate = buildDate->NextSiblingElement();
//                            }
//                            
//                            for (int ttt=0; ttt<ENUM_DATA_XML_END; ttt++) {
//                                switch(ttt)
//                                {
//                                    case ENUMLeaderShip:
//                                        CCLOG("LeaderShip = %d",data.LeaderShip);
//                                        break;
//                                    case ENUMUpperLimit:
//                                        CCLOG("UpperLimit = %d",data.UpperLimit);
//                                        break;
//                                    case ENUMExp:
//                                        CCLOG("Exp = %d",data.Exp);
//                                        
//                                        break;
//                                    case ENUMmergeExp:
//                                        CCLOG("mergeExp = %d",data.mergeExp);
//                                        
//                                        break;
//                                    case ENUMEnergyBase:
//                                        CCLOG("EnergyBase = %d",data.EnergyBase);
//                                        
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        CCLOG("EnergyAdd = %d",data.EnergyAdd);
//                                        
//                                        break;
//                                    case ENUMEnergyType:
//                                        CCLOG("EnergyType = %d",data.EnergyType);
//                                        break;
//                                    case ENUMHpBase:
//                                        CCLOG("HpBase = %d",data.HpBase);
//                                        break;
//                                    case ENUMHpAdd:
//                                        CCLOG("HpAdd = %d",data.HpAdd);
//                                        break;
//                                    case ENUMATKBase:
//                                        CCLOG("ATKBase = %d",data.ATKBase);
//                                        break;
//                                    case ENUMATKAdd:
//                                        CCLOG("ATKAdd = %d",data.ATKAdd);
//                                        break;
//                                    case ENUMASPDBase:
//                                        CCLOG("ASPDBase = %d",data.ASPDBase);
//                                        break;
//                                    case ENUMARNGBase:
//                                        CCLOG("ARNGBase = %d",data.ARNGBase);
//                                        break;
//                                    case ENUMMove:
//                                        CCLOG("Move = %d",data.Move);
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        CCLOG("CoverAreaBuff = %d",data.CoverAreaBuff);
//                                        break;
//                                    case ENUMAttackType:
//                                        CCLOG("AttackType = %d",data.AttackType);
//                                        break;
//                                    case ENUMHighOffset:
//                                        CCLOG("HighOffset = %d",data.HighOffset);
//                                        break;
//                                    default:
//                                        break;
//                                }
//                            }
//                            v->push_back(data);
//                            star=star->NextSiblingElement();
//                        }
//                    }else if (type1 == 2){
//                        TiXmlElement* star = building->FirstChildElement();
//                        
//                        while (star) {
//                            TiXmlAttribute* starAttribute = star->FirstAttribute();
//                            while ( starAttribute ) {
//                                CCLOG("%s : %s",starAttribute->Name(),starAttribute->Value());
//                                if (strcmp(starAttribute->Name(), "name")==0) {
//                                    strcpy(data.name, starAttribute->Value());
//                                }else if (strcmp(starAttribute->Name(), "level")==0){
//                                    data.buildStarlevel = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "id")==0){
//                                    data.buildCardId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "skillid")==0){
//                                    data.buildSkillId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "orientation")==0){
//                                    data.buildOrientation = starAttribute->IntValue();//1:向左 2:向右
//                                }else if (strcmp(starAttribute->Name(), "nameStrId")==0){
//                                    strcpy(data.name_strId, starAttribute->Value());
//                                }
//                                
//                                starAttribute = starAttribute->Next();
//                            }
//                            TiXmlElement* buildDate = star->FirstChildElement();
//                            int i=0;
//                            while (buildDate) {
//                                //CCLOG("%s : %s",buildDate->Value(),buildDate->GetText());
//                                
//                                switch(i)
//                                {
//                                    case ENUMLeaderShip:
//                                        data.LeaderShip = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMUpperLimit:
//                                        data.UpperLimit = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMExp:
//                                        data.Exp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMmergeExp:
//                                        data.mergeExp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyBase:
//                                        data.EnergyBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        data.EnergyAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyType:
//                                        data.EnergyType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpBase:
//                                        data.HpBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpAdd:
//                                        data.HpAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKBase:
//                                        data.ATKBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKAdd:
//                                        data.ATKAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMASPDBase:
//                                        data.ASPDBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMARNGBase:
//                                        data.ARNGBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMMove:
//                                        data.Move = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        data.CoverAreaBuff = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMAttackType:
//                                        data.AttackType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHighOffset:
//                                        data.HighOffset = atoi(buildDate->GetText());
//                                        break;
//                                    default:
//                                        break;
//                                }
//                                i++;
//                                
//                                buildDate = buildDate->NextSiblingElement();
//                            }
//                            
//                            for (int ttt=0; ttt<ENUM_DATA_XML_END; ttt++) {
//                                switch(ttt)
//                                {
//                                    case ENUMLeaderShip:
//                                        CCLOG("LeaderShip = %d",data.LeaderShip);
//                                        break;
//                                    case ENUMUpperLimit:
//                                        CCLOG("UpperLimit = %d",data.UpperLimit);
//                                        break;
//                                    case ENUMExp:
//                                        CCLOG("Exp = %d",data.Exp);
//                                        
//                                        break;
//                                    case ENUMmergeExp:
//                                        CCLOG("mergeExp = %d",data.mergeExp);
//                                        
//                                        break;
//                                    case ENUMEnergyBase:
//                                        CCLOG("EnergyBase = %d",data.EnergyBase);
//                                        
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        CCLOG("EnergyAdd = %d",data.EnergyAdd);
//                                        
//                                        break;
//                                    case ENUMEnergyType:
//                                        CCLOG("EnergyType = %d",data.EnergyType);
//                                        break;
//                                    case ENUMHpBase:
//                                        CCLOG("HpBase = %d",data.HpBase);
//                                        break;
//                                    case ENUMHpAdd:
//                                        CCLOG("HpAdd = %d",data.HpAdd);
//                                        break;
//                                    case ENUMATKBase:
//                                        CCLOG("ATKBase = %d",data.ATKBase);
//                                        break;
//                                    case ENUMATKAdd:
//                                        CCLOG("ATKAdd = %d",data.ATKAdd);
//                                        break;
//                                    case ENUMASPDBase:
//                                        CCLOG("ASPDBase = %d",data.ASPDBase);
//                                        break;
//                                    case ENUMARNGBase:
//                                        CCLOG("ARNGBase = %d",data.ARNGBase);
//                                        break;
//                                    case ENUMMove:
//                                        CCLOG("Move = %d",data.Move);
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        CCLOG("CoverAreaBuff = %d",data.CoverAreaBuff);
//                                        break;
//                                    case ENUMAttackType:
//                                        CCLOG("AttackType = %d",data.AttackType);
//                                        break;
//                                    case ENUMHighOffset:
//                                        CCLOG("HighOffset = %d",data.HighOffset);
//                                        break;
//                                    default:
//                                        break;
//                                }
//                            }
//                            v->push_back(data);
//                            star=star->NextSiblingElement();
//                        }
//                    }else if (type1 == 3){
//                        TiXmlElement* star = building->FirstChildElement();
//                        
//                        while (star) {
//                            TiXmlAttribute* starAttribute = star->FirstAttribute();
//                            while ( starAttribute ) {
//                                CCLOG("%s : %s",starAttribute->Name(),starAttribute->Value());
//                                if (strcmp(starAttribute->Name(), "name")==0) {
//                                    strcpy(data.name, starAttribute->Value());
//                                }else if (strcmp(starAttribute->Name(), "level")==0){
//                                    data.buildStarlevel = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "id")==0){
//                                    data.buildCardId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "skillid")==0){
//                                    data.buildSkillId = starAttribute->IntValue();
//                                }else if (strcmp(starAttribute->Name(), "orientation")==0){
//                                    data.buildOrientation = starAttribute->IntValue();//1:向左 2:向右
//                                }else if (strcmp(starAttribute->Name(), "nameStrId")==0){
//                                    strcpy(data.name_strId, starAttribute->Value());
//                                }
//                                
//                                starAttribute = starAttribute->Next();
//                            }
//                            TiXmlElement* buildDate = star->FirstChildElement();
//                            int i=0;
//                            while (buildDate) {
//                                //CCLOG("%s : %s",buildDate->Value(),buildDate->GetText());
//                                
//                                switch(i)
//                                {
//                                    case ENUMLeaderShip:
//                                        data.LeaderShip = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMUpperLimit:
//                                        data.UpperLimit = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMExp:
//                                        data.Exp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMmergeExp:
//                                        data.mergeExp = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyBase:
//                                        data.EnergyBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        data.EnergyAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMEnergyType:
//                                        data.EnergyType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpBase:
//                                        data.HpBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHpAdd:
//                                        data.HpAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKBase:
//                                        data.ATKBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMATKAdd:
//                                        data.ATKAdd = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMASPDBase:
//                                        data.ASPDBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMARNGBase:
//                                        data.ARNGBase = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMMove:
//                                        data.Move = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        data.CoverAreaBuff = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMAttackType:
//                                        data.AttackType = atoi(buildDate->GetText());
//                                        break;
//                                    case ENUMHighOffset:
//                                        data.HighOffset = atoi(buildDate->GetText());
//                                        break;
//                                    default:
//                                        break;
//                                }
//                                i++;
//                                
//                                buildDate = buildDate->NextSiblingElement();
//                            }
//                            
//                            for (int ttt=0; ttt<ENUM_DATA_XML_END; ttt++) {
//                                switch(ttt)
//                                {
//                                    case ENUMLeaderShip:
//                                        CCLOG("LeaderShip = %d",data.LeaderShip);
//                                        break;
//                                    case ENUMUpperLimit:
//                                        CCLOG("UpperLimit = %d",data.UpperLimit);
//                                        break;
//                                    case ENUMExp:
//                                        CCLOG("Exp = %d",data.Exp);
//                                        
//                                        break;
//                                    case ENUMmergeExp:
//                                        CCLOG("mergeExp = %d",data.mergeExp);
//                                        
//                                        break;
//                                    case ENUMEnergyBase:
//                                        CCLOG("EnergyBase = %d",data.EnergyBase);
//                                        
//                                        break;
//                                    case ENUMEnergyAdd:
//                                        CCLOG("EnergyAdd = %d",data.EnergyAdd);
//                                        
//                                        break;
//                                    case ENUMEnergyType:
//                                        CCLOG("EnergyType = %d",data.EnergyType);
//                                        break;
//                                    case ENUMHpBase:
//                                        CCLOG("HpBase = %d",data.HpBase);
//                                        break;
//                                    case ENUMHpAdd:
//                                        CCLOG("HpAdd = %d",data.HpAdd);
//                                        break;
//                                    case ENUMATKBase:
//                                        CCLOG("ATKBase = %d",data.ATKBase);
//                                        break;
//                                    case ENUMATKAdd:
//                                        CCLOG("ATKAdd = %d",data.ATKAdd);
//                                        break;
//                                    case ENUMASPDBase:
//                                        CCLOG("ASPDBase = %d",data.ASPDBase);
//                                        break;
//                                    case ENUMARNGBase:
//                                        CCLOG("ARNGBase = %d",data.ARNGBase);
//                                        break;
//                                    case ENUMMove:
//                                        CCLOG("Move = %d",data.Move);
//                                        break;
//                                    case ENUMCoverAreaBuff:
//                                        CCLOG("CoverAreaBuff = %d",data.CoverAreaBuff);
//                                        break;
//                                    case ENUMAttackType:
//                                        CCLOG("CoverAreaBuff = %d",data.AttackType);
//                                        break;
//                                    case ENUMHighOffset:
//                                        CCLOG("HighOffset = %d",data.HighOffset);
//                                        break;
//                                    default:
//                                        break;
//                                }
//                            }
//                            v->push_back(data);
//                            star=star->NextSiblingElement();
//                        }
//                    }
//                }
//                buildingType = buildingType->Next();//移动到下一个属性
//            }
//            
//            building = building->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<BattleDefenseXmlDataBase> *v,CCSize *unit)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* hero = rootElement->FirstChildElement();
        while (hero) {
            TiXmlAttribute* heroAttribute = hero->FirstAttribute();
            BattleDefenseXmlDataBase data;
            memset(&data,0, sizeof(data));
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "id")==0){
                    data._OnlyId = heroAttribute->IntValue();
                    CCLOG("Defense id = %d",data._OnlyId);
                }else if (strcmp(heroAttribute->Name(), "big_pic")==0) {
                    strcpy(data._big_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "head_pic")==0) {
                    strcpy(data._head_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "DNA_pic")==0) {
                    strcpy(data._DNA_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "star")==0) {
                    data._star = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "nature")==0) {
                    //需要做一下性格的随即处理
                    data._nature = heroAttribute->IntValue();//0;//(int)(CCRANDOM_0_1()*10)%BATTLE_NATURE_COUNT;
                    
                }else if (strcmp(heroAttribute->Name(), "init_level")==0) {
                    data._init_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "max_level")==0) {
                    data._max_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "clone_cost")==0) {
                    data._clone_cost = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "init_attack")==0) {
                    data._init_attack = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_growth")==0) {
                    data._attack_growth = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "init_hp")==0) {
                    data._init_hp = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "hp_growth")==0) {
                    data._hp_growth = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_speed")==0) {
                    data._attack_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "move_speed")==0) {
                    data._move_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_range")==0) {
                    data._attack_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "no_attack_range")==0) {
                    data._no_attack_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_1")==0) {
                    data._skill_id_1 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_2")==0) {
                    data._skill_id_2 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_3")==0) {
                    data._skill_id_3 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_id")==0) {
                    data._big_skill_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_pic")==0) {
                    strcpy(data._big_skill_pic,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_CG")==0) {
                    strcpy(data._big_skill_CG, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "orientation")==0){
                    data._Orientation = heroAttribute->IntValue();//1:向左 2:向右
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data.name, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "nameStrId")==0){
                    strcpy(data.nameStrId, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "bulletName")==0){
                    strcpy(data.bulletName, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "comment")==0) {
                    strcpy(data._comment, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "box_x")==0) {
                    data.box_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_y")==0) {
                    data.box_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_w")==0) {
                    data.box_w = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_h")==0) {
                    data.box_h = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "norm_h")==0){
                    data.norm_h = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_speed")==0){
                    data._bullet_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_effectR")==0){
                    data._bullet_effectR = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_type")==0){
                    data._bullet_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "num_o_x")==0){
                    data.num_o_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "num_o_y")==0){
                    data.num_o_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_o_x")==0){
                    data.bullet_o_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_o_y")==0){
                    data.bullet_o_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_sound")==0){
                    //                    strcpy(data.sound_attack,heroAttribute->Value());
//                    char temp[40];
//                    WWCAT_EFFECT_PREFIX(temp, heroAttribute->Value());
//                    WWCAT_EFFECT_SUFFIX(data.sound_attack, temp);
                }else if (strcmp(heroAttribute->Name(), "dead_sound")==0){
                    //                    strcpy(data.sound_dead,heroAttribute->Value());
//                    char temp[40];
//                    WWCAT_EFFECT_PREFIX(temp, heroAttribute->Value());
//                    WWCAT_EFFECT_SUFFIX(data.sound_dead, temp);
                }
                
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            initNow(&data,unit);
            v->push_back(data);
            hero = hero->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<BattleAttackXmlDataBase> *v,CCSize *unit)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* hero = rootElement->FirstChildElement();
        while (hero) {
            TiXmlAttribute* heroAttribute = hero->FirstAttribute();
            BattleAttackXmlDataBase data;
            memset(&data,0, sizeof(data));
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "id")==0){
                    data._OnlyId = heroAttribute->IntValue();
//                    CCLOG("Attack id = %d",data._OnlyId);
                }else if (strcmp(heroAttribute->Name(), "big_pic")==0) {
                    strcpy(data._big_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "head_pic")==0) {
                    strcpy(data._head_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "DNA_pic")==0) {
                    strcpy(data._DNA_pic, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "star")==0) {
                    data._star = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "nature")==0) {
                    //需要做一下性格的随即处理
                    data._nature = heroAttribute->IntValue();//0;//(int)(CCRANDOM_0_1()*10)%BATTLE_NATURE_COUNT;
                    
                    
                    
                }else if (strcmp(heroAttribute->Name(), "init_level")==0) {
                    data._init_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "max_level")==0) {
                    data._max_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "clone_cost")==0) {
                    data._clone_cost = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "init_attack")==0) {
                    data._init_attack = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_growth")==0) {
                    data._attack_growth = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "init_hp")==0) {
                    data._init_hp = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "hp_growth")==0) {
                    data._hp_growth = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_speed")==0) {
                    data._attack_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "move_speed")==0) {
                    data._move_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_range")==0) {
                    data._attack_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "no_attack_range")==0) {
                    data._no_attack_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_1")==0) {
                    data._skill_id_1 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_2")==0) {
                    data._skill_id_2 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "skill_id_3")==0) {
                    data._skill_id_3 = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_id")==0) {
                    data._big_skill_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_pic")==0) {
                    strcpy(data._big_skill_pic,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "big_skill_CG")==0) {
                    strcpy(data._big_skill_CG, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "orientation")==0){
                    data._Orientation = heroAttribute->IntValue();//1:向左 2:向右
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data.name, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "nameStrId")==0){
                    strcpy(data.nameStrId, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "bulletName")==0){
                    strcpy(data.bulletName, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "comment")==0) {
                    strcpy(data._comment, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "box_x")==0) {
                    data.box_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_y")==0) {
                    data.box_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_w")==0) {
                    data.box_w = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "box_h")==0) {
                    data.box_h = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "norm_h")==0){
                    data.norm_h = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_speed")==0){
                    data._bullet_speed = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_effectR")==0){
                    data._bullet_effectR = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_type")==0){
                    data._bullet_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "num_o_x")==0){
                    data.num_o_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "num_o_y")==0){
                    data.num_o_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_o_x")==0){
                    data.bullet_o_x = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "bullet_o_y")==0){
                    data.bullet_o_y = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "attack_sound")==0){
//                    char temp[40];
//                    WWCAT_EFFECT_PREFIX(temp, heroAttribute->Value());
//                    WWCAT_EFFECT_SUFFIX(data.sound_attack, temp);
                    //                    strcpy(data.sound_attack,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "dead_sound")==0){
//                    char temp[40];
//                    WWCAT_EFFECT_PREFIX(temp, heroAttribute->Value());
//                    WWCAT_EFFECT_SUFFIX(data.sound_dead, temp);
                    //                    strcpy(data.sound_dead,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "heroInfo")==0) {
                    strcpy(data._heroInfo, heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "heroStone")==0){
                    data._heroStone = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "apAdvancedrate")==0){
                    data._apAdrate = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "hpAdvancedrate")==0){
                    data._hpAdrate = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "stoneFind_FBtype")==0){
                    data._stoneFind_FBtype = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "stoneFind_FBplanet")==0){
                    data._stoneFind_FBplanet = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "stone_FBnumber")==0){
                    data._stone_FBnumber = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            initNow(&data,unit);
            v->push_back(data);
            hero = hero->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<TeamIndexXmlDataBase> *v)
//{
//    CCLOG("#######read %s #########",FileName);
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        
//        TiXmlElement* hero = rootElement->FirstChildElement();
//        while (hero) {
//            TiXmlAttribute* heroAttribute = hero->FirstAttribute();
//            TeamIndexXmlDataBase data;
//            memset(&data,0, sizeof(data));
//            while (heroAttribute) {
//                
//                if (strcmp(heroAttribute->Name(), "name")==0) {
//                    strcpy(data.name, heroAttribute->Value());
//                }else if (strcmp(heroAttribute->Name(), "id")==0){
//                    data.teamId = heroAttribute->IntValue();
//                }else if (strcmp(heroAttribute->Name(), "team")==0){
//                    if (true) {
//                        int j=0;
//                        const char *d = "|";
//                        char _c[100];
//                        strcpy(_c, heroAttribute->Value());
//                        char *p;
//                        p = strtok(_c,d);
//                        while(p)
//                        {
//                            if (j<TEAM_MEMBER_MAX_COUNT_ONESIDE) {
//                                data.teamMember[j] = atoi(p);
//                            }
//                            p=strtok(NULL,d);
//                            j++;
//                        }
//                    }
//                }else if (strcmp(heroAttribute->Name(), "teamGrid")==0){
//                    if (true) {
//                        int j=0;
//                        const char *d = "|";
//                        char _c[100];
//                        strcpy(_c, heroAttribute->Value());
//                        char *p;
//                        p = strtok(_c,d);
//                        while(p)
//                        {
//                            if (j<TEAM_MEMBER_MAX_COUNT_ONESIDE) {
//                                data.teamGrid[j] = atoi(p);
//                            }
//                            p=strtok(NULL,d);
//                            j++;
//                        }
//                    }
//                }
//                
//                heroAttribute = heroAttribute->Next();//移动到下一个属性
//            }
//            v->push_back(data);
//            hero = hero->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<BattleBgXmlDataBase> *v){
//    CCLOG("#######read %s #########",FileName);
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        
//        TiXmlElement* hero = rootElement->FirstChildElement();
//        while (hero) {
//            TiXmlAttribute* heroAttribute = hero->FirstAttribute();
//            BattleBgXmlDataBase data;
//            memset(&data,0, sizeof(data));
//            while (heroAttribute) {
//                if (strcmp(heroAttribute->Name(), "id")==0){
//                    data._id = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "bg_pic")==0) {
//                    strcpy(data._bg_pic, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "bottom_padding_scale")==0) {
//                    data._bottomScale = heroAttribute->IntValue()/100.0f;
//                    
//                }else if (strcmp(heroAttribute->Name(), "top_padding_scale")==0) {
//                    data._topScale = heroAttribute->IntValue()/100.0f;
//                    
//                }else if (strcmp(heroAttribute->Name(), "left_padding_scale")==0) {
//                    data._leftScale = heroAttribute->IntValue()/100.0f;
//                    
//                }else if (strcmp(heroAttribute->Name(), "right_padding_scale")==0) {
//                    data._rightScale = heroAttribute->IntValue()/100.0f;
//                    
//                }
//                
//                heroAttribute = heroAttribute->Next();//移动到下一个属性
//            }
//            v->push_back(data);
//            hero = hero->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
//void EasyXmlTool::readXmlbyFileBuff(const char* FileName,vector<ExploreBgXmlDataBase> *v){
//    CCLOG("#######read %s #########",FileName);
//    TiXmlDocument* doc = new TiXmlDocument;
//    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
//    unsigned long size;
//    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
//    
//    if (pFileContent)
//    {
//        doc->Parse((const char*)pFileContent);
//        TiXmlElement* rootElement = doc->RootElement();//Root
//        if (rootElement==NULL) {
//            //CCLog("rootElement = null");
//        }
//        else
//        {
//            //CCLog("rootElement = %s",rootElement->Value());
//        }
//        /*
//         int _bg_id;
//         int _planet_id;
//         char _bg_pic[40];
//         char _planet_pic[40];
//         float _planet_x_scale;
//         float _planet_y_scale;
//         float _planet_offsetH;
//         float _planet_offsetA;
//         */
//        TiXmlElement* hero = rootElement->FirstChildElement();
//        while (hero) {
//            TiXmlAttribute* heroAttribute = hero->FirstAttribute();
//            ExploreBgXmlDataBase data;
//            memset(&data,0, sizeof(data));
//            while (heroAttribute) {
//                if (strcmp(heroAttribute->Name(), "bg_id")==0){
//                    data._bg_id = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_id")==0) {
//                    data._planet_id = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "bg_pic")==0) {
//                    strcpy(data._bg_pic, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_pic")==0) {
//                    strcpy(data._planet_pic, heroAttribute->Value());
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_x_scale")==0) {
//                    data._planet_x_scale = heroAttribute->IntValue()/100.0f;
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_y_scale")==0) {
//                    data._planet_y_scale = heroAttribute->IntValue()/100.0f;
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_offsetH")==0) {
//                    data._planet_offsetH = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_offsetA")==0) {
//                    data._planet_offsetA = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "planet_round")==0) {
//                    data._planet_round = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "round_times")==0) {
//                    data._round_times = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "n_event_p")==0) {
//                    data._n_event_p = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "n_event_list")==0) {
//                    if (true) {
//                        int j=0;
//                        const char *d = "|";
//                        char _c[300];
//                        strcpy(_c, heroAttribute->Value());
//                        char *p;
//                        p = strtok(_c,d);
//                        while(p)
//                        {
//                            if (j<EXPLORE_N_EVENT_MAX_NUM) {
//                                data._n_event_list[j] = atoi(p);
//                            }
//                            p=strtok(NULL,d);
//                            j++;
//                        }
//                    }
//                }else if (strcmp(heroAttribute->Name(), "s_event_p")==0) {
//                    data._s_event_p = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "s_event_list")==0) {
//                    if (true) {
//                        int j=0;
//                        const char *d = "|";
//                        char _c[300];
//                        strcpy(_c, heroAttribute->Value());
//                        char *p;
//                        p = strtok(_c,d);
//                        while(p)
//                        {
//                            if (j<EXPLORE_S_EVENT_MAX_NUM) {
//                                data._s_event_list[j] = atoi(p);
//                            }
//                            p=strtok(NULL,d);
//                            j++;
//                        }
//                    }
//                }else if (strcmp(heroAttribute->Name(), "dat_event_p")==0) {
//                    data._dat_event_p = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "o_h")==0) {
//                    data._event_offsetH = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "o_w")==0) {
//                    data._event_offsetW = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "o_a")==0) {
//                    data._event_offsetA = heroAttribute->IntValue();
//                    
//                }else if (strcmp(heroAttribute->Name(), "updataCD")==0){
//                    data._planet_updata_cd = heroAttribute->IntValue();
//                }
//                
//                heroAttribute = heroAttribute->Next();//移动到下一个属性
//            }
//            v->push_back(data);
//            hero = hero->NextSiblingElement();//移动到下一个兄弟Element
//            
//        }
//        delete  doc;
//        
//        
//    }
//    else
//    {
//        CCLog("pFileContent=null");
//    }
//}
void EasyXmlTool::readResXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsRes *data=new GoodsRes();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readCardsXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsCards *data=new GoodsCards();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "targetId")==0) {
                    data->m_targetId = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readCardsStoneXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsCardsStone *data=new GoodsCardsStone();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "targetId")==0) {
                    data->m_targetId = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "composeCount")==0) {
                    data->m_composeCount = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readPropXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsProp *data=new GoodsProp();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "add_exp")==0) {
                    data->m_add_exp = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "add_hp")==0) {
                    data->m_add_hp = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "add_atk")==0) {
                    data->m_add_atk = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readBoxXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsBox *data=new GoodsBox();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "keyId")==0) {
                    data->m_keyId = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "reward_id")==0) {
                    data->m_reward_id = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readGiftXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            GoodsGift *data = new GoodsGift();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "prop_id")==0){
                    data->m_prop_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "quality")==0) {
                    data->m_quality = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "fontColor")==0) {
                    data->m_fontColor = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "uselevel")==0) {
                    data->m_uselevel = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "sell_type")==0) {
                    data->m_sell_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "price")==0) {
                    data->m_price = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "life")==0) {
                    data->m_life = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "total")==0) {
                    data->m_total = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "reward_id")==0) {
                    data->m_reward_id = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readRewardXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            RewardCell *data = new RewardCell();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "reward_id")==0){
                    data->m_reward_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "type")==0) {
                    data->m_type = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "typenum")==0) {
                    data->m_typenum = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "prop_list1")==0) {
                    strcpy(data->m_prop_list1,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "prop_list2")==0) {
                    strcpy(data->m_prop_list2,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "prop_list3")==0) {
                    strcpy(data->m_prop_list3,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "prop_list4")==0) {
                    strcpy(data->m_prop_list4,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "prop_list5")==0) {
                    strcpy(data->m_prop_list5,heroAttribute->Value());
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}

void EasyXmlTool::readSkillXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            SkillData *data = new SkillData();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "id")==0){
                    data->m_skill_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "level")==0) {
                    data->m_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "range")==0) {
                    data->m_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "action")==0) {
                    strcpy(data->m_action,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "self_eff")==0) {
                    strcpy(data->m_self_eff,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "target_eff")==0) {
                    strcpy(data->m_target_eff,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "happenType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        CCLOG("%s",_c);
                        char *p;
                        p = strtok(_c,d);
                        
                        CCArray *_s = CCArray::create();
                        
                        while(p)
                        {
                            CCString *_str = CCString::createWithFormat("%s",p);
                            _s->addObject(_str);
                            p=strtok(NULL,d);
                            
                        }
                        
                        if (true) {
                            
                            int n = _s->count();
                            
                            for (int i=0; i<n; i++) {
                                char __c[30];
                                CCString *str = (CCString *)_s->objectAtIndex(i);
                                strcpy(__c, str->getCString());
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        flag=0;
                                        _pem2=atoi(_p);
                                        HappenTypeData *h=new HappenTypeData();
                                        h->m_happentype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        data->m_happenType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "hurtType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        char *p;
                        p = strtok(_c,d);
                        
                        while(p)
                        {
                            if (true) {
                                char __c[30];
                                strcpy(__c, p);
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        flag=0;
                                        _pem2=atoi(_p);
                                        HurtTypeData *h=new HurtTypeData();
                                        h->m_hurttype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        data->m_hurtType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                            p=strtok(NULL,d);
                            
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "effectType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        char *p;
                        p = strtok(_c,d);
                        
                        while(p)
                        {
                            if (true) {
                                char __c[30];
                                strcpy(__c, p);
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                int _pem3=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        _pem2=atoi(_p);
                                        
                                    }else if (flag==3){
                                        flag=0;
                                        _pem3=atoi(_p);
                                        EffectTypeData *h=new EffectTypeData();
                                        h->m_effecttype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        h->m_time = _pem3;
                                        data->m_effectType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                            p=strtok(NULL,d);
                            
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "skillType")==0){
                    data->m_skill_type = heroAttribute->IntValue();
                    
                }
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}
void EasyXmlTool::readBigSkillXmlbyFileBuff(const char* FileName,CCArray *v)
{
    CCLOG("#######read %s #########",FileName);
    TiXmlDocument* doc = new TiXmlDocument;
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(FileName);
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str() , "r", &size);
    
    if (pFileContent)
    {
        doc->Parse((const char*)pFileContent);
        TiXmlElement* rootElement = doc->RootElement();//Root
        if (rootElement==NULL) {
            //CCLog("rootElement = null");
        }
        else
        {
            //CCLog("rootElement = %s",rootElement->Value());
        }
        
        TiXmlElement* props = rootElement->FirstChildElement();
        while (props) {
            TiXmlAttribute* heroAttribute = props->FirstAttribute();
            BigSkillData *data = new BigSkillData();
            while (heroAttribute) {
                if (strcmp(heroAttribute->Name(), "id")==0){
                    data->m_skill_id = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "name")==0) {
                    strcpy(data->m_name,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "icon")==0) {
                    strcpy(data->m_icon,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "level")==0) {
                    data->m_level = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "range")==0) {
                    data->m_range = heroAttribute->IntValue();
                    
                }else if (strcmp(heroAttribute->Name(), "info")==0) {
                    strcpy(data->m_info,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "action")==0) {
                    strcpy(data->m_action,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "self_eff")==0) {
                    strcpy(data->m_self_eff,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "target_eff")==0) {
                    strcpy(data->m_target_eff,heroAttribute->Value());
                    
                }else if (strcmp(heroAttribute->Name(), "highlight_eff")==0){
                    
                    strcpy(data->m_highlight_eff, heroAttribute->Value());
                }else if (strcmp(heroAttribute->Name(), "slay_head_1")==0){
                    
                    strcpy(data->m_show_head_1, heroAttribute->Value());
                }else if (strcmp(heroAttribute->Name(), "slay_head_2")==0){
                    
                    strcpy(data->m_show_head_2, heroAttribute->Value());
                }else if (strcmp(heroAttribute->Name(), "slay_name_pic")==0){
                    
                    strcpy(data->m_name_pic, heroAttribute->Value());
                }else if (strcmp(heroAttribute->Name(), "highlight_time")==0){
                    
                    data->m_highlight_time = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "highlight_cd")==0){
                    
                    data->m_highlight_cd = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "scene_time")==0){
                    
                    data->m_scene_time = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "auto_fire_time")==0){
                    
                    data->m_auto_fire_time = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "happenType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        CCLOG("%s",_c);
                        char *p;
                        p = strtok(_c,d);
                        
                        CCArray *_s = CCArray::create();
                        
                        while(p)
                        {
                            CCString *_str = CCString::createWithFormat("%s",p);
                            _s->addObject(_str);
                            p=strtok(NULL,d);
                            
                        }
                        
                        if (true) {
                            
                            int n = _s->count();
                            
                            for (int i=0; i<n; i++) {
                                char __c[30];
                                CCString *str = (CCString *)_s->objectAtIndex(i);
                                strcpy(__c, str->getCString());
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        flag=0;
                                        _pem2=atoi(_p);
                                        HappenTypeData *h=new HappenTypeData();
                                        h->m_happentype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        data->m_happenType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "targetType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        char *p;
                        p = strtok(_c,d);
                        
                        while(p)
                        {
                            if (true) {
                                char __c[30];
                                strcpy(__c, p);
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        flag=0;
                                        _pem2=atoi(_p);
                                        TargetTypeData *h=new TargetTypeData();
                                        h->m_targettype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        data->m_targetType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                            p=strtok(NULL,d);
                            
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "hurtType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        char *p;
                        p = strtok(_c,d);
                        
                        while(p)
                        {
                            if (true) {
                                char __c[30];
                                strcpy(__c, p);
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        flag=0;
                                        _pem2=atoi(_p);
                                        HurtTypeData *h=new HurtTypeData();
                                        h->m_hurttype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        data->m_hurtType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                            p=strtok(NULL,d);
                            
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "effectType")==0){
                    if (true) {
                        const char *d = "|";
                        char _c[50];
                        strcpy(_c, heroAttribute->Value());
                        char *p;
                        p = strtok(_c,d);
                        
                        while(p)
                        {
                            if (true) {
                                char __c[30];
                                strcpy(__c, p);
                                const char *_d = ",";
                                char *_p;
                                int flag=0;
                                _p = strtok(__c,_d);
                                int _pem1=0;
                                int _pem2=0;
                                int _pem3=0;
                                while (_p) {
                                    
                                    flag++;
                                    CCLOG("--------%s",_p);
                                    if (flag==1) {
                                        _pem1=atoi(_p);
                                        
                                    }else if (flag==2){
                                        _pem2=atoi(_p);
                                        
                                    }else if (flag==3){
                                        flag=0;
                                        _pem3=atoi(_p);
                                        EffectTypeData *h=new EffectTypeData();
                                        h->m_effecttype_id = _pem1;
                                        h->m_parameter = _pem2;
                                        h->m_time = _pem3;
                                        data->m_effectType->addObject(h);
                                    }
                                    _p=strtok(NULL,_d);
                                }
                            }
                            p=strtok(NULL,d);
                            
                        }
                    }
                }else if (strcmp(heroAttribute->Name(), "cd_l")==0){
                    
                    data->m_cd_l = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "runType")==0){
                    
                    data->m_runType = heroAttribute->IntValue();
                }else if (strcmp(heroAttribute->Name(), "runTime")==0){
                    
                    data->m_runTime = heroAttribute->IntValue();
                }
                
                
                
                
                heroAttribute = heroAttribute->Next();//移动到下一个属性
            }
            
            v->addObject(data);
            props = props->NextSiblingElement();//移动到下一个兄弟Element
            
        }
        delete  doc;
        
        
    }
    else
    {
        CCLog("pFileContent=null");
    }
}




