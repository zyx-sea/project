// MP3.h : main header file for the MP3 application
//

#if !defined(AFX_MP3_H__F35C057D_B5FC_4880_A4C1_7B3AD282317D__INCLUDED_)
#define AFX_MP3_H__F35C057D_B5FC_4880_A4C1_7B3AD282317D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMP3App:
// See MP3.cpp for the implementation of this class
//

class CMP3App : public CWinApp
{
public:
	CMP3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMP3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3_H__F35C057D_B5FC_4880_A4C1_7B3AD282317D__INCLUDED_)
