// centech-troubleshooter.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <windows.h>
#include <stdio.h>
#include "HubUtil.h"

int main(int argc, const char* argv[])
{
    BYTE data = 1;
    if (1 < argc)
    {
        // 引数(1:ON / 0:OFF)
        char ch;
        memcpy(&ch, argv[1], 1);

        // ON/OFF
        if (ch == '1')
        {
            // ON
            //printf("ONにします\n");
            data = 1;
        }
        else
        {
            // OFF
            //printf("OFFにします\n");
            data = 0;
        }
    }

    USB_1PORT_HUB_DEVICE_INFO devinfo = {};
    
    for (int i = 0; i < 1000; i++)
    {
        switch (data)
        {
        case 1:
        {
            if (Hub_GetDeviceInfo(&devinfo)) {
                while (1) {
                    Hub_SetStatus(devinfo.CtrlSerial, 1);// On
                    if (!Hub_GetNextDeviceInfo(&devinfo)) {
                        break;
                    }
                }
            }
            break;
        }

        default:
        {
            if (Hub_GetDeviceInfo(&devinfo)) {
                while (1) {
                    Hub_SetStatus(devinfo.CtrlSerial, 0);// Off
                    if (!Hub_GetNextDeviceInfo(&devinfo)) {
                        break;
                    }
                }
            }
            break;
        }
        }

        if (Hub_GetDeviceInfo(&devinfo)) 
        {
            BYTE status = 0;
            if (Hub_GetStatus(devinfo.CtrlSerial, &status))
            {
                if (status == data)
                {
                    break;
                }
            }
        }
    }
}
