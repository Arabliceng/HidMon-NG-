// HidMon_ngDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HidMon_ng.h"
#include "HidMon_ngDlg.h"
#include "ttest.h"
#include <time.h>



#include <lmcons.h>

#include <atlbase.h>

#include <winbase.h>




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_TASKBAR  WM_APP+450
#ifndef BIF_NEWDIALOGSTYLE
#define BIF_NEWDIALOGSTYLE 0x0040
#endif
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
 void OnPaint();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	 ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

 void CAboutDlg::OnPaint()
{
    CPaintDC dc(this);

    CRect r;
    GetClientRect(&r);

    dc.FillSolidRect(&r, RGB(19, 27, 42));

    int y = 18;

    CFont font;
    CFont* oldFont;

    // TITLE
    font.CreateFont(
        30, 0, 0, 0, FW_BOLD,
        FALSE, FALSE, 0,
        ANSI_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        "Arial"
    );

    oldFont = dc.SelectObject(&font);

    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(RGB(0, 200, 255));

    dc.TextOut(20, y, "HidMon_ng");

    dc.SelectObject(oldFont);
    font.DeleteObject();

    y += 48;

    // SUBTITLE
    dc.SetTextColor(RGB(220, 230, 245));

    dc.TextOut(
        20, y,
        "HID Keyboard Monitoring & Management Utility"
    );

    y += 45;

    // OVERVIEW
    dc.SetTextColor(RGB(0, 200, 255));
    dc.TextOut(20, y, "OVERVIEW");

    y += 25;

    dc.SetTextColor(RGB(210, 220, 235));

    dc.TextOut(20, y,
        "Windows utility designed to manage and monitor");

    y += 20;

    dc.TextOut(20, y,
        "Human Interface Device (HID) keyboard devices.");

    y += 40;

    // KEY FEATURES
    dc.SetTextColor(RGB(0, 200, 255));
    dc.TextOut(20, y, "KEY FEATURES");

    y += 25;

    dc.SetTextColor(RGB(210, 220, 235));

    dc.TextOut(20, y,
        "- Real-time detection of connected HID keyboards.");

    y += 22;

    dc.TextOut(20, y,
        "- Monitoring newly connected keyboards.");

    y += 22;

    dc.TextOut(20, y,
        "- Detailed reporting and activity logging.");

    y += 40;

    // OPERATING MODES
    dc.SetTextColor(RGB(0, 200, 255));
    dc.TextOut(20, y, "OPERATING MODES");

    y += 25;

    dc.SetTextColor(RGB(255, 170, 60));
    dc.TextOut(20, y, "1. BLOCK MODE");

    y += 22;

    dc.SetTextColor(RGB(210, 220, 235));
    dc.TextOut(20, y,
        "Automatically blocks newly connected HID keyboards. need admin permisions");

    y += 35;


   dc.SetTextColor(RGB(255, 170, 60));
    dc.TextOut(20, y, "2. ALLOW MODE");

    y += 22;

    dc.SetTextColor(RGB(210, 220, 235));
    dc.TextOut(20, y,
        "Allow  newly connected HID keyboards.");

    y += 35;



    dc.SetTextColor(RGB(100, 220, 150));
    dc.TextOut(20, y, "3. INVESTIGATE MODE");

    y += 22;

    dc.SetTextColor(RGB(210, 220, 235));
    dc.TextOut(20, y,
        "Monitors keyboard-injected commands without");

    y += 20;

    dc.TextOut(20, y,
        "interfering with normal system operation.");

    y += 40;


 dc.SetTextColor(RGB(100, 220, 150));
    dc.TextOut(20, y, "4. MOINTOR MODE");

    y += 22;

    dc.SetTextColor(RGB(210, 220, 235));
    dc.TextOut(20, y,
        "Automatically Monitors newly connected HID keyboards");


    y += 20;
 dc.TextOut(20, y,
        "and show keyboard-injected commands without");

    y += 20;
    dc.TextOut(20, y,
        "interfering with normal system operation. need Admin permisions");

    y += 40;
   
    dc.TextOut(20, y, "REPORTS & LOGGING");

    y += 25;

    dc.SetTextColor(RGB(210, 220, 235));

    dc.TextOut(20, y, "- Export reports of blocked devices.");

    y += 22;

    dc.TextOut(20, y,
        "- Generate lists of detected keyboard-injected commands.");

    y += 40;

    // COPYRIGHT
    dc.SetTextColor(RGB(255, 190, 80));

    dc.TextOut(20, y,
        "Developed by Eng. Ahmad Kassem");

    y += 22;

    dc.SetTextColor(RGB(140, 160, 185));

    dc.TextOut(20, y,
        "Version 1.0");

    y += 20;

    dc.TextOut(20, y,
        "Copyright 2026 - All Rights Reserved");
}
/////////////////////////////////////////////////////////////////////////////
// CHidMon_ngDlg dialog

CHidMon_ngDlg::CHidMon_ngDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHidMon_ngDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHidMon_ngDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHidMon_ngDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHidMon_ngDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHidMon_ngDlg, CDialog)
	//{{AFX_MSG_MAP(CHidMon_ngDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_COMMAND(ID_SETTINGS_SHOWWINDOW,showwin)
				ON_COMMAND(ID_SETTINGS_ALLOW,allowhid)
				ON_COMMAND(ID_SETTINGS_ABOUT,showabout)
				ON_COMMAND(ID_SETTINGS_SHOWLOG,showlog)
                ON_COMMAND(ID_SETTINGS_INVESTIGATE,showcommand)
				ON_COMMAND(ID_SETTINGS_BLOCK1,blockhid)
				ON_COMMAND(ID_SETTINGS_MOINTOR,mointor)
				ON_COMMAND(ID_SETTINGS_EXIT,exitapp)
			ON_MESSAGE(WM_TASKBAR,OnTaskbar)

			ON_WM_DEVICECHANGE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHidMon_ngDlg message handlers











////////////////////////////////////
///////////////////////////////////
/////////////////////////////////////

 BOOL SaveLogFolder(CString folder)
{
    HKEY hKey;

    LONG result = RegCreateKeyEx(
        HKEY_CURRENT_USER,
        "Software\\HidMon-NG",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );

    if (result != ERROR_SUCCESS)
        return FALSE;

    result = RegSetValueEx(
        hKey,
        "LogFolder",
        0,
        REG_SZ,
        (BYTE*)(LPCTSTR)folder,
        (folder.GetLength() + 1) * sizeof(TCHAR)
    );

    RegCloseKey(hKey);

    return (result == ERROR_SUCCESS);
}


CString SelectLogFolder()
{
    BROWSEINFO bi;
    ZeroMemory(&bi, sizeof(bi));

    bi.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
    bi.lpszTitle = "Select folder for log files";
    bi.ulFlags = BIF_RETURNONLYFSDIRS |
                 BIF_NEWDIALOGSTYLE;

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

    if (pidl == NULL)
        return "";

    char path[MAX_PATH];

    BOOL result = SHGetPathFromIDList(pidl, path);

    IMalloc* pMalloc = NULL;

    if (SUCCEEDED(SHGetMalloc(&pMalloc)))
    {
        pMalloc->Free(pidl);
        pMalloc->Release();
    }

    if (!result)
        return "";
 SaveLogFolder(path);
    return CString(path);
}

CString GetLogFolder()
{
    HKEY hKey;
    CString folder = "";

    LONG result = RegOpenKeyEx(
        HKEY_CURRENT_USER,
        "Software\\HidMon-NG",
        0,
        KEY_READ,
        &hKey
    );

    if (result != ERROR_SUCCESS)
        return "";

    TCHAR buffer[MAX_PATH];
    DWORD size = sizeof(buffer);
    DWORD type = REG_SZ;

    result = RegQueryValueEx(
        hKey,
        "LogFolder",
        NULL,
        &type,
        (LPBYTE)buffer,
        &size
    );

    RegCloseKey(hKey);

    if (result == ERROR_SUCCESS && type == REG_SZ)
        folder = buffer;

    return folder;
}

void ReadLog()
{
    CFileStatus status;
CString   strFile=GetLogFolder();
  strFile+="\\log.xml";
    
    if (!CFile::GetStatus(strFile, status))
    {
        AfxMessageBox("Log file not found!");
        return;
    }

    CFile file;

    if (!file.Open(strFile,
        CFile::modeRead | CFile::typeBinary))
        return;

    DWORD dwLength = (DWORD)file.GetLength();

    char* pBuffer = new char[dwLength + 1];

    if (dwLength > 0)
        file.Read(pBuffer, dwLength);

    pBuffer[dwLength] = '\0';

    CString strContent = pBuffer;

    delete [] pBuffer;
    file.Close();

    int nPos = 0;
 CString strMessage1 ="";
    while (TRUE)
    {
        int nStart = strContent.Find("<Entry>", nPos);

        if (nStart == -1)
            break;

        int nTimeStart = strContent.Find("<Time>", nStart);
        int nTimeEnd = strContent.Find("</Time>", nStart);

        int nInfoStart = strContent.Find("<Info>", nStart);
        int nInfoEnd = strContent.Find("</Info>", nStart);

        if (nTimeStart == -1 || nTimeEnd == -1 ||
            nInfoStart == -1 || nInfoEnd == -1)
            break;

        CString strTime = strContent.Mid(
            nTimeStart + 6,
            nTimeEnd - (nTimeStart + 6));

        CString strInfo = strContent.Mid(
            nInfoStart + 6,
            nInfoEnd - (nInfoStart + 6));

       
 CString strMessage;
        strMessage.Format(
            "%s : %s\r\n",
            (LPCTSTR)strTime,
            (LPCTSTR)strInfo);
		 strMessage1 +=  "\n"+strMessage;
   //AfxMessageBox(strMessage);
        TRACE("%s", (LPCTSTR)strMessage);

        nPos = nInfoEnd + 7;
    }
	AfxMessageBox(strMessage1);
}




///////////////////////////////////
////////////////////////////////////
///////////////////////////////////
BOOL CHidMon_ngDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
c=0;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
		settrayicon();

		CString logFolder;

    logFolder = GetLogFolder();

    // Check if folder is configured
    if (logFolder.IsEmpty() )
	{
        AfxMessageBox(
            "Please select a folder for log files."
        );
    

        logFolder = SelectLogFolder();

       

            
        }else
	{

			AfxMessageBox(
            "done"
        );
    }
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHidMon_ngDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	

	
		
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHidMon_ngDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHidMon_ngDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHidMon_ngDlg::OnOK() 
{
m_KeyboardNotify.setcond(0);
m_KeyboardNotify.Unregister();
	if (IsRunAsAdmin())
{
    AfxMessageBox("Block(HID) Keybord  ");

if(!m_KeyboardNotify.Register(m_hWnd))
    {
        AfxMessageBox("RegisterDeviceNotification Failed");
    }
 else { }

}
else
{
    MessageBox(
               "Application is NOT running as Administrator this feature nedd Admin permissions",
               "Admin Check",
               MB_OK | MB_ICONWARNING);
}





	
}


void CHidMon_ngDlg::allowhid()
{

AfxMessageBox("Allow(HID) Keybord  ");

m_KeyboardNotify.setcond(0);
m_KeyboardNotify.Unregister();




}
void CHidMon_ngDlg::mointor()




{
	m_KeyboardNotify.Unregister();
	m_KeyboardNotify.setcond(1);
	

	if (IsRunAsAdmin())
{
    AfxMessageBox("Mointor(HID) Keybord  ");

if(!m_KeyboardNotify.Register(m_hWnd))
    {
        AfxMessageBox("RegisterDeviceNotification Failed");
    }
 else { }

}
else
{
    MessageBox(
               "Application is NOT running as Administrator this feature nedd Admin permissions",
               "Admin Check",
               MB_OK | MB_ICONWARNING);
}




}
void CHidMon_ngDlg::blockhid()
{
m_KeyboardNotify.Unregister();
 m_KeyboardNotify.setcond(0);

	if (IsRunAsAdmin())
{
    AfxMessageBox("Block(HID) Keybord  ");
	

if(!m_KeyboardNotify.Register(m_hWnd))
    {
        AfxMessageBox("RegisterDeviceNotification Failed");
    }
 else { }

}
else
{
    MessageBox("Application is NOT running as Administrator this feature nedd Admin permissions",
               "Admin Check",
               MB_OK | MB_ICONWARNING);
}






}


void CHidMon_ngDlg::showabout()
{


ShellAbout(NULL,"HidMon_ng  ","Ahmad Kassem \n Email : neteng.ahmadkassem@gmail.com",AfxGetApp()->LoadIcon(IDI_ICON1));	




}


void CHidMon_ngDlg::showlog()
{


ReadLog();




}


void CHidMon_ngDlg::showcommand()
{


investigatefun();




}

void CHidMon_ngDlg::showwin()
{


	c=1;
	ShowWindow(1);




}



LRESULT	 CHidMon_ngDlg::OnTaskbar(WPARAM wParam, LPARAM lParam)

{

	UINT uMouseMsg = (UINT) lParam;
int wmId, wmEvent;
		
	switch (uMouseMsg)

	{
		case WM_LBUTTONDOWN: 
			{
				::ShowWindow(hw,SW_SHOW);
			if(hw==NULL)
			{	AfxMessageBox("Mouse ");
			break;
			}
			else
			{	
			::ShowWindow(hw,SW_SHOW);
			
							 break;
			}
			}
				case WM_RBUTTONDOWN: 
					{
				
		
			showmen();
			break;
					}

	
	}
		
	return 0;

}


void CHidMon_ngDlg::showmen()
{ 
CPoint pt;
	GetCursorPos(&pt);

 
   
      CMenu menu;
      if (menu.LoadMenu(IDR_MENU1))
      {
         CMenu* pPopup = menu.GetSubMenu(0);
         ASSERT(pPopup != NULL);

         pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
            pt.x, pt.y,
            AfxGetMainWnd()); // use main window for cmds
		  
		 int uu=pPopup->GetMenuItemID(0);
		 CString sd,fg;
		 sd.Format("%d",uu);
			
int dd= pPopup->GetMenuState(uu,1);
pPopup->GetMenuString(uu,(char *)sd.operator LPCTSTR(),59,2);
 
			 
  pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
            pt.x, pt.y,
            AfxGetMainWnd());
 

      }



}







 void  CHidMon_ngDlg::settrayicon()

{




HICON hIcon;
	

	
	char lpszTip[] = "This Program by AHMAD KASSEM ";
	
	HINSTANCE hInst = AfxFindResourceHandle(MAKEINTRESOURCE(IDI_ICON3),RT_GROUP_ICON);
				
hIcon = (HICON)LoadImage(hInst,MAKEINTRESOURCE(IDI_ICON3),IMAGE_ICON,100,100,LR_DEFAULTCOLOR);
    	

	
	NOTIFYICONDATA tnid; 
 
    tnid.hWnd = m_hWnd; 
    tnid.uID = IDR_MAINFRAME; 
    tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
    tnid.uCallbackMessage = WM_TASKBAR; 
    tnid.cbSize = sizeof(NOTIFYICONDATA); 
    tnid.hIcon = hIcon; 
    			
	if (lpszTip) 
        lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip)); 
    else 
        tnid.szTip[0] = '\0'; 
 
    ////////////////////////////////////////////////////////////////	  


	
	Shell_NotifyIcon(NIM_ADD, &tnid); 
 
	
	if (hIcon) 
        DestroyIcon(hIcon); 






 }

void CHidMon_ngDlg::OnButton1() 
{
		ShowWindow(0);
	
}

void CHidMon_ngDlg::OnButton2() 
{
	


	ReadLog();
}

void CHidMon_ngDlg::OnButton3() 
{

investigatefun();

}


void CHidMon_ngDlg::investigatefun() {


		

g_hDefaultDesktop =
        OpenDesktop(_T("Default"),
                    0,
                    FALSE,
                    GENERIC_ALL);

    HDESK hDesk =
        CreateDesktop(
            _T("MyDesk"),
            NULL,
            NULL,
            0,
            GENERIC_ALL,
            NULL);

    if (hDesk == NULL)
    {
        AfxMessageBox(_T("CreateDesktop Failed"));
        return;
    }

    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);
    si.lpDesktop = _T("MyDesk");


char b[MAX_PATH];
char cmdLine[MAX_PATH];

char szExePath[MAX_PATH] = {0};

GetModuleFileName(NULL, szExePath, MAX_PATH);

//AfxMessageBox(szExePath);


strcpy(b, (LPCTSTR)szExePath);

wsprintf(cmdLine, "\"%s\"%s", b, "/desktop");

//  AfxMessageBox(b);
    CreateProcess(
        NULL,
     cmdLine,
        NULL,
        NULL,
        FALSE,
        0,  
        NULL,
        NULL,
        &si,
        &pi);

  Sleep(1000);

 SwitchDesktop(hDesk);

 // Sleep(50000);

 //SwitchDesktop( g_hDefaultDesktop);





	
}


void CHidMon_ngDlg::exitapp() 
{
	exit(0);
	
}


void CHidMon_ngDlg::OnButton4() 
{
	m_KeyboardNotify.setcond(1);
	m_KeyboardNotify.Unregister();

	if (IsRunAsAdmin())
{
    AfxMessageBox("Mointor(HID) Keybord  ");

if(!m_KeyboardNotify.Register(m_hWnd))
    {
        AfxMessageBox("RegisterDeviceNotification Failed");
    }
 else { }

}
else
{
    MessageBox(
               "Application is NOT running as Administrator this feature nedd Admin permissions",
               "Admin Check",
               MB_OK | MB_ICONWARNING);
}




}
void CAboutDlg::OnButton1() 
{

	ShellAbout(NULL,"HidMon_ng  ","Ahmad Kassem \n Email : neteng.ahmadkassem@gmail.com",AfxGetApp()->LoadIcon(IDI_ICON1));	


}

void CHidMon_ngDlg::OnCancel() 
{
AfxMessageBox("Allow(HID) Keybord  ");
m_KeyboardNotify.setcond(0);
m_KeyboardNotify.Unregister();

}



 CHidMon_ngDlg::OnDeviceChange(UINT nEventType, DWORD dwData)
{
    m_KeyboardNotify.OnDeviceChange(nEventType, dwData);
   
    return CDialog::OnDeviceChange(nEventType, dwData);
}



 BOOL CHidMon_ngDlg::IsRunAsAdmin()
{
    BOOL bIsAdmin = FALSE;
    HANDLE hToken = NULL;

    if (OpenProcessToken(GetCurrentProcess(),
                         TOKEN_QUERY,
                         &hToken))
    {
        BYTE buffer[1024];
        DWORD dwSize = 0;

        if (GetTokenInformation(hToken,
                                TokenGroups,
                                buffer,
                                sizeof(buffer),
                                &dwSize))
        {
            PTOKEN_GROUPS pGroups = (PTOKEN_GROUPS)buffer;

            SID_IDENTIFIER_AUTHORITY NtAuthority =
                SECURITY_NT_AUTHORITY;

            PSID AdministratorsGroup = NULL;

            if (AllocateAndInitializeSid(
                    &NtAuthority,
                    2,
                    SECURITY_BUILTIN_DOMAIN_RID,
                    DOMAIN_ALIAS_RID_ADMINS,
                    0, 0, 0, 0, 0, 0,
                    &AdministratorsGroup))
            {
                DWORD i;

                for (i = 0; i < pGroups->GroupCount; i++)
                {
                    if (EqualSid(
                            AdministratorsGroup,
                            pGroups->Groups[i].Sid))
                    {
                        if (pGroups->Groups[i].Attributes &
                            SE_GROUP_ENABLED)
                        {
                            bIsAdmin = TRUE;
                            break;
                        }
                    }
                }

                FreeSid(AdministratorsGroup);
            }
        }

        CloseHandle(hToken);
    }

    return bIsAdmin;
}


