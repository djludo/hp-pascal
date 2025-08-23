#if !defined(AFX_HPPASCALCOMPILER_H__6DDE27C3_BEDA_11D3_91D8_525400EA8C8F__INCLUDED_)
#define AFX_HPPASCALCOMPILER_H__6DDE27C3_BEDA_11D3_91D8_525400EA8C8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// HP PASCAL Compiler.h : main header file for HP PASCAL COMPILER.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerApp : See HP PASCAL Compiler.cpp for implementation.

class CHPPASCALCompilerApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HPPASCALCOMPILER_H__6DDE27C3_BEDA_11D3_91D8_525400EA8C8F__INCLUDED)
