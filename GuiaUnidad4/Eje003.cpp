#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

void insertar(Nodo*& cabeza,int n,int& l) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->sig = nullptr;
    l++;

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }

    Nodo* p = cabeza;
    while (p->sig != nullptr) {
        p = p->sig;
    }
    p->sig = nuevo;
}

//n es el nodo a eliminar
void eliminar(Nodo*& cabeza, int n, int& l) {
    if (n>l || cabeza == nullptr) {
        return;
    }
    l--;
    Nodo* act = cabeza;
    Nodo* ant = nullptr;
    if (n == 1) {
        cabeza = cabeza->sig;
        delete act;
        return;
    }
    for (int i =0; i < n; i++) {
        ant = act;
        act = act->sig;
    }
    ant->sig = act->sig;
    delete act;
}

void mostrar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout<<cabeza->dato<<endl;
        cabeza = cabeza->sig;
    }
}

void liberar(Nodo*& cabeza) {
    Nodo* aux;
    while (cabeza != nullptr) {
        aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
    }
}

int main() {
    int lstLength = 0;
    Nodo* lista = nullptr;
    insertar(lista, 1, lstLength);
    insertar(lista, 2, lstLength);
    insertar(lista, 3, lstLength);
    cout<<"La lista es:"<<lstLength<<endl;
    mostrar(lista);
    //No tomo por subindices sino por numero de elemento
    eliminar(lista, 1, lstLength);
    cout<<"La lista es:"<<lstLength<<endl;
    mostrar(lista);
    liberar(lista);
    return 0;
}