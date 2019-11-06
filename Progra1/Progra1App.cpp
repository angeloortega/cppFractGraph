/***************************************************************
 * Name:      Progra1App.cpp
 * Purpose:   Code for application class
 * Author:    Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * Created:   2017-09-21
 * Copyright: Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Progra1App.h"
#include "Progra1Main.h"


IMPLEMENT_APP(Progra1App);

bool Progra1App::OnInit()
{

    Progra1Dialog* dlg = new Progra1Dialog(0L, _("FractGraph 2017"));
    dlg->Show();

    return true;
}
