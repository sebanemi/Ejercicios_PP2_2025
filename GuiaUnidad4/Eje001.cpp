#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* sig;
};

void insertar(Nodo*& cabeza,int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->sig = nullptr;

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
    Nodo* lista = nullptr;
    insertar(lista,5);
    insertar(lista,4);
    insertar(lista,1);
    mostrar(lista);
    liberar(lista);
    return 0;
}