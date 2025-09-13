#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* sig;
};

void addFirst(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->valor = valor;
    nuevo->sig = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }

    nuevo->sig = cabeza;
    cabeza = nuevo;
}
void mostrar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout<<cabeza->valor<<endl;
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
    addFirst(lista, 1);
    addFirst(lista, 2);
    addFirst(lista, 3);
    addFirst(lista, 4);
    mostrar(lista);
    liberar(lista);
    return 0;
}