// MP3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MP3.h"
#include "MP3Dlg.h"
#include "Mmsystem.h"
#include "Digitalv.h"
#pragma comment(lib,"Winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//��������ȫ�ֱ���
HWND m_hWnd;
DWORD DeviceID;
MCI_OPEN_PARMS mciopenparms;

void Load(HWND hWnd,CString strFilepath)
{
	m_hWnd=hWnd;
	mciSendCommand(DeviceID,MCI_CLOSE,0,0);//�ڼ����ļ�ǰ�������һ�β��ŵ��豸
	mciopenparms.lpstrElementName=strFilepath;//�������ļ�·�������豸
	DWORD dwReturn;
	if(dwReturn=mciSendCommand(NULL,MCI_OPEN,MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD)(LPVOID)&mciopenparms))
	{
		//������ļ�ʧ�ܣ��򽫳�����Ϣ������buffer������ʾ������
		char buffer[256];
		mciGetErrorString(dwReturn,buffer,256);
		MessageBox(hWnd,buffer,"������!",MB_ICONHAND|MB_ICONERROR|MB_ICONSTOP);

	}
	DeviceID=mciopenparms.wDeviceID;
	//���ļ��ɹ��͹����ļ����豸
}

void play()
{
	MCI_PLAY_PARMS mciplayparms;
	mciplayparms.dwCallback=(DWORD)m_hWnd;
	mciplayparms.dwFrom=0;//ÿ�β��Ŷ��Ǵ�0��ʼ����
	mciSendCommand(DeviceID,MCI_PLAY,MCI_FROM|MCI_NOTIFY,(DWORD)(LPVOID)&mciplayparms);
}

void pause()
{
	mciSendCommand(DeviceID,MCI_PAUSE,0,0);
}
void resume()
{
	mciSendCommand(DeviceID,MCI_RESUME,0,0);
}
void stop()
{
	mciSendCommand(DeviceID,MCI_STOP,0,0);
	mciSendCommand(DeviceID,MCI_CLOSE,0,0);
	//�����ֹͣ��ťʱ�������е���Ϣ�������
}
DWORD setvolume(DWORD vol)
{
	MCI_DGV_SETAUDIO_PARMS setvolume;//�������������Ĳ������ݽṹ
	setvolume.dwCallback=NULL;
	setvolume.dwItem=MCI_DGV_SETAUDIO_VOLUME;//��������������
	setvolume.dwValue=vol;//����ֵ��vol
	mciSendCommand(DeviceID,MCI_SETAUDIO,MCI_DGV_SETAUDIO_ITEM|MCI_DGV_SETAUDIO_VALUE,(DWORD)(LPVOID)&setvolume);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMP3Dlg dialog

CMP3Dlg::CMP3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMP3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMP3Dlg)
	m_int = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMP3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMP3Dlg)
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	DDX_Text(pDX, IDC_vol, m_int);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMP3Dlg, CDialog)
	//{{AFX_MSG_MAP(CMP3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_about, Onabout)
	ON_BN_CLICKED(IDC_exit, Onexit)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, OnCustomdrawSlider)
	ON_BN_CLICKED(IDC_filechoice, Onfilechoice)
	ON_BN_CLICKED(IDC_play, Onplay)
	ON_BN_CLICKED(IDC_pause, Onpause)
	ON_BN_CLICKED(IDC_stop, Onstop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMP3Dlg message handlers

BOOL CMP3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	m_slider.SetRange(0,1000);//������ƶ���Χ0~1000
	m_slider.SetPos(500);//����ָ��ĳ�ʼλ����Ϊ500�����ʼ����Ϊ50
	GetDlgItem(IDC_play)->EnableWindow(false);//�ļ�û�ж�ȡʱ���а�ťӦ���ǲ���ѡ��
	GetDlgItem(IDC_pause)->EnableWindow(false);
	GetDlgItem(IDC_stop)->EnableWindow(false);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMP3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMP3Dlg::OnPaint() 
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
HCURSOR CMP3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMP3Dlg::Onabout() 
{
CAboutDlg dlg;
dlg.DoModal();	
}

void CMP3Dlg::Onexit() 
{
	CDialog::OnCancel();	
}

void CMP3Dlg::OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData(true);
	m_int=m_slider.GetPos()/10;
	setvolume(m_slider.GetPos());
	UpdateData(false);
	*pResult = 0;
}

void CMP3Dlg::Onfilechoice() 
{
char szFileFilter[]="mp3�ļ�(*.mp3)|*.mp3|"
                        "wma�ļ�(*.wma)|*.wma|"
						"wav�ļ�(*.wav)|*.wav|"
						"�����ļ�(*.*)|*.*|";
	CFileDialog dlg(true,NULL,NULL,OFN_HIDEREADONLY,szFileFilter);
	if(dlg.DoModal()==IDOK)
	{
		CString strFilepath=dlg.GetPathName();
		CString strFilename=dlg.GetFileName();
		SetDlgItemText(IDC_filename,strFilename);
		Load(this->m_hWnd,strFilepath);
		GetDlgItem(IDC_play)->EnableWindow(true);//�ļ���ȡ�ɹ�ʱ���а�ť���ѡ��
	    GetDlgItem(IDC_pause)->EnableWindow(true);
	    GetDlgItem(IDC_stop)->EnableWindow(true);
	}	
}
void CMP3Dlg::Onplay() 
{
play();
SetDlgItemText(IDC_pause,"��ͣ");	
}

void CMP3Dlg::Onpause() 
{
CString strtemp;
GetDlgItemText(IDC_pause,strtemp);//��ȡ��ť״̬
if(strtemp.Compare("��ͣ")==0)
{
	pause();
	SetDlgItemText(IDC_pause,"�ָ�");
}	
if(strtemp.Compare("�ָ�")==0)
{
	resume();
	SetDlgItemText(IDC_pause,"��ͣ");
}	
}

void CMP3Dlg::Onstop() 
{
stop();	
SetDlgItemText(IDC_pause,"��ͣ");
GetDlgItem(IDC_play)->EnableWindow(false);//��stop��ť����ʱ,���ź���ͣӦ�þ�������
GetDlgItem(IDC_pause)->EnableWindow(false);	
}
