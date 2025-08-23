// HPPASCALCompilerCtl.cpp : Implementation of the CHPPASCALCompilerCtrl ActiveX Control class.

#include "stdafx.h"
#include "HP PASCAL Compiler.h"
#include "HPPASCALCompilerCtl.h"
#include "HPPASCALCompilerPpg.h"

#include <process.h>

#include "assembler.h"
#include "MacroCompile.h"
#include "Optimizer.h"
#include "Compiler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CHPPASCALCompilerCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CHPPASCALCompilerCtrl, COleControl)
	//{{AFX_MSG_MAP(CHPPASCALCompilerCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CHPPASCALCompilerCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CHPPASCALCompilerCtrl)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "ErreurFichier", m_erreurFichier, OnErreurFichierChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "Erreur", m_erreur, OnErreurChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "ErreurAbscisse", m_erreurAbscisse, OnErreurAbscisseChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "ErreurOrdonnee", m_erreurOrdonnee, OnErreurOrdonneeChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "FileSource", m_fileSource, OnFileSourceChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "ErreurMessage", m_erreurMessage, OnErreurMessageChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "FileDestination", m_fileDestination, OnFileDestinationChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "DirectorySource", m_directorySource, OnDirectorySourceChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "DirectoryUnit", m_directoryUnit, OnDirectoryUnitChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "DirectoryResource", m_directoryResource, OnDirectoryResourceChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "DirectoryDestination", m_directoryDestination, OnDirectoryDestinationChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "MemoryBITMAP", m_memoryBITMAP, OnMemoryBITMAPChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "MemorySTACK", m_memorySTACK, OnMemorySTACKChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "MemoryRPL", m_memoryRPL, OnMemoryRPLChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "EtapeMessage", m_etapeMessage, OnEtapeMessageChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "EtapeFichier", m_etapeFichier, OnEtapeFichierChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "EtapeJauge", m_etapeJauge, OnEtapeJaugeChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CHPPASCALCompilerCtrl, "Version", m_acces, OnVersionChanged, VT_I4)
	DISP_FUNCTION(CHPPASCALCompilerCtrl, "Compile", Compile, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CHPPASCALCompilerCtrl, "CheckSyntax", CheckSyntax, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CHPPASCALCompilerCtrl, COleControl)
	//{{AFX_EVENT_MAP(CHPPASCALCompilerCtrl)
	EVENT_CUSTOM("Evenement", FireEvenement, VTS_NONE)
	EVENT_CUSTOM("Fini", FireFini, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CHPPASCALCompilerCtrl, 1)
	PROPPAGEID(CHPPASCALCompilerPropPage::guid)
END_PROPPAGEIDS(CHPPASCALCompilerCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CHPPASCALCompilerCtrl, "HPPASCALCOMPILER.HPPASCALCompilerCtrl.1",
	0x6dde27a6, 0xbeda, 0x11d3, 0x91, 0xd8, 0x52, 0x54, 0, 0xea, 0x8c, 0x8f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CHPPASCALCompilerCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DHPPASCALCompiler =
		{ 0x6dde27bc, 0xbeda, 0x11d3, { 0x91, 0xd8, 0x52, 0x54, 0, 0xea, 0x8c, 0x8f } };
const IID BASED_CODE IID_DHPPASCALCompilerEvents =
		{ 0x6dde27bd, 0xbeda, 0x11d3, { 0x91, 0xd8, 0x52, 0x54, 0, 0xea, 0x8c, 0x8f } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwHPPASCALCompilerOleMisc =
	OLEMISC_SIMPLEFRAME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHPPASCALCompilerCtrl, IDS_HPPASCALCOMPILER, _dwHPPASCALCompilerOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::CHPPASCALCompilerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CHPPASCALCompilerCtrl

BOOL CHPPASCALCompilerCtrl::CHPPASCALCompilerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HPPASCALCOMPILER,
			IDB_HPPASCALCOMPILER,
			afxRegApartmentThreading,
			_dwHPPASCALCompilerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::CHPPASCALCompilerCtrl - Constructor

CHPPASCALCompilerCtrl::CHPPASCALCompilerCtrl()
{
	InitializeIIDs(&IID_DHPPASCALCompiler, &IID_DHPPASCALCompilerEvents);

	EnableSimpleFrame();

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::~CHPPASCALCompilerCtrl - Destructor

CHPPASCALCompilerCtrl::~CHPPASCALCompilerCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::OnDraw - Drawing function

void CHPPASCALCompilerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	DoSuperclassPaint(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::DoPropExchange - Persistence support

void CHPPASCALCompilerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::OnResetState - Reset control to default state

void CHPPASCALCompilerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CHPPASCALCompilerCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("STATIC");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::IsSubclassedControl - This is a subclassed control

BOOL CHPPASCALCompilerCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl::OnOcmCommand - Handle command messages

LRESULT CHPPASCALCompilerCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: Switch on wNotifyCode here.

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CHPPASCALCompilerCtrl message handlers

CString CHPPASCALCompilerCtrl::directoryDestination()
{
	return (m_directoryDestination);
}

CString CHPPASCALCompilerCtrl::directorySource()
{
	return (m_directorySource);
}

CString CHPPASCALCompilerCtrl::directoryResource()
{
	return (m_directoryResource);
}

CString CHPPASCALCompilerCtrl::directoryUnit()
{
	return (m_directoryUnit);
}

CString CHPPASCALCompilerCtrl::fileSource()
{
	return (m_fileSource);
}

CString CHPPASCALCompilerCtrl::fileDestination()
{
	return (m_fileDestination);
}

int CHPPASCALCompilerCtrl::memoryBITMAP ()
{
	return (m_memoryBITMAP);
}

int CHPPASCALCompilerCtrl::memorySTACK ()
{
	return (m_memorySTACK);
}

int CHPPASCALCompilerCtrl::memoryRPL ()
{
	return (m_memoryRPL);
}

void CHPPASCALCompilerCtrl::Update ()
{
	FireEvenement ();
}

void CHPPASCALCompilerCtrl::EtapeMessage (CString mess)
{
	m_etapeMessage = mess;
}

void CHPPASCALCompilerCtrl::EtapeFichier (CString mess)
{
	m_etapeFichier = mess;
}

void CHPPASCALCompilerCtrl::EtapeJauge (int i)
{
	m_etapeJauge = i;
}

// Le compilateur
// --------------

void CHPPASCALCompilerCtrl::CompileAux ()
{
	// TODO: Add your dispatch handler code here

	// En mode DEBUG, on génère RESULTAT1,2,3,4.TXT
#ifdef _DEBUG
	bool debug = true;	
#endif
	
#ifdef NDEBUG
	bool debug = false;	
#endif

	// Controle d'accès	

	if (m_acces==65536745) calculatrice=HP48;
	if (m_acces==65536746) calculatrice=HP49;

	if ((unsigned long)(m_acces-65536745)<2)
	{
		
		// Compilation
		
		m_erreur = false;
		
		CCompiler *Compilateur;
		Compilateur = new CCompiler (this);
		Compilateur->DoCompile ();
		
		if (debug) Compilateur->FichierEntree->Debug();
		
		if (Compilateur->Erreur.Message!="")
		{
			m_erreur = true;
			m_erreurOrdonnee = Compilateur->Erreur.Ligne;
			m_erreurAbscisse = Compilateur->Erreur.Abscisse;
			m_erreurMessage = Compilateur->Erreur.Message;			
			m_erreurFichier = Compilateur->Erreur.Fichier;
			FireEvenement();
			FireFini();		
			return;
		}
		
		if (debug) Compilateur->generatedFile->Create();
		
		memoryGlobal = Compilateur->GlobalMemory;
		
		// Optimisation
		
		EtapeMessage ("Optimisation");
		EtapeFichier ("");
		EtapeJauge (0);
		Update();
		
		COptimizer *optimize;
		optimize = new COptimizer(Compilateur->generatedFile, this);
		
		if (debug) optimize->generatedFile->Create();
		
		// Production du code assembleur
		
		EtapeMessage ("Création du code assembleur");
		EtapeFichier ("");
		EtapeJauge (0);
		Update();
		
		CMacroCompile *macrocomp;
		macrocomp = new CMacroCompile (optimize->generatedFile, this);
		
		if (debug) macrocomp->generatedFile->Create();
		
		// Assemblage
		
		EtapeMessage ("Assemblage");
		EtapeFichier ("");
		EtapeJauge (0);
		Update();
		
		CAssembler *assembler;
		assembler = new CAssembler (macrocomp->generatedFile, this);
		
		if (!assembler->Erreur) assembler->StopAssLine();
		
		if (assembler->Erreur)
		{
			m_erreur = true;		
			m_erreurOrdonnee = assembler->ErreurInfos.Ligne;
			m_erreurAbscisse = 1;
			m_erreurMessage = assembler->ErreurInfos.Message;
			m_erreurFichier = assembler->ErreurInfos.Fichier;
		}	
		
		FireEvenement();
		FireFini ();
		return;
	}

}



// Le vérificateur de syntaxe
// --------------------------

void CHPPASCALCompilerCtrl::SyntaxeAux ()
{
	// TODO: Add your dispatch handler code here

	// En mode DEBUG, on génère RESULTAT1,2,3,4.TXT
#ifdef _DEBUG
	bool debug = true;	
#endif
	
#ifdef NDEBUG
	bool debug = false;	
#endif

	// Controle d'accès	

	if (m_acces==65536745)
	{
		
		// Compilation
		
		m_erreur = false;
		
		CCompiler *Compilateur;
		Compilateur = new CCompiler (this);
		Compilateur->DoCheckSyntaxe ();
		
		if (debug) Compilateur->FichierEntree->Debug();
		
		if (Compilateur->Erreur.Message!="")
		{
			m_erreur = true;
			m_erreurOrdonnee = Compilateur->Erreur.Ligne;
			m_erreurAbscisse = Compilateur->Erreur.Abscisse;
			m_erreurMessage = Compilateur->Erreur.Message;			
			m_erreurFichier = Compilateur->Erreur.Fichier;
			FireEvenement();
			FireFini();		
			return;
		}
		
		if (debug) Compilateur->generatedFile->Create();

		FireEvenement();
		FireFini ();
		return;
	}

}



void CHPPASCALCompilerCtrl::OnErreurFichierChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnErreurChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnErreurAbscisseChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnErreurOrdonneeChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnFileSourceChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnErreurMessageChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnFileDestinationChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnDirectorySourceChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnDirectoryUnitChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnDirectoryResourceChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnDirectoryDestinationChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnMemoryBITMAPChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnMemorySTACKChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnMemoryRPLChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnEtapeMessageChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnEtapeFichierChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnEtapeJaugeChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void CHPPASCALCompilerCtrl::OnVersionChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void daube (void *obj)
{
	CHPPASCALCompilerCtrl* objet;
	objet = (CHPPASCALCompilerCtrl*)obj;

	objet->CompileAux();
}

void daube2 (void *obj)
{
	CHPPASCALCompilerCtrl* objet;
	objet = (CHPPASCALCompilerCtrl*)obj;

	objet->SyntaxeAux();
}

BOOL CHPPASCALCompilerCtrl::Compile() 
{
	_beginthread (daube, 0, this);
	return true;
}

BOOL CHPPASCALCompilerCtrl::CheckSyntax() 
{
	// TODO: Add your dispatch handler code here
	_beginthread (daube2, 0, this);
	return true;
}
