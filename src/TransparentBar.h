/*____________________________________________________________________________

   ExifPro Image Viewer

   Copyright (C) 2000-2015 Michael Kowalski
____________________________________________________________________________*/

#if !defined(AFX_TRANSPARENTBAR_H__6EA7403D_2EE4_4AA1_838D_59C1B71C0D38__INCLUDED_)
#define AFX_TRANSPARENTBAR_H__6EA7403D_2EE4_4AA1_838D_59C1B71C0D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TransparentBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTransparentBar window

class CTransparentBar : public CToolBarCtrl
{
// Construction
public:
	CTransparentBar();

// Attributes
public:

// Operations
public:
	bool Create(CWnd* parent, UINT id);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransparentBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTransparentBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTransparentBar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSPARENTBAR_H__6EA7403D_2EE4_4AA1_838D_59C1B71C0D38__INCLUDED_)
