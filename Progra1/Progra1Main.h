/***************************************************************
 * Name:      Progra1Main.h
 * Purpose:   Defines Main Application Frame
 * Author:    Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * Created:   2017-09-21
 * Copyright: Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * License:
 **************************************************************/

#ifndef PROGRA1MAIN_H
#define PROGRA1MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Progra1App.h"
#include <wx/button.h>
#include <wx/statline.h>
class Progra1Dialog: public wxDialog
{
    public:
        Progra1Dialog(wxDialog *dlg, const wxString& title);
        ~Progra1Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout,
            idBtnLevy,
            idBtnSierpinski,
            idBtnDragon
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;
        wxTextCtrl* iterationEntry;
        wxTextCtrl* redEntry;
        wxTextCtrl* greenEntry;
        wxTextCtrl* blueEntry;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDragon(wxCommandEvent& event);
        void OnLevy(wxCommandEvent& event);
        void OnSierpinski(wxCommandEvent& event);
        bool checkColors(int r, int g, int b);
        DECLARE_EVENT_TABLE()
};

#endif // PROGRA1MAIN_H
