#ifndef __MOUNTMGR_H
#define __MOUNTMGR_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

// #include "ntddk.h"

DEFINE_GUID(MOUNTDEV_MOUNTED_DEVICE_GUID,
    0x53f5630d, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

#define MOUNTMGRCONTROLTYPE                             ((ULONG)'m')
#define MOUNTDEVCONTROLTYPE                             ((ULONG)'M')

#define MOUNTMGR_DEVICE_NAME              L"\\Device\\MountPointManager"
#define MOUNTMGR_DOS_DEVICE_NAME          L"\\\\.\\MountPointManager"

#define IOCTL_MOUNTMGR_CREATE_POINT \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_QUERY_POINTS \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_MOUNTMGR_DELETE_POINTS \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_CHANGE_NOTIFY \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION \
  CTL_CODE(MOUNTMGRCONTROLTYPE, 11, METHOD_BUFFERED, FILE_READ_ACCESS)


typedef struct _MOUNTDEV_NAME {
  USHORT  NameLength;
  WCHAR  Name[1];
} MOUNTDEV_NAME, *PMOUNTDEV_NAME;

typedef struct _MOUNTMGR_CHANGE_NOTIFY_INFO {
  ULONG  EpicNumber;
} MOUNTMGR_CHANGE_NOTIFY_INFO, *PMOUNTMGR_CHANGE_NOTIFY_INFO;

typedef struct _MOUNTMGR_CREATE_POINT_INPUT {
  USHORT  SymbolicLinkNameOffset;
  USHORT  SymbolicLinkNameLength;
  USHORT  DeviceNameOffset;
  USHORT  DeviceNameLength;
} MOUNTMGR_CREATE_POINT_INPUT, *PMOUNTMGR_CREATE_POINT_INPUT;

typedef struct _MOUNTMGR_DRIVE_LETTER_INFORMATION {
  BOOLEAN  DriveLetterWasAssigned;
  UCHAR  CurrentDriveLetter;
} MOUNTMGR_DRIVE_LETTER_INFORMATION, *PMOUNTMGR_DRIVE_LETTER_INFORMATION;

typedef struct _MOUNTMGR_DRIVE_LETTER_TARGET {
  USHORT  DeviceNameLength;
  WCHAR  DeviceName[1];
} MOUNTMGR_DRIVE_LETTER_TARGET, *PMOUNTMGR_DRIVE_LETTER_TARGET;

typedef struct _MOUNTMGR_MOUNT_POINT {
  ULONG  SymbolicLinkNameOffset;
  USHORT  SymbolicLinkNameLength;
  ULONG  UniqueIdOffset;
  USHORT  UniqueIdLength;
  ULONG  DeviceNameOffset;
  USHORT  DeviceNameLength;
} MOUNTMGR_MOUNT_POINT, *PMOUNTMGR_MOUNT_POINT;

typedef struct _MOUNTMGR_MOUNT_POINTS {
  ULONG  Size;
  ULONG  NumberOfMountPoints;
  MOUNTMGR_MOUNT_POINT  MountPoints[1];
} MOUNTMGR_MOUNT_POINTS, *PMOUNTMGR_MOUNT_POINTS;

typedef struct _MOUNTMGR_TARGET_NAME {
  USHORT  DeviceNameLength;
  WCHAR  DeviceName[1];
} MOUNTMGR_TARGET_NAME, *PMOUNTMGR_TARGET_NAME;

typedef struct _MOUNTMGR_VOLUME_MOUNT_POINT {
  USHORT  SourceVolumeNameOffset;
  USHORT  SourceVolumeNameLength;
  USHORT  TargetVolumeNameOffset;
  USHORT  TargetVolumeNameLength;
} MOUNTMGR_VOLUME_MOUNT_POINT, *PMOUNTMGR_VOLUME_MOUNT_POINT;

#ifdef __cplusplus
}
#endif

#endif /* __MOUNTMGR_H */

