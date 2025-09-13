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
int getSize(Nodo* cabeza) {
    int l = 0;
    while (cabeza != nullptr) {
        cabeza = cabeza->sig;
        l++;
    }
    return l;
}

void invertir(Nodo*& cabeza) {
    Nodo* reverso = nullptr;
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = aux->dato;
        nuevo->sig = reverso;
        reverso = nuevo;
        aux = aux->sig;
    }
    cabeza = reverso;
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
    Nodo* lst = nullptr;
    insertar(lst,5);
    insertar(lst,4);
    insertar(lst,6);
    insertar(lst,3);
    mostrar(lst);
    cout<<"######"<<endl;
    invertir(lst);
    mostrar(lst);
    liberar(lst);
    return 0;
}