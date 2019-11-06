#include "DragonView.h"

//(*InternalHeaders(DragonView)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(DragonView)
const long DragonView::ID_AXIS1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DragonView,wxDialog)
	//(*EventTable(DragonView)
	//*)
END_EVENT_TABLE()

DragonView::DragonView(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DragonView)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Axis1 = new mpScaleX(_("XY"), 1, true);
	this->AddLayer(Axis1);
	//*)
}

DragonView::~DragonView()
{
	//(*Destroy(DragonView)
	//*)
}

