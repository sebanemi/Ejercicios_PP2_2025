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

void duplicados(Nodo*& cabeza) {
    if (cabeza == nullptr) return;

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* prev = actual;
        Nodo* aux = actual->sig;

        // Recorremos lo que sigue del nodo actual
        while (aux != nullptr) {
            if (aux->dato == actual->dato) {
                // Eliminar el nodo duplicado
                prev->sig = aux->sig;
                delete aux;
                aux = prev->sig; // avanzar sin perder referencia
            } else {
                prev = aux;
                aux = aux->sig;
            }
        }
        actual = actual->sig;
    }
}

void mostrar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->sig;
    }
    cout << endl;
}

int main() {
    Nodo* lst = nullptr;
    insertar(lst, 1);
    insertar(lst, 2);
    insertar(lst, 2);
    insertar(lst, 3);
    insertar(lst, 4);
    insertar(lst, 2);
    mostrar(lst);
    duplicados(lst);
    mostrar(lst);
    return 0;
}