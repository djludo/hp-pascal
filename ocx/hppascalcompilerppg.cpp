// HPPASCALCompilerPpg.cpp : Implementation of the CHPPASCALCompilerPropPage property page class.

#include "stdafx.h"
#include "HP PASCAL Compiler.h"
#include "HPPASCALCompilerPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHPPASCALCompilerPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHPPASCALCompilerPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CHPPASCALCompilerPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHPPASCALCompilerPropPage, "HPPASCALCOMPILER.HPPASCALCompilerPropPage.1",
	0x6dde27be, 0xbeda, 0x11d3, 0x91, 0xd8, 0x52, 0x54, 0, 0xea, 0x8c, 0x8f)


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerPropPage::CHPPASCALCompilerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CHPPASCALCompilerPropPage

BOOL CHPPASCALCompilerPropPage::CHPPASCALCompilerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HPPASCALCOMPILER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerPropPage::CHPPASCALCompilerPropPage - Constructor

CHPPASCALCompilerPropPage::CHPPASCALCompilerPropPage() :
	COlePropertyPage(IDD, IDS_HPPASCALCOMPILER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CHPPASCALCompilerPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerPropPage::DoDataExchange - Moves data between page and properties

void CHPPASCALCompilerPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CHPPASCALCompilerPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerPropPage message handlers
