// HidMon_ng.h : main header file for the HIDMON_NG application
//

#if !defined(AFX_HIDMON_NG_H__A212ADBB_107E_4239_8048_C2730320828A__INCLUDED_)
#define AFX_HIDMON_NG_H__A212ADBB_107E_4239_8048_C2730320828A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHidMon_ngApp:
// See HidMon_ng.cpp for the implementation of this class
//

class CHidMon_ngApp : public CWinApp
{
public:
	CHidMon_ngApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHidMon_ngApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHidMon_ngApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDMON_NG_H__A212ADBB_107E_4239_8048_C2730320828A__INCLUDED_)
