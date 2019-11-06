/***************************************************************
 * Name:      LevyCView.h
 * Purpose:   Code to display Levy C Curve fractal using
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
class SierpinskiView : public wxDialog
{

    public:
        SierpinskiView(wxDialog *dlg, const wxString &title, int iteraciones, int r, int g, int b);

    protected:
        enum
        {
            idBtnVolver
        };

    private:
        int iterar;
        int rc;
        int gc;
        int bc;
        void OnClose(wxCloseEvent& event);
        void paintEvent(wxPaintEvent & evt);
        void paintNow();
        DECLARE_EVENT_TABLE()
        void OnVolver(wxCommandEvent &event);
        void sierpinskil(LinkedList<int> &lista)throw(runtime_error);
        int getBrushSize(int i);
        Listas_Fractales sierpinski;
    };

    BEGIN_EVENT_TABLE(SierpinskiView, wxDialog)
    EVT_PAINT(SierpinskiView::paintEvent)
    EVT_BUTTON(idBtnVolver, SierpinskiView::OnVolver)
    END_EVENT_TABLE()


    SierpinskiView::SierpinskiView(wxDialog *dlg, const wxString &title,int iteraciones, int r, int g, int b)
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
        this->SetBackgroundColour(wxColour(* wxBLACK)); //Changes background color to black so fractal colors look better
        sizer->Add(BtnVolver, 0, wxALL, 5);
        this->SetSizer(sizer);
        this->SetAutoLayout(true);
        sizer->Fit(this);
        }

    void SierpinskiView::paintEvent(wxPaintEvent & evt)
    {
    //Creates a list and itereates through it creating a line each iteration and using the Grafico class to calculate the next line to draw
    LinkedList<int> lista;
    lista.append(0);
    lista.append(0);
    for(int i = 0; i<iterar; i++){
        sierpinski.sierpinski1(lista);
    }
    int inix, iniy;
    if(iterar%2==0){
    inix = 800;
    iniy = 600;
    }
    else{
    inix = 900;
    iniy = 100;
    }
    Grafico dibujar(inix, iniy);
    dibujar.setPos(180);
    lista.goToStart();
    int brush = getBrushSize(iterar);
    wxClientDC draw(this);
    for(int i= 0; i<lista.getSize(); i++){
        dibujar.guardaPos(lista.getElement(), 60);
        dibujar.avanzar(60, brush);
        draw.SetPen( wxPen( wxColor(rc, gc, bc),1) );
        draw.DrawLine(dibujar.getXIni(), dibujar.getYIni(), dibujar.getXFin(), dibujar.getYFin());
        lista.next();
        }
    }

    int SierpinskiView::getBrushSize(int i){
    switch(i)
    {
        // Used to determine the length of the brush, which is how long each segment will be depending on the iterations
    case 1:
        return 128;

    case 2:
        return 64;

    case 3:
        return 32;

    case 4:
        return 16;

    case 5:
        return 10;

    case 6:
        return 4;

    case 7:
        return 2;

    case 8:
        return 1;

    default:
        return 1;
    }
    return 0;
    }

    void SierpinskiView::OnVolver(wxCommandEvent &event)
    {
        Destroy();
    }
    void SierpinskiView::OnClose(wxCloseEvent&){
        Destroy();
        }

