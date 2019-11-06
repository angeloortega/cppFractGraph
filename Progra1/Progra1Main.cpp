/***************************************************************
 * Name:      Progra1Main.cpp
 * Purpose:   Code for Main Application Frame
 * Author:    Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * Created:   2017-09-21
 * Copyright: Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * License:
 **************************************************************/
#include <iostream>
#include <cstdlib>
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "Progra1Main.h"
#include "DragonView.h"
#include "SierpinskiView.h"
#include "LevyCView.h"

using namespace std;
enum wxbuildinfoformat {
    short_f, long_f };

BEGIN_EVENT_TABLE(Progra1Dialog, wxDialog)
    EVT_CLOSE(Progra1Dialog::OnClose)
    EVT_BUTTON(idBtnQuit, Progra1Dialog::OnQuit)
    EVT_BUTTON(idBtnAbout, Progra1Dialog::OnAbout)
    EVT_BUTTON(idBtnLevy, Progra1Dialog::OnLevy)
    EVT_BUTTON(idBtnDragon, Progra1Dialog::OnDragon)
    EVT_BUTTON(idBtnSierpinski, Progra1Dialog::OnSierpinski)
END_EVENT_TABLE()

Progra1Dialog::Progra1Dialog(wxDialog *dlg, const wxString &title)
    : wxDialog(dlg, -1, title)
    //Creates the main window and places all the items needed to interact with it.
{
    this->SetSizeHints(400, 380);
    wxBoxSizer* bSizer1;
    wxBoxSizer* bSizer2;
    wxBoxSizer* bSizer3;
    wxBoxSizer* bSizer4;
    wxBoxSizer* bSizer5;
    bSizer1 = new wxBoxSizer(wxVERTICAL);
    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Por favor seleccione la \ncantidad de iteraciones y\nel fractal por graficar\n"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->SetFont(wxFont(16, 74, 90, 90, false, wxT("Arial")));
    wxStaticText* m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Iteraciones: "), wxDefaultPosition, wxDefaultSize, 0);
    wxStaticText* m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Rojo: "), wxDefaultPosition, wxDefaultSize, 0);
    wxStaticText* m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Verde: "), wxDefaultPosition, wxDefaultSize, 0);
    wxStaticText* m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("Azul: "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText2->SetFont(wxFont(12, 74, 90, 90, false, wxT("Arial")));
    iterationEntry = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(45, wxDefaultCoord),0,wxDefaultValidator,wxTextCtrlNameStr);
    redEntry = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(60, wxDefaultCoord),0,wxDefaultValidator,wxTextCtrlNameStr);
    greenEntry = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(60, wxDefaultCoord),0,wxDefaultValidator,wxTextCtrlNameStr);
    blueEntry = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(60, wxDefaultCoord),0,wxDefaultValidator,wxTextCtrlNameStr);
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticText1, 0, wxALIGN_CENTER | wxTOP | wxRIGHT | wxBOTTOM, 5);
    bSizer2->Add(m_staticline1, 0, wxALL|wxEXPAND, 5);
    BtnQuit = new wxButton(this, idBtnQuit, wxT("&Salir"), wxDefaultPosition, wxDefaultSize, 0);
    wxButton* BtnLevy = new wxButton(this, idBtnLevy, wxT("&Levy"), wxDefaultPosition, wxDefaultSize, 0);
    wxButton* BtnDragon = new wxButton(this, idBtnDragon, wxT("&Dragon"), wxDefaultPosition, wxDefaultSize, 0);
    wxButton* BtnSierpinski = new wxButton(this, idBtnSierpinski, wxT("&Sierpinski"), wxDefaultPosition, wxDefaultSize, 0);
    BtnAbout = new wxButton(this, idBtnAbout, wxT("&Acerca De"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnLevy, 0, wxALL, 5);
    bSizer2->Add(BtnDragon, 0, wxALL, 5);
    bSizer2->Add(BtnSierpinski, 0, wxALL, 5);
    bSizer3->Add(BtnAbout, 0, wxALL, 5);
    bSizer3->Add(BtnQuit, 0, wxALL, 5);
    bSizer4->Add(m_staticText2, 0, wxALL, 3);
    bSizer4->Add(iterationEntry,0,wxALL,3);
    bSizer5->Add(m_staticText3, 0, wxALL, 3);
    bSizer5->Add(redEntry,0,wxALL,3);
    bSizer5->Add(m_staticText4, 0, wxALL, 3);
    bSizer5->Add(greenEntry,0,wxALL,3);
    bSizer5->Add(m_staticText5, 0, wxALL, 3);
    bSizer5->Add(blueEntry,0,wxALL,3);
    bSizer1->Add(bSizer5, 0, wxALIGN_CENTER | wxTOP | wxRIGHT | wxBOTTOM, 5);
    bSizer1->Add(bSizer4, 0, wxALIGN_CENTER | wxTOP | wxRIGHT | wxBOTTOM, 5);
    bSizer1->Add(bSizer2, 0, wxALIGN_CENTER | wxTOP | wxRIGHT | wxBOTTOM, 5);
    bSizer1->Add(bSizer3, 0, wxALIGN_CENTER | wxTOP | wxRIGHT | wxBOTTOM,5);


    this->SetSizer(bSizer1);

    this->Layout();

    bSizer1->Fit(this);
}


Progra1Dialog::~Progra1Dialog()
{
}

void Progra1Dialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void Progra1Dialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void Progra1Dialog::OnAbout(wxCommandEvent &event)
{
    //About button pressed event
    wxString msg = "Angelo Ramirez Ortega-2017080055\nGuilliano D'Ambrosio-2017158561\n";
    wxMessageBox(msg, "Acerca de");
}
void Progra1Dialog::OnLevy(wxCommandEvent &event)
{
    //Validates Levy C Curve event and creates a new frame in case they are correct
    wxString x = iterationEntry->GetValue();
    wxString r1 = redEntry->GetValue();
    wxString g1 = greenEntry->GetValue();
    wxString b1 = blueEntry->GetValue();
    string entry = string(x.mb_str());
    string r2 = string(r1.mb_str());
    string g2 = string(g1.mb_str());
    string b2 = string(b1.mb_str());
    if(entry.find_first_not_of("0123456789") == string::npos && entry != "" && r2 != "" && g2 != "" && b2 != "")
    {
        int entryInt = atoi(entry.c_str());
        int r = atoi(r2.c_str());
        int g = atoi(g2.c_str());
        int b = atoi(b2.c_str());
        if(entryInt  > 0 && entryInt < 14){
                if(checkColors(r,g,b))
                {
                LevyCView* wframe = new LevyCView(this,_("Levy C"),entryInt,r,g,b);
                wframe->ShowWindowModal();
                }
                else{
                    wxMessageBox( wxT("Los colores deben estar entre 1 y 255"), wxT("Error de colores"), wxICON_INFORMATION);
                }
        }
        else{
            wxMessageBox( wxT("Las iteraciones deben ser un numero entre 1 y 13"), wxT("Error de iteraciones"), wxICON_INFORMATION);
        }
    }
    else{
        wxMessageBox( wxT("Las iteraciones deben ser un numero"), wxT("Error de iteraciones"), wxICON_INFORMATION);
    }
}
void Progra1Dialog::OnDragon(wxCommandEvent &event)
{
    //Validates Dragon Curve event and creates a new frame in case they are correct
    wxString x = iterationEntry->GetValue();
    wxString r1 = redEntry->GetValue();
    wxString g1 = greenEntry->GetValue();
    wxString b1 = blueEntry->GetValue();
    string entry = string(x.mb_str());
    string r2 = string(r1.mb_str());
    string g2 = string(g1.mb_str());
    string b2 = string(b1.mb_str());
    if(entry.find_first_not_of("0123456789") == string::npos && entry != "" && r2 != "" && g2 != "" && b2 != "")
    {
        int entryInt = atoi(entry.c_str());
        int r = atoi(r2.c_str());
        int g = atoi(g2.c_str());
        int b = atoi(b2.c_str());
        if(entryInt  > 0 && entryInt < 17){
                if(checkColors(r,g,b))
                {
                    DragonView* wframe = new DragonView(this,_("Fractal Dragon"),entryInt,r,g,b);
                    wframe->ShowWindowModal();
                }
                else{
                    wxMessageBox( wxT("Los colores deben estar entre 1 y 255"), wxT("Error de colores"), wxICON_INFORMATION);
                }
        }
        else{
            wxMessageBox( wxT("Las iteraciones deben ser un numero entre 1 y 16"), wxT("Error de iteraciones"), wxICON_INFORMATION);
        }
    }
    else{
        wxMessageBox( wxT("Las iteraciones deben ser un numero"), wxT("Error de iteraciones"), wxICON_INFORMATION);
    }
}
void Progra1Dialog::OnSierpinski(wxCommandEvent &event)
{
    //Validates Sierpinski Curve event and creates a new frame in case they are correct
    wxString x = iterationEntry->GetValue();
    wxString r1 = redEntry->GetValue();
    wxString g1 = greenEntry->GetValue();
    wxString b1 = blueEntry->GetValue();
    string entry = string(x.mb_str());
    string r2 = string(r1.mb_str());
    string g2 = string(g1.mb_str());
    string b2 = string(b1.mb_str());
    if(entry.find_first_not_of("0123456789") == string::npos && entry != "" && r2 != "" && g2 != "" && b2 != "")
    {
        int entryInt = atoi(entry.c_str());
        int r = atoi(r2.c_str());
        int g = atoi(g2.c_str());
        int b = atoi(b2.c_str());
        if(entryInt  > 0 && entryInt < 9){
            if(checkColors(r,g,b))
            {
            SierpinskiView* wframe = new SierpinskiView(this,_("Triangulo Sierpinski"),entryInt,r,g,b);
            wframe->ShowWindowModal();
            }
            else{
                    wxMessageBox( wxT("Los colores deben estar entre 1 y 255"), wxT("Error de colores"), wxICON_INFORMATION);
                }
        }
        else{
            wxMessageBox( wxT("Las iteraciones deben ser un numero entre 1 y 8"), wxT("Error de iteraciones"), wxICON_INFORMATION);
        }
    }
    else{
        wxMessageBox( wxT("Las iteraciones deben ser un numero"), wxT("Error de iteraciones"), wxICON_INFORMATION);
    }
}

bool Progra1Dialog::checkColors(int r, int g, int b){
    //Receibes color codes and determines if they are in the correct range.
    if(r > 0 && r<256){
        if(g > 0 && g<256){
            if(b > 0 && b<256){
            return true;
            }
        }
    }
    return false;
}

