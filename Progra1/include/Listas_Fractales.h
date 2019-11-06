#ifndef LISTAS_FRACTALES_H
#define LISTAS_FRACTALES_H



class Listas_Fractales
{
    public:
        //Listas_Fractales();
        //~Listas_Fractales();

void LevyCl1(LinkedList<int> &lista) throw(runtime_error){
    LinkedList<int> retorna;
    int tamano = lista.getSize();
    lista.goToStart();
    int primero = lista.getElement();
    int i = 0;
    while (i<tamano){
        lista.goToPos(i);
        int elemento = lista.getElement();
        if(elemento == 2){
            retorna.append(0);
            retorna.append(2);
            retorna.append(1);
            retorna.append(1);
            retorna.append(2);
            retorna.append(0);
        }
        else{
            retorna.append(elemento);
        }
        i++;
    }
    lista.clear();
    retorna.goToStart();
    for (int i = 0; i<retorna.getSize();i++){
        lista.append(retorna.getElement());
        retorna.next();
    }
}

void sierpinski1(LinkedList<int> &lista) throw(runtime_error){
    LinkedList<int> retorna;
    int tamano = lista.getSize();
    lista.goToStart();
    int primero = lista.getElement();
    int i = 0;
    while (i<tamano){
        lista.goToPos(i);
        int elemento = lista.getElement();
        if (primero == 0){
            retorna.append(1);
            retorna.append(1);
            retorna.append(elemento);
            primero = 1;
        }
        else{
            retorna.append(0);
            retorna.append(0);
            retorna.append(elemento);
            primero = 0;
        }
      i++;
    }
    lista.goToStart();
    if(lista.getElement() == 1){
        retorna.append(0);
        retorna.append(0);
    }
    else{
        retorna.append(1);
        retorna.append(1);
    }
    int tamano2 = retorna.getSize();
    lista.clear();
    retorna.goToStart();
    for (int i = 0; i<tamano2;i++){
        lista.append(retorna.getElement());
        retorna.next();
        }
    }

void dragon1(LinkedList<int> &lista) throw(runtime_error){
    lista.goToStart();
    int auxiliar  = 0;
    int indice = 0;
    while(indice<= lista.getSize()){
        if (auxiliar == 0){
            lista.insert(0);
            lista.next();
            lista.next();
            auxiliar = 1;
            indice++;
        }
        else{
            lista.insert(1);
            lista.next();
            lista.next();
            auxiliar = 0;
            indice++;
        }
        indice++;
    }
}
};

#endif // LISTAS_FRACTALES_H
