#include <iostream>
using namespace std;

struct NodoDoble {
    int dato;
    NodoDoble* sig;
    NodoDoble* ant;
};
struct NodoSimple {
    int dato;
    NodoSimple* sig;
};

void insertarDoble(NodoDoble*& cabeza,int n) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = n;
    nuevo->sig = nullptr;
    nuevo->ant = nullptr;

    if(cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }
    NodoDoble* aux = cabeza;
    while(aux->sig != nullptr) {
        aux = aux->sig;
    }
    aux->sig = nuevo;
    nuevo->ant = aux;
}

void insertarSimple(NodoSimple*& cabeza,int n) {
    NodoSimple* nuevo = new NodoSimple;
    nuevo->dato = n;
    nuevo->sig = nullptr;

    if(cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }
    NodoSimple* aux = cabeza;
    while(aux->sig != nullptr) {
        aux = aux->sig;
    }
    aux->sig = nuevo;
}

NodoSimple* dobleToSimple(NodoDoble* cabeza) {
    NodoSimple* simple = nullptr;
    while (cabeza!=nullptr) {
        insertarSimple(simple,cabeza->dato);
        cabeza = cabeza->sig;
    }
    return simple;
}

void mostrar(NodoSimple* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->sig;
    }
    cout << endl;
}
void mostrar(NodoDoble* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->sig;
    }
    cout << endl;
}

void liberar(NodoSimple*& cabeza) {
    NodoSimple* aux;
    while (cabeza != nullptr) {
        aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
    }
}
void liberar(NodoDoble*& cabeza) {
    NodoDoble* aux;
    while (cabeza != nullptr) {
        aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
    }
}

int main() {
    NodoDoble* lst = nullptr;
    insertarDoble(lst, 10);
    insertarDoble(lst, 20);
    insertarDoble(lst, 30);
    insertarDoble(lst, 40);
    mostrar(lst);

    NodoSimple* lst_simp = dobleToSimple(lst);
    mostrar(lst_simp);
    return 0;
}