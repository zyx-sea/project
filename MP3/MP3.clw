; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMP3Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MP3.h"

ClassCount=3
Class1=CMP3App
Class2=CMP3Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MP3_DIALOG

[CLS:CMP3App]
Type=0
HeaderFile=MP3.h
ImplementationFile=MP3.cpp
Filter=N

[CLS:CMP3Dlg]
Type=0
HeaderFile=MP3Dlg.h
ImplementationFile=MP3Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_vol

[CLS:CAboutDlg]
Type=0
HeaderFile=MP3Dlg.h
ImplementationFile=MP3Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308353
Control4=IDOK,button,1342373889

[DLG:IDD_MP3_DIALOG]
Type=1
Class=CMP3Dlg
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_filename,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_filechoice,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_play,button,1342242816
Control7=IDC_pause,button,1342242816
Control8=IDC_stop,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_about,button,1342242816
Control12=IDC_exit,button,1342242816
Control13=IDC_vol,edit,1350631552
Control14=IDC_SLIDER,msctls_trackbar32,1342242820

