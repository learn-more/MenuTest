#pragma once


// CTransparentButton

class CTransparentButton : public CButton
{
	DECLARE_DYNAMIC(CTransparentButton)

public:
	CTransparentButton();
	virtual ~CTransparentButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


