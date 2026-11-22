// HidMon_ngDlg.h : header file
//
#include "KeyboardNotify.h" 
#if !defined(AFX_HIDMON_NGDLG_H__5B1110D0_D4CE_4FD5_9822_DF96713E53D9__INCLUDED_)
#define AFX_HIDMON_NGDLG_H__5B1110D0_D4CE_4FD5_9822_DF96713E53D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHidMon_ngDlg dialog

class CHidMon_ngDlg : public CDialog
{
// Construction
public:
	CHidMon_ngDlg(CWnd* pParent = NULL);	// standard constructor

HDESK  g_hDefaultDesktop;




CKeyboardNotify m_KeyboardNotify;


void CHidMon_ngDlg::investigatefun();

LRESULT	CHidMon_ngDlg::OnTaskbar(WPARAM wParam, LPARAM lParam);
void showmen();
HWND hw;
int c;


// Dialog Data
	//{{AFX_DATA(CHidMon_ngDlg)
	enum { IDD = IDD_HIDMON_NG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
afx_msg void settrayicon();
	
		afx_msg void mointor();
		afx_msg void showabout();
			afx_msg void blockhid();
					afx_msg void allowhid();
							afx_msg void showcommand();
									afx_msg void showlog();
									afx_msg void showwin();
									afx_msg void exitapp() ;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHidMon_ngDlg)

	virtual void DoDataExchange(CDataExchange* pDX);
	
	
	 BOOL CHidMon_ngDlg::IsRunAsAdmin();	
	
	
	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD dwData);
	// Generated message map functions
	//{{AFX_MSG(CHidMon_ngDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDMON_NGDLG_H__5B1110D0_D4CE_4FD5_9822_DF96713E53D9__INCLUDED_)
