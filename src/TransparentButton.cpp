// TransparentButton.cpp : implementation file
//

#include "stdafx.h"
#include "MenuTestDlg.h"
#include "TransparentButton.h"


// CTransparentButton

IMPLEMENT_DYNAMIC(CTransparentButton, CButton)

CTransparentButton::CTransparentButton()
{

}

CTransparentButton::~CTransparentButton()
{
}


BEGIN_MESSAGE_MAP(CTransparentButton, CButton)
ON_WM_MOUSEMOVE()
ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



void CTransparentButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC dc;
    dc.Attach(lpDrawItemStruct->hDC);

    CRect rt = lpDrawItemStruct->rcItem;

    UINT nEdge = (lpDrawItemStruct->itemState & ODS_SELECTED) ? EDGE_SUNKEN : EDGE_RAISED;
    dc.DrawEdge(rt, nEdge, BF_RECT);

    //CString strTemp;
    //GetWindowText(strTemp);

    //dc.SetTextColor(RGB(0, 0, 0));
    //dc.DrawText(strTemp, rt, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    dc.Detach();
}


void CTransparentButton::OnMouseMove(UINT nFlags, CPoint point)
{
    CButton::OnMouseMove(nFlags, point);


    CMenuTestDlg* dlg = (CMenuTestDlg*)GetParent();
    dlg->HoverChanged(this);
}


HBRUSH CTransparentButton::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
    pDC->SetBkMode(TRANSPARENT);
    return (HBRUSH)GetStockObject(NULL_BRUSH);
}
