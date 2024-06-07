
// MenuTestDlg.h : header file
//

#pragma once
#include "TransparentButton.h"


// CMenuTestDlg dialog
class CMenuTestDlg : public CDialog
{
public:
	CMenuTestDlg(CWnd* pParent = NULL);	// standard constructor

    void HoverChanged(CTransparentButton* btn);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENUTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

    void ShowMenu(UINT Flags);


// Implementation
protected:
    CPoint m_MinSize;
	HICON m_hIcon;
    bool m_Exclude = false;
    bool m_Vertical = false;
    bool m_Rtl = false;
    CBrush m_BackColor;
    CTransparentButton* m_HoverButton = nullptr;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonTopLeft();
    afx_msg void OnBnClickedButtonTopRight();
    afx_msg void OnBnClickedButtonBottomLeft();
    afx_msg void OnBnClickedButtonBottomRight();
    afx_msg void OnBnClickedButtonTopVcenter();
    afx_msg void OnBnClickedButtonCenterLeft();
    afx_msg void OnBnClickedButtonCenterVcenter();
    afx_msg void OnBnClickedButtonCenterRight();
    afx_msg void OnBnClickedButtonBottomVcenter();
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
    CTransparentButton m_ButtonBottomLeft;
    CTransparentButton m_ButtonBottomRight;
    CTransparentButton m_ButtonBottomVCenter;
    CTransparentButton m_ButtonCenterLeft;
    CTransparentButton m_ButtonCenterRight;
    CTransparentButton m_ButtonCenterVCenter;
    CTransparentButton m_ButtonTopLeft;
    CTransparentButton m_ButtonTopRight;
    CTransparentButton m_ButtonTopVCenter;
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
