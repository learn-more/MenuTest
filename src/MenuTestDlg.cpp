
// MenuTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MenuTest.h"
#include "MenuTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenuTestDlg dialog



CMenuTestDlg::CMenuTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MENUTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMenuTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_BOTTOM_LEFT, m_ButtonBottomLeft);
    DDX_Control(pDX, IDC_BUTTON_BOTTOM_RIGHT, m_ButtonBottomRight);
    DDX_Control(pDX, IDC_BUTTON_BOTTOM_VCENTER, m_ButtonBottomVCenter);
    DDX_Control(pDX, IDC_BUTTON_CENTER_LEFT, m_ButtonCenterLeft);
    DDX_Control(pDX, IDC_BUTTON_CENTER_RIGHT, m_ButtonCenterRight);
    DDX_Control(pDX, IDC_BUTTON_CENTER_VCENTER, m_ButtonCenterVCenter);
    DDX_Control(pDX, IDC_BUTTON_TOP_LEFT, m_ButtonTopLeft);
    DDX_Control(pDX, IDC_BUTTON_TOP_RIGHT, m_ButtonTopRight);
    DDX_Control(pDX, IDC_BUTTON_TOP_VCENTER, m_ButtonTopVCenter);
}

BEGIN_MESSAGE_MAP(CMenuTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_TOP_LEFT, &CMenuTestDlg::OnBnClickedButtonTopLeft)
    ON_BN_CLICKED(IDC_BUTTON_TOP_RIGHT, &CMenuTestDlg::OnBnClickedButtonTopRight)
    ON_BN_CLICKED(IDC_BUTTON_BOTTOM_LEFT, &CMenuTestDlg::OnBnClickedButtonBottomLeft)
    ON_BN_CLICKED(IDC_BUTTON_BOTTOM_RIGHT, &CMenuTestDlg::OnBnClickedButtonBottomRight)
    ON_BN_CLICKED(IDC_BUTTON_TOP_VCENTER, &CMenuTestDlg::OnBnClickedButtonTopVcenter)
    ON_BN_CLICKED(IDC_BUTTON_CENTER_LEFT, &CMenuTestDlg::OnBnClickedButtonCenterLeft)
    ON_BN_CLICKED(IDC_BUTTON_CENTER_VCENTER, &CMenuTestDlg::OnBnClickedButtonCenterVcenter)
    ON_BN_CLICKED(IDC_BUTTON_CENTER_RIGHT, &CMenuTestDlg::OnBnClickedButtonCenterRight)
    ON_BN_CLICKED(IDC_BUTTON_BOTTOM_VCENTER, &CMenuTestDlg::OnBnClickedButtonBottomVcenter)
    ON_WM_GETMINMAXINFO()
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

void CMenuTestDlg::HoverChanged(CTransparentButton* btn)
{
    if (btn != m_HoverButton)
    {
        m_HoverButton = btn;
        CRect rc;
        GetClientRect(&rc);
        InvalidateRect(rc);

        CString Text;

        switch (m_HoverButton->GetDlgCtrlID())
        {
        case IDC_BUTTON_TOP_LEFT: Text = "TPM_RIGHTALIGN | TPM_BOTTOMALIGN"; break;
        case IDC_BUTTON_TOP_RIGHT: Text = "TPM_LEFTALIGN | TPM_BOTTOMALIGN"; break;
        case IDC_BUTTON_BOTTOM_LEFT: Text = "TPM_RIGHTALIGN | TPM_TOPALIGN"; break;
        case IDC_BUTTON_BOTTOM_RIGHT: Text = "TPM_LEFTALIGN | TPM_TOPALIGN"; break;
        case IDC_BUTTON_TOP_VCENTER: Text = "TPM_CENTERALIGN | TPM_BOTTOMALIGN"; break;
        case IDC_BUTTON_CENTER_LEFT: Text = "TPM_RIGHTALIGN | TPM_VCENTERALIGN"; break;
        case IDC_BUTTON_CENTER_VCENTER: Text = "TPM_CENTERALIGN | TPM_VCENTERALIGN"; break;
        case IDC_BUTTON_CENTER_RIGHT: Text = "TPM_LEFTALIGN | TPM_VCENTERALIGN"; break;
        case IDC_BUTTON_BOTTOM_VCENTER: Text = "TPM_CENTERALIGN | TPM_TOPALIGN"; break;
        default: __debugbreak();
        }

        SetWindowText(Text);

    }
}


// CMenuTestDlg message handlers

BOOL CMenuTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    CRect rc;
    GetWindowRect(&rc);
    m_MinSize = rc.Size();

    m_BackColor.CreateSolidBrush(RGB(255, 255, 255));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMenuTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
        CPaintDC dc(this); // device context for painting

        if (m_HoverButton)
        {
            CRect rc;
            CRect rcCenter;
            m_HoverButton->GetWindowRect(rc);
            m_ButtonCenterVCenter.GetWindowRect(rcCenter);

            ScreenToClient(&rc);
            ScreenToClient(&rcCenter);
            CPoint selCenter = rc.CenterPoint();
            CPoint center = rcCenter.CenterPoint();


            CRect drawMenu = rcCenter;
            drawMenu.InflateRect(rcCenter.Width() / 4, rcCenter.Height() / 4);

            CPoint drawAt = drawMenu.TopLeft();
            if (selCenter.x < center.x)
            {
                // Right align
                drawAt.x = center.x - drawMenu.Width();
                if (m_Exclude && !m_Vertical)
                    drawAt.x = rcCenter.left - drawMenu.Width();
            }
            else if (selCenter.x > center.x)
            {
                // Left align
                drawAt.x = center.x;
                if (m_Exclude && !m_Vertical)
                    drawAt.x = rcCenter.right;
            }
            else
            {
                // Center align
                if (m_Exclude && !m_Vertical)
                    drawAt.x = rcCenter.right;
            }


            if (selCenter.y < center.y)
            {
                // Bottom align
                drawAt.y = center.y - drawMenu.Height();
                if (m_Exclude && m_Vertical)
                    drawAt.y = rcCenter.top - drawMenu.Height();
            }
            else if (selCenter.y > center.y)
            {
                // Top align
                drawAt.y = center.y;
                if (m_Exclude && m_Vertical)
                    drawAt.y = rcCenter.bottom;
            }
            else
            {
                // Center align
                if (m_Exclude && m_Vertical)
                    drawAt.y = rcCenter.bottom;
            }

            drawMenu.MoveToXY(drawAt);

            center.Offset(-8, -8);
            dc.Draw3dRect(center.x-2, center.y-2, 4, 4, RGB(0, 255, 0), RGB(0, 255, 0));
            rcCenter.InflateRect(-2, -2);
            dc.Draw3dRect(rcCenter, RGB(0, 255, 0), RGB(0, 255, 0));

            dc.Draw3dRect(drawMenu, RGB(255, 0, 0), RGB(255, 0, 0));
        }


        if (PaintWindowlessControls(&dc))
            return;
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMenuTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMenuTestDlg::ShowMenu(UINT Flags)
{
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);
    CPoint pt;
    GetCursorPos(&pt);

    TPMPARAMS tpm = {sizeof(tpm)};
    CWnd* wnd = WindowFromPoint(pt);
    wnd->GetWindowRect(&tpm.rcExclude);

    TPMPARAMS* ptm = m_Exclude ? &tpm : NULL;
    Flags |= (m_Vertical ? TPM_VERTICAL : TPM_HORIZONTAL);
    Flags |= (m_Rtl ? TPM_LAYOUTRTL : 0);

    CMenu* sub = menu.GetSubMenu(0);

    sub->CheckMenuItem(ID_EXCLUDERECTANGLE, MF_BYCOMMAND | (m_Exclude ? MF_CHECKED : MF_UNCHECKED));
    sub->CheckMenuItem(ID_EXCLUDEVERTICAL, MF_BYCOMMAND | (m_Vertical ? MF_CHECKED : MF_UNCHECKED));
    sub->CheckMenuItem(ID_LAYOUTRTL, MF_BYCOMMAND | (m_Rtl ? MF_CHECKED : MF_UNCHECKED));

    switch (sub->TrackPopupMenuEx(Flags | TPM_RETURNCMD | TPM_RIGHTBUTTON, pt.x, pt.y, this, ptm))
    {
    case ID_EXCLUDERECTANGLE:
        m_Exclude = !m_Exclude;
        break;
    case ID_EXCLUDEVERTICAL:
        m_Vertical = !m_Vertical;
        break;
    case ID_LAYOUTRTL:
        m_Rtl = !m_Rtl;
        break;
    }
}


void CMenuTestDlg::OnBnClickedButtonTopLeft()
{
    ShowMenu(TPM_RIGHTALIGN | TPM_BOTTOMALIGN);
}


void CMenuTestDlg::OnBnClickedButtonTopRight()
{
    ShowMenu(TPM_LEFTALIGN | TPM_BOTTOMALIGN);
}


void CMenuTestDlg::OnBnClickedButtonBottomLeft()
{
    ShowMenu(TPM_RIGHTALIGN | TPM_TOPALIGN);
}


void CMenuTestDlg::OnBnClickedButtonBottomRight()
{
    ShowMenu(TPM_LEFTALIGN | TPM_TOPALIGN);
}


void CMenuTestDlg::OnBnClickedButtonTopVcenter()
{
    ShowMenu(TPM_CENTERALIGN | TPM_BOTTOMALIGN);
}


void CMenuTestDlg::OnBnClickedButtonCenterLeft()
{
    ShowMenu(TPM_RIGHTALIGN | TPM_VCENTERALIGN);
}


void CMenuTestDlg::OnBnClickedButtonCenterVcenter()
{
    ShowMenu(TPM_CENTERALIGN | TPM_VCENTERALIGN);
}


void CMenuTestDlg::OnBnClickedButtonCenterRight()
{
    ShowMenu(TPM_LEFTALIGN | TPM_VCENTERALIGN);
}


void CMenuTestDlg::OnBnClickedButtonBottomVcenter()
{
    ShowMenu(TPM_CENTERALIGN | TPM_TOPALIGN);
}


void CMenuTestDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    CDialog::OnGetMinMaxInfo(lpMMI);

    lpMMI->ptMinTrackSize = m_MinSize;
}



HBRUSH CMenuTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    if (nCtlColor == CTLCOLOR_DLG)
    {
        hbr = m_BackColor;
    }

    return hbr;
}
