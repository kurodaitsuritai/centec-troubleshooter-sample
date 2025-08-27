#ifndef __HUBUTL_H__
#define __HUBUTL_H__

typedef enum { 
  USB_HUB_NoDeviceConnected         = 0,// Indicates that there is no device connected to the port.
  USB_HUB_DeviceConnected           = 1,// Indicates that a device was successfully connected to the port.
  USB_HUB_DeviceFailedEnumeration   = 2,// Indicates that an attempt was made to connect a device to the port, but the enumeration of the device failed.
  USB_HUB_DeviceGeneralFailure      = 3,// Indicates that an attempt was made to connect a device to the port, but the connection failed for unspecified reasons.
  USB_HUB_DeviceCausedOvercurrent   = 4,// Indicates that an attempt was made to connect a device to the port, but the attempt failed because of an overcurrent condition.
  USB_HUB_DeviceNotEnoughPower      = 5,// Indicates that an attempt was made to connect a device to the port, but there was not enough power to drive the device, and the connection failed.
  USB_HUB_DeviceNotEnoughBandwidth  = 6,// Indicates that an attempt was made to connect a device to the port, but there was not enough bandwidth available for the device to function properly, and the connection failed.
  USB_HUB_DeviceHubNestedTooDeeply  = 7,// Indicates that an attempt was made to connect a device to the port, but the nesting of USB hubs was too deep, so the connection failed.
  USB_HUB_DeviceInLegacyHub         = 8,// Indicates that an attempt was made to connect a device to the port of an unsupported legacy hub, and the connection failed.
  USB_HUB_DeviceEnumerating         = 9,// Indicates that a device connected to the port is currently being enumerated.
  USB_HUB_DeviceReset               = 10// Indicates that device connected to the port is currently being reset.
} USB_HUB_CONNECTION_STATUS;

typedef struct USB_1PORT_HUB_DEVICE_INFO {
	UCHAR	HUB_STATUS;			// HUB Power Status
	WCHAR	CtrlSerial[256];	// Control USBSerial
	UCHAR	bDeviceClass;		// Specifies the class code of the device as assigned by the USB specification group.
	UCHAR	bDeviceSubClass;	// Specifies the subclass code of the device as assigned by the USB specification group.
	USHORT	idVendor;			// Specifies the vendor identifier for the device as assigned by the USB specification committee.
	USHORT	idProduct;			// Specifies the product identifier. This value is assigned by the manufacturer and is device-specific.
	USHORT	bcdDevice;			// Identifies the version of the device. This value is a binary-coded decimal number.
	UCHAR	CurrentConfigurationValue; // Contains the ID used with the SetConfiguration request to specify that current configuration of the device connected to the indicated port. For an explanation of this value, see the Universal Serial Bus Specification.
	UCHAR	Speed;				// Contains a value of type USB_HUB_CONNECTION_STATUS that indicates the speed of the device.
	WCHAR	cSerial[256];		// USB Serial
	WCHAR	cDeviceName[256];	// 
	USB_HUB_CONNECTION_STATUS	ConnectionStatus;
} USB_1PORT_HUB_DEVICE_INFO, *PUSB_1PORT_HUB_DEVICE_INFO;

// HUB Enable端子の状態取得
// status	端子状態	1:On 0:Off
BOOL (__stdcall Hub_GetStatus)(WCHAR *serial,BYTE *status);
// HUB Enable端子の状態設定
// status	端子状態	1:On 0:Off
BOOL (__stdcall Hub_SetStatus)(WCHAR *serial,BYTE hub_power);
// HUB Reset
// ms		リセット時間（単位msec）
BOOL (__stdcall Hub_SetReset)(WCHAR *serial,BYTE ms);
// HUB Fault端子状態取得
// status	Fault端子状態	1:High 0:Low
BOOL (__stdcall Hub_GetFault)(WCHAR *serial,BYTE *status);
// HUBに接続されているデバイス情報取得
BOOL (__stdcall Hub_GetDeviceInfo)(USB_1PORT_HUB_DEVICE_INFO *info);
BOOL (__stdcall Hub_GetNextDeviceInfo)(USB_1PORT_HUB_DEVICE_INFO *info);

// RTC時間の取得
BOOL (__stdcall Hub_GetRTC)(WCHAR *serial,BYTE *datetime);
// RTC時間の設定
BOOL (__stdcall Hub_SetRTC)(WCHAR *serial,BYTE *datetime);

// FRAM指定アドレスのリード
BOOL (__stdcall Hub_ReadFram)(WCHAR *serial,BYTE addr,BYTE n,BYTE *data);
// FRAM指定アドレスへのライト
BOOL (__stdcall Hub_WriteFram)(WCHAR *serial,BYTE addr,BYTE n,BYTE *data);

#endif