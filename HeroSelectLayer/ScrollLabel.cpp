//
//  ScrollLabel.cpp
//  hello
//
//  Created by 吴凡 on 14-5-26.
//
//

#include "ScrollLabel.h"

XJScrollLabel* XJScrollLabel::create(const char *pszText, const char *fontName, float fontSize, CCTextAlignment hAlignment, cocos2d::CCSize ScrollViewSize,float LabelDementionsX)
{
	XJScrollLabel* pScrollLabel = new XJScrollLabel;
	if( pScrollLabel && pScrollLabel->init( pszText, fontName, fontSize, hAlignment, ScrollViewSize,LabelDementionsX ) )
	{
		pScrollLabel->autorelease();
		return pScrollLabel;
	}
	else
	{
		CC_SAFE_DELETE( pScrollLabel );
		return NULL;
	}
}

XJScrollLabel::XJScrollLabel() :
m_pScrollView( NULL ),
m_pLabel( NULL )
{
	
}

XJScrollLabel::~XJScrollLabel()
{
	CC_SAFE_RELEASE_NULL( m_pLabel );
	CC_SAFE_RELEASE_NULL( m_pScrollView );
}

bool XJScrollLabel::init(const char *pszText, const char *fontName, float fontSize, CCTextAlignment hAlignment, cocos2d::CCSize& ScrollViewSize,float LabelDementionsX)
{
	//object has been initialized.
	if( m_pScrollView || m_pLabel )
	{
		return false;
	}
	
	//constraint the label's width, but not height.
//	m_pLabel = CCLabelTTF::create( pszText, fontName, fontSize, CCSizeMake( ScrollViewSize.width, 0 ), hAlignment );
    m_pLabel = CCLabelTTF::create( pszText, fontName, fontSize, CCSizeMake( LabelDementionsX, 0 ), hAlignment );
	m_pLabel->retain();
	
	//get the texture size
	CCSize TextSize = m_pLabel->getTexture()->getContentSize();
	
	//we have to invoke CCScrollView::create( ScrollViewSize ) instead of
	//CCScrollView::create( ScrollViewSize, m_pLabel ) to let the CCScrollView
	//create a default container for you.
	
	//It's because that the label may smaller than the view of
	//CCScrollView. If that is the condition, the label will be positioned
	//at the bottom of the View by CCScrollView.
	
	//Even though you can set the label at the top, but the behavior of
	//ScrollView always try to reposition it. So we must ensure the container
	//is larger than the View of CCScrollView.
	m_pScrollView = CCScrollView::create( ScrollViewSize );
	m_pScrollView->retain();
	m_pScrollView->setDelegate( this );
    m_pScrollView->setTouchPriority(-130);
	m_pScrollView->setDirection( kCCScrollViewDirectionVertical );
	
	//set the container size.
	//So we must ensure the conainer is larger than the View of CCScrollView.
	if( TextSize.height > ScrollViewSize.height )
	{
		m_pScrollView->setContentSize( TextSize );
		//make the left-top corner of container coincide with View's
		m_pScrollView->setContentOffset( ccp( 0, ScrollViewSize.height - TextSize.height ) );
	}
	else
	{
        m_pScrollView->setTouchEnabled(false);
		m_pScrollView->setContentSize( ScrollViewSize );
	}
	
	//put the label at the top of the container.
	m_pScrollView->addChild( m_pLabel );
	m_pLabel->ignoreAnchorPointForPosition( false );
	m_pLabel->setAnchorPoint( ccp( 0, 1 ) );
	m_pLabel->setPosition( ccp( 0, m_pScrollView->getContentSize().height ) );
	
    
	addChild( m_pScrollView );
	return true;
}

void XJScrollLabel::infoSetstring(const char *str){
    m_pLabel->setString(str);
}