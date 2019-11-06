/***************************************************************
 * Name:      Grafico.h
 * Purpose:   Class to calculate coordinates given a point,
   a distance and an angle.
 * Author:    Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * Created:   2017-09-21
 * Copyright: Angelo Ramirez Ortega/Guilliano D' Ambrosio
 * License:
 **************************************************************/
#ifndef CLASSGRAFICO_H_INCLUDED
#define CLASSGRAFICO_H_INCLUDED
#include<math.h>

using namespace std;


class Grafico{
private:
    int x_Inicial;
    int x_Final;
    int y_Inicial;
    int y_Final;
    int posicion = 0;
public:
    Grafico(int px_Final, int py_Final, int pPosicion = 0){
        //Sets the initial position (by default right), the final points which will be used as initial in the first iteration
        posicion = pPosicion;
        x_Final = px_Final;
        y_Final = py_Final;
    }
    //Getters and Setters
    int getXIni(){
        return x_Inicial;
    }
    int getXFin(){
        return x_Final;
    }
    int getYIni(){
        return y_Inicial;
    }
    int getYFin(){
        return y_Final;
    }

    void setPos(int pPosicion){
        posicion = pPosicion;
    }
    void setXIni(int x){
        x_Inicial = x;
    }
    void setYIni(int y){
        y_Inicial = y;
    }
    void setXFin(int x){
        x_Final = x;
    }
    void setYFin(int y){
        y_Final = y;
    }
    void avanzar(int angulo, int tamanio){
        //Class which utilizes trigonometry to determine the position of the next points to graph given an angle and a length using the previous position stored
        int pos = posicion;
        int coseno = tamanio*cos(anguloToRadian(angulo))+1;
        int seno = tamanio*sin(anguloToRadian(angulo))+1;
        x_Inicial = x_Final;// Sets the previous final points as initial points
        y_Inicial = y_Final;

        if (pos == 0){
            setPointsWithPos(posicion,tamanio);
        }
        else if(pos%90 == 0){
            setPointsWithPos(posicion,tamanio);
        }
        else if(posicion<360 && posicion>270){
            if(posicion<315||posicion>315){
                x_Final = x_Inicial+coseno;
                y_Final = y_Inicial+seno;
            }
            else{
                x_Final = x_Inicial+seno;
                y_Final = y_Inicial+seno;
            }
        }

        else if (posicion<270&&posicion>180){
            if(posicion<225||posicion>225){
                x_Final = x_Inicial-coseno;
                y_Final = y_Inicial+seno;
            }else{
                x_Final = x_Inicial-seno;
                y_Final = y_Inicial+seno;
            }
        }
        else if (posicion<180&&posicion>90){
            if (posicion>135||posicion<135){
                x_Final = x_Inicial-coseno;
                y_Final = y_Inicial-seno;
            }
            else{
                x_Final = x_Inicial-seno;
                y_Final = y_Final-seno;
            }
        }

        else{
            if (posicion<45||posicion>45){
                x_Final = x_Inicial+coseno;
                y_Final = y_Inicial-seno;
            }
            else{
                x_Final = x_Inicial+seno;
                y_Final = y_Inicial-seno;
            }
        }
    }

    int cambio_posicional(int actual, int operacion, int angulo){
        //Used to change the rotate the positon given an angle
        if(operacion != 0)
        {
            if(actual-angulo<0){
                int temp = 360-(actual+angulo);
                return temp;
            }
            else{
                if (actual-angulo == 360){
                    return 0;
                }
                else{
                    return actual-angulo;
                }
            }
        }
        else
            {
            if (actual+angulo>360){
                int temporal = (actual+angulo)-360;
                return temporal;
            }
            else{
                if (actual+angulo == 360){
                    return 0;
                }
                else{
                    return actual+angulo;
                }
            }
        }
    }
    double anguloToRadian(int angulo){
        //Converts a given angle to its radian equivalent
        return angulo*(3.14/180);
    }
    void guardaPos(int direccion, int angulo){
        if (direccion == 0){
            posicion = cambio_posicional(posicion, 1, angulo);
        }
        else{
            posicion = cambio_posicional(posicion, 0, angulo);
        }
    }

    void setPointsWithPos(int pPosicion, int tamanio){
        //Graphs points only using a position when it is a multiple of 90, bceuase it is only a straight line and doesn't require trigonometry
        switch(pPosicion){
            case 0:
                x_Final = x_Inicial+tamanio;
                y_Final = y_Inicial;
                break;
            case 90:
                x_Final = x_Final;
                y_Final = y_Inicial-tamanio;
                break;
            case 180:
                x_Final = x_Inicial-tamanio;
                y_Final = y_Inicial;
                break;
            case 270:
                x_Final = x_Inicial;
                y_Final = y_Inicial+tamanio;
                break;
        }
    }

};
#endif
