/************************************************************************
MBEditLook

Prog. : Lim Dong Hwan
Date  : 10.Sep.2007
Desc. : Editbox 컨트롤의 커스텀룩(Custom look) 클래스 입니다.
*************************************************************************/


#pragma once

#include "Mint.h"
#include "MEdit.h"
#include "MBitmapDrawer.h"



// namespace : mint3
namespace mint3
{


/*	MBEditLook
	프레임의 Look을 정의하는 클래스
*/
class MBEditLook : public MEditLook
{
// Member variables
private:
	// 프레임의 비트맵을 저장하는 변수 선언
	MBitmapRep			m_Bitmaps[ 3];			// Normal, Focused, Disabled

	// 비트맵 그리기 스타일 변수
	MDRAWBITMAPSTYLE	m_BitmapStyle;

	// 비트맵 이미지를 타일형으로 찍는지 여부를 저장하는 변수
	bool				m_bTiled;

	// 커스텀 Look을 사용하는지 여부를 설정하는 변수
	bool				m_bCustomLook;

	// 폰트를 지정하는 변수
	MFont*				m_pFont;

	// 텍스트 색상을 저장하는 변수
	MCOLOR				m_colorFont[ 3];



// Member functions
public:
	// 생성자
	MBEditLook();

	// 소멸자
	virtual ~MBEditLook();



	// 커스텀 Look을 사용하는지 여부를 설정하는 함수
	void SetCustomLook( bool bCustom =true)		{ m_bCustomLook = bCustom;			}

	// 커스텀 Look을 사용하는지 여부를 구하는 함수
	bool IsCustomLook() const						{ return m_bCustomLook;				}



	/* Interface functions */

	// 프레임에 사용될 이미지를 설정하는 함수
	void SetBitmap( const string strFileName);

	// 프레임에 사용될 비트맵의 영역을 설정하는 함수
	void SetAssignRect( int state, int index, float x1, float y1, float x2, float y2);

	// 비트맵을 늘려 찍을 수 있게 설정하는 함수
	void SetStretchBlt( bool bStretch =true);

	// 타일 비트맵을 사용하는지 여부를 설정하는 함수
	void SetTiled( bool bTiled)					{ m_bTiled = bTiled;				}

	// 텍스트 폰트를 설정하는 함수
	void SetFont( MFont* pFont)						{ m_pFont = pFont;					}

	// 텍스트 색상을 설정하는 함수
	void SetFontColor( int state, MCOLOR& color)	{ m_colorFont[ state] = color;		}



protected:
	// 프레임을 그리는 함수
	virtual void OnFrameDraw( MEdit* pEdit, MDrawContext* pDC);

	// 텍스트를 그리는 함수
	virtual void OnTextDraw( MEdit* pEdit, MDrawContext* pDC, bool bShowLanguageTab);

	// 클라이언트의 영역을 구하는 함수(텍스트를 입력하는 공간)
	virtual MRECT GetClientRect(MEdit* pEdit, MRECT& r);
};


} // namespace mint3











/*****************************************************************

여기서부터는 이전 코드입니다


#pragma once

#include "MEdit.h"

namespace mint3 {

class MBEditLook : public MEditLook{
public:
	MBitmap*	m_pFrameBitmaps[9];
	MFont*		m_pFont;
	

public:
	MBEditLook(void);

	virtual void OnFrameDraw(MEdit* pEdit, MDrawContext* pDC);
	virtual MRECT GetClientRect(MEdit* pEdit, MRECT& r);
	virtual void OnDraw(MEdit* pEdit, MDrawContext* pDC);
};

} // namespace mint3
*/