#ifndef __KEYBOARDNOTIFY_H__
#define __KEYBOARDNOTIFY_H__
#define WINVER 0x0500

#include <windows.h>
#include <dbt.h>

#include "ttest.h"

#ifdef UNICODE
typedef DEV_BROADCAST_DEVICEINTERFACE_W DEV_BROADCAST_DEVICEINTERFACE;
typedef PDEV_BROADCAST_DEVICEINTERFACE_W PDEV_BROADCAST_DEVICEINTERFACE;
#else
typedef DEV_BROADCAST_DEVICEINTERFACE_A DEV_BROADCAST_DEVICEINTERFACE;
typedef PDEV_BROADCAST_DEVICEINTERFACE_A PDEV_BROADCAST_DEVICEINTERFACE;
#endif

typedef HANDLE HDEVNOTIFY;
// Keyboard Interface GUID
// DEFINE_GUID(GUID_DEVINTERFACE_KEYBOARD,
// 0x884b96c3,0x56ef,0x11d1,0xbc,0x8c,0x00,0xa0,0xc9,0x14,0x05,0xdd);

static const GUID GUID_DEVINTERFACE_KEYBOARD =
{
    0x884b96c3,
    0x56ef,
    0x11d1,
    {0xbc,0x8c,0x00,0xa0,0xc9,0x14,0x05,0xdd}
};

class CKeyboardNotify
{
public:
    CKeyboardNotify();
    virtual ~CKeyboardNotify();
   CString XmlEscape(CString str);
BOOL WriteLog(CString strFile, CString strInfo);
void ReadLog(CString strFile);
    BOOL Register(HWND hWnd);
    void Unregister();

BOOL DisableKeyboard(LPCTSTR pszInterfacePath);
    BOOL OnDeviceChange(UINT nEventType, DWORD dwData);
void setcond(int cond);
int getcond();
protected:
    HDEVNOTIFY m_hDevNotify;
	int cond;
HDESK  g_hDefaultDesktop;
};

#endif