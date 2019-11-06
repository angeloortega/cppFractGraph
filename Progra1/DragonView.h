/***************************************************************
 * Name:      DragonView.H
 * Purpose:   Code to display Dragon Curve fractal using
 multiple iterations or a single one
 * Author:    Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * Created:   2017-09-21
 * Copyright: Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * License:
 **************************************************************/
#include "wx/wx.h"
#include "wx/sizer.h"
#include "Progra1App.h"
#include "Progra1Main.h"
#include "LinkedList.h"
#include "Grafico.h"
#include "Listas_Fractales.h"

class DragonView : public wxDialog
{

    public:
        DragonView(wxDialog *dlg, const wxString &title, int iteraciones,int r, int g, int b);

    protected:
        enum
        {
            idBtnVolver
        };

    private:
        int iterar; //Number of iterations
        int rc;
        int gc;  //color codes
        int bc;
        void OnClose(wxCloseEvent& event);
        void paintEvent(wxPaintEvent & evt);
        DECLARE_EVENT_TABLE()
        void OnVolver(wxCommandEvent &event);
        int getBrushSize(int i);
        Listas_Fractales dragon; //To create list with the information in order to graph
    };

    BEGIN_EVENT_TABLE(DragonView, wxDialog)
    EVT_PAINT(DragonView::paintEvent)
    EVT_BUTTON(idBtnVolver, DragonView::OnVolver)
    END_EVENT_TABLE()


    DragonView::DragonView(wxDialog *dlg, const wxString &title,int iteraciones, int r, int g, int b)
    : wxDialog(dlg, -1, title)
        {
            //Class constructor which sets the necessary information to generate the fractal.
        this->rc = r;
        this->gc = g;
        this->bc = b;
        this->iterar = iteraciones;
        this->SetSizeHints(1000, 1000);
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        wxButton* BtnVolver = new wxButton(this, idBtnVolver, wxT("&Volver"), wxDefaultPosition, wxDefaultSize, 0);
        this->SetBackgroundColour(wxColour(* wxBLACK));
        sizer->Add(BtnVolver, 0, wxALL, 5);
        this->SetSizer(sizer);
        this->SetAutoLayout(true);
        sizer->Fit(this);
        }

    void DragonView::paintEvent(wxPaintEvent & evt)
    {
        //Creates a list and itereates through it creating a line each iteration and using the Grafico class to calculate the next line to draw
    LinkedList<int> lista;
    lista.append(0);
    for(int i = 0; i<iterar; i++){
        dragon.dragon1(lista);
    }
    int brush = getBrushSize(iterar);
    Grafico dibujar(540-(iterar*10),300+(iterar*10)); //The image starts in different locations because of the sligth shifting between iterations
    lista.goToStart();
    wxClientDC draw(this);
    for(int i= 0; i<lista.getSize(); i++){
        dibujar.guardaPos(lista.getElement(), 90);
        dibujar.avanzar(90,brush);
        draw.SetPen( wxPen( wxColor(rc, gc, bc),1) );
        draw.DrawLine(dibujar.getXIni(), dibujar.getYIni(), dibujar.getXFin(), dibujar.getYFin());
        lista.next();
        }
    }

    int DragonView::getBrushSize(int i){
        // Used to determine the length of the brush, which is how long each segment will be depending on the iterations
    switch(i)
    {
    case 1:
        return 200;

    case 2:
        return 100;

    case 3:
        return 75;

    case 4:
        return 62;

    case 5:
        return 40;

    case 6:
        return 35;

    case 7:
        return 30;

    case 8:
        return 25;

    case 9:
        return 15;

    case 10:
        return 10;

    case 11:
        return 5;

    case 12:
        return 3;

    case 13:
        return 2;

    case 14:
        return 2;

    case 15:
        return 2;

    default:
        return 1;
    }
    return 1;
    }

    void DragonView::OnVolver(wxCommandEvent &event)
    {
        //What happens when the 'Volver' button is pressed
        Destroy();
    }
    void DragonView::OnClose(wxCloseEvent&){
        Destroy();
        }

