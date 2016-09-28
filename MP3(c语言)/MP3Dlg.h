// MP3Dlg.h : header file
//

#if !defined(AFX_MP3DLG_H__B99CF0CF_9814_4343_AEE9_9255B7F20239__INCLUDED_)
#define AFX_MP3DLG_H__B99CF0CF_9814_4343_AEE9_9255B7F20239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMP3Dlg dialog

class CMP3Dlg : public CDialog
{
// Construction
public:
	CMP3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMP3Dlg)
	enum { IDD = IDD_MP3_DIALOG };
	CSliderCtrl	m_slider;
	int		m_int;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMP3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onabout();
	afx_msg void Onexit();
	afx_msg void OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onfilechoice();
	afx_msg void Onplay();
	afx_msg void Onpause();
	afx_msg void Onstop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3DLG_H__B99CF0CF_9814_4343_AEE9_9255B7F20239__INCLUDED_)
