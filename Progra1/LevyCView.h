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
class LevyCView: public wxDialog
{

    public:
        LevyCView(wxDialog *dlg, const wxString &title, int iteraciones, int r, int g, int b);

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
        DECLARE_EVENT_TABLE()
        void OnVolver(wxCommandEvent &event);
        int getBrushSize(int i);
        Listas_Fractales LevyCl;
    };

    BEGIN_EVENT_TABLE(LevyCView, wxDialog)
    EVT_PAINT(LevyCView::paintEvent)
    EVT_BUTTON(idBtnVolver, LevyCView::OnVolver)
    END_EVENT_TABLE()


    LevyCView::LevyCView(wxDialog *dlg, const wxString &title,int iteraciones, int r, int g, int b)
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

    void LevyCView::paintEvent(wxPaintEvent & evt)
    {
        //Creates a list and itereates through it creating a line each iteration and using the Grafico class to calculate the next line to draw
    int brush = getBrushSize(iterar);
    LinkedList<int> lista;
    lista.append(2);
    for(int i = 0; i<iterar;i++){
        LevyCl.LevyCl1(lista);
    }
    lista.goToStart();
    wxClientDC draw(this);
    Grafico dibujar(200, 200);
    for(int i = 0; i<lista.getSize(); i++){
        if(lista.getElement()!=2){
            dibujar.guardaPos(lista.getElement(), 45); //Given that not on every iteration of the Levy C curve draws a line, the position needs
                                                       //to be kept and shifted while iterating through the list.
        } else{
            dibujar.avanzar(45,brush);
            draw.SetPen( wxPen( wxColor(rc, gc, bc),1) );
            draw.DrawLine(dibujar.getXIni(), dibujar.getYIni(), dibujar.getXFin(), dibujar.getYFin());
        }
        lista.next();
    }
    }

    int LevyCView::getBrushSize(int i){
    switch(i)
    {
        // Used to determine the length of the brush, which is how long each segment will be depending on the iterations
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
        return 8;

    case 12:
        return 6;

    case 13:
        return 4;

    case 14:
        return 2;

    case 15:
        return 1;

    default:
        return 1;
    }
    return 1;
    }

    void LevyCView::OnVolver(wxCommandEvent &event)
    {
        Destroy();
    }
    void LevyCView::OnClose(wxCloseEvent&){
        Destroy();
        }


