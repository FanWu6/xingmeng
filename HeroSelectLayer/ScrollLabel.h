//
//  ScrollLabel.h
//  hello
//
//  Created by 吴凡 on 14-5-26.
//
//

#ifndef __hello__ScrollLabel__
#define __hello__ScrollLabel__


#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


#define POINTER_OPERATION( pointer, operation ) \
do\
{\
    if( pointer )\
    {\
        operation;\
    }\
}while( 0 )

//the anchor point of XJScrollLabel is the left-bottom corner.
class XJScrollLabel : public CCNode, public CCScrollViewDelegate
{
public://static functions
    static XJScrollLabel* create( const char* pszText, const char *fontName, float fontSize, CCTextAlignment hAlignment, CCSize ScrollViewSize,float LabelDementionsX );
    
public:
    XJScrollLabel();
    ~XJScrollLabel();
    bool init( const char* pszText, const char *fontName, float fontSize, CCTextAlignment hAlignment, CCSize& ScrollViewSize,float LabelDementionsX );
    
    void setTextColor(const ccColor3B& color3)
    { POINTER_OPERATION( m_pLabel, m_pLabel->setColor( color3 ) ); }
    
    void infoSetstring(const char *str);
    
public://scroll view delegate
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
private:
    CCScrollView* m_pScrollView;
    CCLabelTTF* m_pLabel;
};


#endif /* defined(__hello__ScrollLabel__) */
