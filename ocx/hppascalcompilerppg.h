#if !defined(AFX_HPPASCALCOMPILERPPG_H__6DDE27CC_BEDA_11D3_91D8_525400EA8C8F__INCLUDED_)
#define AFX_HPPASCALCOMPILERPPG_H__6DDE27CC_BEDA_11D3_91D8_525400EA8C8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HPPASCALCompilerPpg.h : Declaration of the CHPPASCALCompilerPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerPropPage : See HPPASCALCompilerPpg.cpp.cpp for implementation.

class CHPPASCALCompilerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHPPASCALCompilerPropPage)
	DECLARE_OLECREATE_EX(CHPPASCALCompilerPropPage)

// Constructor
public:
	CHPPASCALCompilerPropPage();

// Dialog Data
	//{{AFX_DATA(CHPPASCALCompilerPropPage)
	enum { IDD = IDD_PROPPAGE_HPPASCALCOMPILER };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CHPPASCALCompilerPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HPPASCALCOMPILERPPG_H__6DDE27CC_BEDA_11D3_91D8_525400EA8C8F__INCLUDED)
