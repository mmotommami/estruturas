#ifndef NODODE_H
#define NODODE_H

#include <string>
#include <iostream>

using namespace std;

class NodoDE {
private:
    string titulo;
    int vistas;
    NodoDE* sig;
    NodoDE* ant;

public:
    NodoDE(string titular, int visitas) {
        titulo = titular;
        vistas = visitas;
        sig = NULL;
        ant = NULL;
    }

    NodoDE(string titular, int visitas, NodoDE* siguiente, NodoDE* anterior) {
        titulo = titular;
        vistas = visitas;
        sig = siguiente;
        ant = anterior;
    }

    void imprimir() {
        cout << titulo << endl << endl;
        cout << vistas << endl << endl;

    }

    friend class listaDE;
};

typedef NodoDE* nodoP;

class listaDE {
private:
    nodoP inicio;
    nodoP fin;

public:
    listaDE() {
        inicio = NULL;
        fin = NULL;
    }

    int tamano();

    int indice(nodoP nodoB);

    void imprimir();

    void insertarFinal(nodoP nodoI);

    void insertarPosicion(nodoP nodoI, int pos);

    void eliminarElemento(int pos);

    nodoP buscarNodo(int pos);

    void moverPos(int posInicial, int posFinal);

};

#endif