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

        void imprimir(){
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
        listaDE(){
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

int listaDE::tamano() {
    int i = 0;
    if (inicio != NULL) {
        i = 1;
        nodoP aux = inicio;
        while (aux != fin) {
            i++;
            aux = aux -> sig;
        }
    }
    return i;
}

int listaDE::indice(nodoP nodoB) {
    nodoP aux = inicio;
    int i = 0;
    while ((aux != NULL)) {
        if (aux == nodoB) {
            return i;
        }
        i++;
        aux = aux -> sig;
    }
    return -1;
}

void listaDE::imprimir() {
    nodoP aux = inicio;
    while (aux != NULL) {
        cout << aux -> titulo << " -> ";
        aux = aux -> sig;
    }
    return;
}

void listaDE::insertarFinal(nodoP nodoI) {
    if (inicio == NULL) {
        inicio = nodoI;
        fin = inicio;
    } else {
        fin -> sig = nodoI;
        nodoI -> ant = fin;
        fin = nodoI;
    }
    return;
}

void listaDE::insertarPosicion(nodoP nodoI, int pos) {
    if ((pos <= tamano()) && (pos >= 0)) {
        nodoP aux = inicio;
        cout << tamano() << endl << endl << pos << endl << endl << endl;
        if (pos == 0) {
            inicio = nodoI;
            inicio -> sig = aux;
            aux -> ant = inicio;
        } else if (pos == tamano()) {
            insertarFinal(nodoI);
        } else {
            while (pos > 1) {
                aux = aux -> sig;
                pos--;
            }
            nodoP temp = aux -> sig;
            aux -> sig = nodoI;
            temp -> ant = nodoI;
            nodoI -> sig = temp;
            nodoI -> ant = aux;
        }
    }
    return;
}

void listaDE::eliminarElemento(int pos) {
    if ((pos < tamano()) && (pos >= 0)) {
        nodoP aux = inicio;
        if (pos == 0) {
            inicio = inicio -> sig;
            aux = NULL;
            delete(aux);
        } else if (pos == (tamano() - 1)) {
            aux = fin;
            fin = fin -> ant;
            fin -> sig = NULL;
            aux = NULL;
            delete(aux);
        } else {
            while (pos > 1) {
                aux = aux -> sig;
                pos--;
            }
            nodoP temp = aux -> sig;
            nodoP temp2 = aux -> sig -> sig;
            aux -> sig = temp2;
            temp2 -> ant = aux;
            temp = NULL;
            delete(temp);
        }
    }
    return;
}

nodoP listaDE::buscarNodo(int pos) {
    nodoP aux = NULL;
    if (inicio != NULL) {
        if ((pos < tamano()) && (pos >= 0)) {
            aux = inicio;
            while ((aux != fin) && (pos > 0)) {
                aux = aux -> sig;
                pos--;
            }
        }
    }
    cout << aux -> titulo << endl << endl;
    return aux;
}

void listaDE::moverPos(int posInicial, int posFinal) {
    if (posInicial == posFinal) {
        return;
    }
    nodoP aux = inicio;
    while (posInicial > 0) {
        aux = aux -> sig;
        posInicial--;
    }
    nodoP temp = aux -> ant;
    nodoP temp2 = aux -> sig;
    aux -> sig = NULL;
    aux -> ant = NULL;
    temp -> sig = temp2;
    temp2 -> ant = temp;
    temp = inicio;
    if (posFinal == 0) {
        aux -> sig = inicio;
        inicio -> ant = aux;
        inicio = aux;
    }
    else if (posFinal == tamano()) {
        insertarFinal(aux);
    } else {
        while (posFinal > 0) {
            temp = temp -> sig;
            posFinal--;
        }
        temp2 = temp -> ant;
        temp2 -> sig = aux;
        temp -> ant = aux;
        aux -> ant = temp2;
        aux -> sig = temp;
    }
    return;
}

int main() {
    listaDE* lista = new listaDE();

    // Agregar algunos titulares
    nodoP ejemplo = new NodoDE("Este es un ejemplo", 10);
    nodoP ejemplo2 = new NodoDE("Este es otro ejemplo", 11);
    nodoP ejemplo3 = new NodoDE("Este es un ejemplo3", 12);
    nodoP ejemplo4 = new NodoDE("Este es otro ejemplo4", 13);
    lista->insertarFinal(ejemplo);
    lista->insertarFinal(ejemplo2);
    lista->insertarFinal(ejemplo3);
    lista->insertarFinal(ejemplo4);

    // Imprimir la lista
    cout << "Lista inicial:" << endl;
    lista->imprimir();
    cout << endl;

    // Buscar y mostrar un nodo por posición
    int posBusqueda = 2;
    nodoP nodoBuscado = lista->buscarNodo(posBusqueda);
    if (nodoBuscado != nullptr) {
        cout << "Nodo en la posición " << posBusqueda << ":" << endl;
        nodoBuscado->imprimir();
    } else {
        cout << "Nodo en la posición " << posBusqueda << " no encontrado." << endl;
    }
    cout << endl;

    // Eliminar un nodo por posición
    int posEliminacion = 1;
    lista->eliminarElemento(posEliminacion);
    cout << "Lista después de eliminar el nodo en la posición " << posEliminacion << ":" << endl;
    lista->imprimir();
    cout << endl;

    // Mover un nodo a otra posición
    int posInicial = 3;
    int posFinal = 0;
    lista->moverPos(posInicial, posFinal);
    cout << "Lista después de mover el nodo de la posición " << posInicial << " a la posición " << posFinal << ":" << endl;
    lista->imprimir();
    cout << endl;

    // Limpieza de memoria
    delete ejemplo;
    delete ejemplo2;
    delete ejemplo3;
    delete ejemplo4;
    delete lista;

    return 0;
}





