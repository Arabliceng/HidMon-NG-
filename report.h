#if !defined(AFX_REPORT_H__62009C96_A997_4FD4_B3E2_1A5F0908203C__INCLUDED_)
#define AFX_REPORT_H__62009C96_A997_4FD4_B3E2_1A5F0908203C__INCLUDED_
#include "resource.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// report.h : header file
//
#define WM_KEY_HOOK (WM_USER + 100)
/////////////////////////////////////////////////////////////////////////////
// report dialog

class report : public CDialog
{
// Construction
public:
	report(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(log)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(log)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(log)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG


	CString GetKeyText(UINT vk);
virtual BOOL OnInitDialog();
	virtual void OnOK();
afx_msg  void OnButton1();
	 afx_msg void OnDestroy();
	  afx_msg LRESULT OnKeyHook(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOG_H__255E943E_D749_4CB3_8E2B_4CCC376A63E9__INCLUDED_)



