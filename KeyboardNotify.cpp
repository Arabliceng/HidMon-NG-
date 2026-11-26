#include "stdafx.h"
#include "KeyboardNotify.h"
#include <dbt.h>

#include <winuser.h>

#include <windows.h>

#include <setupapi.h>

#include <afxwin.h>

#include <windows.h>

#include <setupapi.h>

#include <devguid.h>

#include <regstr.h>


#include <dbt.h>



#pragma comment(lib, "user32.lib")

#include <windows.h>
#pragma comment(lib, "setupapi.lib")











typedef DWORD DEVINST;
typedef DWORD CONFIGRET; 

#define CR_SUCCESS 0

typedef CONFIGRET (WINAPI *pCM_Get_Device_IDA)(
    DEVINST dnDevInst,
    LPSTR Buffer,
    ULONG BufferLen,
    ULONG ulFlags
);

typedef CONFIGRET (WINAPI *pCM_Disable_DevNode)(
    DEVINST dnDevInst,
    ULONG ulFlags
);





CKeyboardNotify::CKeyboardNotify()
{
    m_hDevNotify = NULL;
}

CKeyboardNotify::~CKeyboardNotify()
{
    Unregister();
}

BOOL CKeyboardNotify::Register(HWND hWnd)
{
    DEV_BROADCAST_DEVICEINTERFACE_A dbi;

    ZeroMemory(&dbi, sizeof(dbi));

    dbi.dbcc_size = sizeof(dbi);
    dbi.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    dbi.dbcc_classguid = GUID_DEVINTERFACE_KEYBOARD;

    m_hDevNotify = RegisterDeviceNotification(
                        hWnd,
                        &dbi,
                        DEVICE_NOTIFY_WINDOW_HANDLE);

    return (m_hDevNotify != NULL);
}



BOOL CKeyboardNotify::DisableKeyboard(LPCTSTR pszInterfacePath)
{
     HDEVINFO hDevInfo;
    SP_DEVICE_INTERFACE_DATA ifData;
    SP_DEVINFO_DATA devData;
    PSP_DEVICE_INTERFACE_DETAIL_DATA pDetail;
    DWORD required = 0;

    hDevInfo = SetupDiCreateDeviceInfoList(NULL, NULL);
    if (hDevInfo == INVALID_HANDLE_VALUE)
        return FALSE;

    ifData.cbSize = sizeof(ifData);

    if (!SetupDiOpenDeviceInterface(
            hDevInfo,
            pszInterfacePath,
            0,
            &ifData))
    {

//AfxMessageBox("no 1 "  );

        SetupDiDestroyDeviceInfoList(hDevInfo);
        return FALSE;
    }
	//	AfxMessageBox("yes 1  "  );

    devData.cbSize = sizeof(devData);

    SetupDiGetDeviceInterfaceDetail(
        hDevInfo,
        &ifData,
        NULL,
        0,
        &required,
        &devData);


 

    pDetail = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(required);
    if (pDetail == NULL)
    {
//AfxMessageBox("no 2 "  );
        SetupDiDestroyDeviceInfoList(hDevInfo);
        return FALSE;
    }
//	AfxMessageBox("yes 2 "  );
    pDetail->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

    if (!SetupDiGetDeviceInterfaceDetail(
            hDevInfo,
            &ifData,
            pDetail,
            required,
            NULL,
            &devData))
    {
        free(pDetail);
        SetupDiDestroyDeviceInfoList(hDevInfo);


//AfxMessageBox("no 3 "  );
        return FALSE;
    }
	//	AfxMessageBox("yes 3 "  );








HMODULE hCfg = LoadLibrary("cfgmgr32.dll");
if (!hCfg)
{
    AfxMessageBox("cfgmgr32.dll not found");
    return 0 ;
}


		pCM_Get_Device_IDA CM_Get_Device_IDA =
    (pCM_Get_Device_IDA)GetProcAddress(hCfg, "CM_Get_Device_IDA");

pCM_Disable_DevNode CM_Disable_DevNode =
    (pCM_Disable_DevNode)GetProcAddress(hCfg, "CM_Disable_DevNode");

if (!CM_Get_Device_IDA || !CM_Disable_DevNode)
{
    AfxMessageBox("CFG manager functions not available");
    FreeLibrary(hCfg);
    return 0 ;
}

char deviceId[512];

CONFIGRET cr = CM_Get_Device_IDA(
    devData.DevInst,
    deviceId,
    sizeof(deviceId),
    0);

//if (cr == CR_SUCCESS)
//{ AfxMessageBox(deviceId);}

 CM_Disable_DevNode =
    (pCM_Disable_DevNode)GetProcAddress(hCfg, "CM_Disable_DevNode");

if (!CM_Disable_DevNode)
{
    AfxMessageBox("CM_Disable_DevNode not available on this system");
    FreeLibrary(hCfg);
    return 0;
}

 cr = CM_Disable_DevNode(devData.DevInst, 0);

CString s;
s.Format("Result = %lu", cr);
//AfxMessageBox(s);

FreeLibrary(hCfg);






    free(pDetail);
    SetupDiDestroyDeviceInfoList(hDevInfo);





	SP_PROPCHANGE_PARAMS pcp;

 

ZeroMemory(&pcp, sizeof(pcp));

pcp.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);

pcp.ClassInstallHeader.InstallFunction = DIF_PROPERTYCHANGE;

pcp.StateChange = DICS_DISABLE;

pcp.Scope = DICS_FLAG_GLOBAL;

pcp.HwProfile = 0;

 

if (SetupDiSetClassInstallParams(

        hDevInfo,

        &devData,

        (SP_CLASSINSTALL_HEADER*)&pcp,

        sizeof(pcp)))

{

    if (SetupDiChangeState(hDevInfo, &devData))

    {

        // device state changed

    }

    else

    {

        printf("ChangeState failed: %lu\n", GetLastError());

    }

}

else

{

    printf("SetClassInstallParams failed: %lu\n", GetLastError());

}

    return 1;

}






void CKeyboardNotify::Unregister()
{
    if (m_hDevNotify)
    {
        UnregisterDeviceNotification(m_hDevNotify);
        m_hDevNotify = NULL;
    }
}

BOOL CKeyboardNotify::OnDeviceChange(UINT nEventType, DWORD dwData)
{
    switch(nEventType)
    {
    case DBT_DEVICEARRIVAL:
        {
            PDEV_BROADCAST_HDR pHdr =
                (PDEV_BROADCAST_HDR)dwData;

            if (pHdr &&
                pHdr->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)
            {
                PDEV_BROADCAST_DEVICEINTERFACE pDev =
                    (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;

                TRACE("Keyboard Connected\n");
                TRACE("%s\n", pDev->dbcc_name);


				CString strDevice = pDev->dbcc_name;

				// AfxMessageBox(_T(pDev->dbcc_classguid));
			//	if (strDevice.Find (_T("\\?\HID#VID_04D9&"))==0)
		///	{ AfxMessageBox("fghfghfgh"  );}



			
		 if( DisableKeyboard(strDevice ))
		 
		 {	 //AfxMessageBox("yesdy"   );
		 
		 }
		 else
		 {	 AfxMessageBox("no"   );}
			
				// AfxMessageBox(pDev->dbcc_name   );
			


            }else

			{
				PDEV_BROADCAST_DEVICEINTERFACE pDev =
                    (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;

                TRACE("Keyboard Connected\n");
                TRACE("%s\n", pDev->dbcc_name);


			//	CString strDevice = pDev->dbcc_name;

				 CString strDevice(pDev->dbcc_name);
	//	AfxMessageBox(strDevice  );





CString strType;
strType.Format(_T("%u"), (unsigned int)pHdr->dbch_devicetype);
//AfxMessageBox("ahmad");
//AfxMessageBox(strType);
//	AfxMessageBox("ahmad");


				DisableKeyboard(strDevice );
				
				
//		AfxMessageBox("xsfvdsfsdf");
}
		
        }
        break;

    case DBT_DEVICEREMOVECOMPLETE:
        {
            PDEV_BROADCAST_HDR pHdr =
                (PDEV_BROADCAST_HDR)dwData;

            if (pHdr &&
                pHdr->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE)
            {
                PDEV_BROADCAST_DEVICEINTERFACE pDev =
                    (PDEV_BROADCAST_DEVICEINTERFACE)pHdr;

                TRACE("Keyboard Removed\n");
                TRACE("%s\n", pDev->dbcc_name);
            }
        }
        break;
    }

    return TRUE;
}