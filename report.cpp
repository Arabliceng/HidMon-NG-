// report.cpp : implementation file
//

#include "stdafx.h"
#include <time.h>
#include "report.h"
#include "HidMon_ng.h"
#include "HidMon_ngDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef VK_BROWSER_BACK
#define VK_BROWSER_BACK        0xA6
#define VK_BROWSER_FORWARD     0xA7
#define VK_BROWSER_REFRESH     0xA8
#define VK_BROWSER_STOP        0xA9
#define VK_BROWSER_SEARCH      0xAA
#define VK_BROWSER_FAVORITES   0xAB
#define VK_BROWSER_HOME        0xAC


#define VK_BE 0xBE
#define VK_BC 0xBC
#define VK_BD 0xBD
#define VK_BA 0xBA


#define VK_VOLUME_MUTE         0xAD
#define VK_VOLUME_DOWN         0xAE
#define VK_VOLUME_UP           0xAF

#define VK_MEDIA_NEXT_TRACK    0xB0
#define VK_MEDIA_PREV_TRACK    0xB1
#define VK_MEDIA_STOP          0xB2
#define VK_MEDIA_PLAY_PAUSE    0xB3
#define VK_SLEEP 0x5F
#endif

HHOOK g_hHook = NULL;

CString toto;

CString output;
LRESULT CALLBACK LowLevelKeyboardProc(
    int nCode,
    WPARAM wParam,
    LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        
 KBDLLHOOKSTRUCT *pKey =
            (KBDLLHOOKSTRUCT *)lParam;
        if (wParam == WM_KEYDOWN ||
            wParam == WM_SYSKEYDOWN)
        {
            HWND hWnd = AfxGetMainWnd()->GetSafeHwnd();

            if (hWnd != NULL)
            {
                ::PostMessage(
                    hWnd,
                    WM_KEY_HOOK,
                    (WPARAM)pKey->vkCode,
                    0);
            }
        }
    }

    return CallNextHookEx(
        g_hHook,
        nCode,
        wParam,
        lParam);
}
/////////////////////////////////////////////////////////////////////////////
// report dialog
























report::report(CWnd* pParent /*=NULL*/)
	: CDialog(report::IDD, pParent)
{
	//{{AFX_DATA_INIT(report)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

BOOL report::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.



 g_hHook = SetWindowsHookEx(
                    WH_KEYBOARD_LL,
                    LowLevelKeyboardProc,
                    AfxGetInstanceHandle(),
                    0);

    if (g_hHook == NULL)
    {
        AfxMessageBox("Unable to install keyboard hook.");
    }

	return TRUE; 
}
void report::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(report)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(report, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)

	 ON_MESSAGE(WM_KEY_HOOK,OnKeyHook)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// report message handlers

void report::OnOK() 
{
	


HDESK  g_hDefaultDesktop =
        OpenDesktop(_T("Default"),
                    0,
                    FALSE,
                    GENERIC_ALL);

	SwitchDesktop( g_hDefaultDesktop);
	exit(0);

}
void report::OnDestroy()
{
    if (g_hHook != NULL)
    {
        UnhookWindowsHookEx(g_hHook);
        g_hHook = NULL;
    }

    CDialog::OnDestroy();
}


CString report::GetKeyText(UINT vk)
{switch (vk)
{
case VK_CONTROL:   return "Ctrl";
case VK_LCONTROL:  return "Left Ctrl";
case VK_RCONTROL:  return "Right Ctrl";

case VK_SHIFT:     return "Shift";
case VK_LSHIFT:    return "Left Shift";
case VK_RSHIFT:    return "Right Shift";

case VK_MENU:      return "Alt";
case VK_LMENU:     return "Left Alt";
case VK_RMENU:     return "Right Alt";


case VK_BE:     return ".";
case VK_BC:     return ",";
case VK_BD:     return "-";
case VK_BA:     return ";";

case VK_RETURN:    return "Enter";
case VK_SPACE:     return " ";
case VK_BACK:      return "Backspace";
case VK_TAB:       return "Tab";
case VK_ESCAPE:    return "Esc";
case VK_CAPITAL:   return "Caps Lock";

case VK_LEFT:      return "Left";
case VK_RIGHT:     return "Right";
case VK_UP:        return "Up";
case VK_DOWN:      return "Down";

case VK_INSERT:    return "Insert";
case VK_DELETE:    return "Delete";
case VK_HOME:      return "Home";
case VK_END:       return "End";
case VK_PRIOR:     return "Page Up";
case VK_NEXT:      return "Page Down";

case VK_SNAPSHOT:  return "Print Screen";
case VK_SCROLL:    return "Scroll Lock";
case VK_PAUSE:     return "Pause";

case VK_NUMLOCK:   return "Num Lock";

case VK_NUMPAD0:   return "Num 0";
case VK_NUMPAD1:   return "Num 1";
case VK_NUMPAD2:   return "Num 2";
case VK_NUMPAD3:   return "Num 3";
case VK_NUMPAD4:   return "Num 4";
case VK_NUMPAD5:   return "Num 5";
case VK_NUMPAD6:   return "Num 6";
case VK_NUMPAD7:   return "Num 7";
case VK_NUMPAD8:   return "Num 8";
case VK_NUMPAD9:   return "Num 9";

case VK_MULTIPLY:  return "Num *";
case VK_ADD:       return "Num +";
case VK_SEPARATOR: return "Num Separator";
case VK_SUBTRACT:  return "Num -";
case VK_DECIMAL:   return "Num .";
case VK_DIVIDE:    return "Num /";

case VK_APPS:      return "Menu";

case VK_LWIN:      return "Left Win";
case VK_RWIN:      return "Right Win";

case VK_BROWSER_BACK:      return "Browser Back";
case VK_BROWSER_FORWARD:   return "Browser Forward";
case VK_BROWSER_REFRESH:   return "Browser Refresh";
case VK_BROWSER_STOP:      return "Browser Stop";
case VK_BROWSER_SEARCH:    return "Browser Search";
case VK_BROWSER_FAVORITES: return "Browser Favorites";
case VK_BROWSER_HOME:      return "Browser Home";

case VK_VOLUME_MUTE:       return "Volume Mute";
case VK_VOLUME_DOWN:       return "Volume Down";
case VK_VOLUME_UP:         return "Volume Up";
case VK_MEDIA_NEXT_TRACK:  return "Next Track";
case VK_MEDIA_PREV_TRACK:  return "Previous Track";
case VK_MEDIA_STOP:        return "Stop";
case VK_MEDIA_PLAY_PAUSE:  return "Play/Pause";

case VK_SLEEP:     return "Sleep";
}

   if (vk >= 'A' && vk <= 'Z')
    return CString((char)vk);

if (vk >= '0' && vk <= '9')
    return CString((char)vk);

if (vk >= VK_F1 && vk <= VK_F12)
{
    CString s;
    s.Format("F%d", vk - VK_F1 + 1);
    return s;
}

CString s;
s.Format("VK_%02X", vk);
return s;
}

LRESULT report::OnKeyHook(
    WPARAM wParam,
    LPARAM lParam)
{
  /* char szName[64];

LONG lParam1 = MapVirtualKey((UINT)wParam, 0) << 16;

GetKeyNameText(
    lParam1,
    szName,
    sizeof(szName));

char szText[128];

wsprintf(
    szText,
    "Key : %s (VK=%02X)",
    szName,
    (UINT)wParam);
 
 toto=toto+ szName;

AfxMessageBox( toto);
//SetDlgItemText(IDC_STATIC_STATUS, szText);
    return 0;*/


UINT vk;

 CString key =  GetKeyText((UINT)wParam);

    if (vk == VK_RETURN)
    {
        output += "\r\n";
    }
    else if (vk == VK_SPACE)
    {
        output += " ";
    }
    else if (key.GetLength() == 1)
    {
        output += key;
    }
    else
    {
        output += "\r\n[" + key + "]\r\n";
    }




   
//AfxMessageBox( toto);
    SetDlgItemText(IDC_EDIT1, output);    // or AfxMessageBox(toto)

    return 0;
}




static CString XmlEscape(const CString& input)
{
    CString output;
    int i;

    for (i = 0; i < input.GetLength(); i++)
    {
        TCHAR ch = input[i];

        switch (ch)
        {
        case '&':
            output += "&amp;";
            break;

        case '<':
            output += "&lt;";
            break;

        case '>':
            output += "&gt;";
            break;

        case '"':
            output += "&quot;";
            break;

        case '\'':
            output += "&apos;";
            break;

        default:
            // XML 1.0 excludes most control characters.
            if (ch == 9 || ch == 10 || ch == 13 ||
                (ch >= 32 && ch != 0xFFFE &&
                 ch != 0xFFFF))
            {
                output += ch;
            }
            break;
        }
    }

    return output;
}


void report::OnButton1() 
{
	
// Ask user how to export.
    int choice = AfxMessageBox(
        "Export all commands as ONE XML tag?\n\n"
        "YES = One Command tag\n"
        "NO  = Multiple Command tags",
        MB_YESNO | MB_ICONQUESTION
    );

    BOOL oneTag = (choice == IDYES);

    CFileDialog dlg(
        FALSE,
        "xml",
        "Commands.xml",
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "XML Files (*.xml)|*.xml|All Files (*.*)|*.*||",
        this
    );

    if (dlg.DoModal() != IDOK)
        return;

    FILE *fp = fopen(dlg.GetPathName(), "wb");

    if (fp == NULL)
    {
        AfxMessageBox("Cannot create XML file.");
        return;
    }

    CString text;
    GetDlgItemText(IDC_EDIT1, text);

    fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    fprintf(fp, "<ETWGroup>\r\n");

    CString modifiers;
    CString allCommands;

    int pos = 0;

    while (pos < text.GetLength())
    {
        int end = text.Find('\n', pos);

        CString line;

        if (end == -1)
        {
            line = text.Mid(pos);
            pos = text.GetLength();
        }
        else
        {
            line = text.Mid(pos, end - pos);
            pos = end + 1;
        }

        line.TrimLeft();
        line.TrimRight();

        if (line.IsEmpty())
            continue;

        // Detect modifier keys.
        if (line.CompareNoCase("[Ctrl]") == 0)
        {
            modifiers += "Ctrl+";
            continue;
        }

        if (line.CompareNoCase("[Shift]") == 0)
        {
            modifiers += "Shift+";
            continue;
        }

        if (line.CompareNoCase("[Alt]") == 0)
        {
            modifiers += "Alt+";
            continue;
        }

        if (line.CompareNoCase("[Left Win]") == 0)
        {
            modifiers += "Left Win+";
            continue;
        }

        if (line.CompareNoCase("[Right Win]") == 0)
        {
            modifiers += "Right Win+";
            continue;
        }

        CString command;

        if (!modifiers.IsEmpty())
        {
            // First character belongs to the shortcut.
            command = modifiers + line.Left(1);

            modifiers.Empty();

            // Remaining characters are separate text.
            CString remaining = line.Mid(1);

            if (!remaining.IsEmpty())
            {
                if (oneTag)
                {
                    command += remaining;
                }
                else
                {
                    if (!allCommands.IsEmpty())
                        allCommands += "\r\n";

                    allCommands += command;
                    command = remaining;
                }
            }
        }
        else
        {
            command = line;
        }

        if (oneTag)
        {
            if (!allCommands.IsEmpty())
                allCommands += "\r\n";

            allCommands += command;
        }
        else
        {
            CString escaped = XmlEscape(command);

            fprintf(fp, "    <Command>%s</Command>\r\n",
                    (LPCSTR)escaped);
        }
    }

    // Export remaining commands as one tag.
    if (oneTag && !allCommands.IsEmpty())
    {
        CString escaped = XmlEscape(allCommands);

        fprintf(fp, "    <Command>%s</Command>\r\n",
                (LPCSTR)escaped);
    }

    fprintf(fp, "</ETWGroup>\r\n");

    fclose(fp);

    AfxMessageBox("Commands exported successfully.please remove usb before press return button ");
}