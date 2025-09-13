#include <iostream>
using namespace std;

struct Nodo {
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

bool search(Nodo* cabeza,int n) {
    while (cabeza != nullptr) {
        if (cabeza->dato == n) {
            return true;
        }
        cabeza = cabeza->sig;
    }
    return false;
}

int main() {
    Nodo* lst = nullptr;
    insertar(lst, 1);
    insertar(lst, 2);
    insertar(lst, 3);
    insertar(lst, 4);

    int valor;
    cout<<"Ingrese valor:";
    cin>>valor;

    if (search(lst, valor)) {
        cout<<"El numero pertenece"<<endl;
    }else {
        cout<<"El numero no pertenece"<<endl;
    }
    return 0;
}