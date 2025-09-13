#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

void insertarOrdenado(Nodo*& cabeza,int n) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = nullptr;
    if (cabeza == nullptr || cabeza->dato > n) {
        nuevo->sig = cabeza;
        cabeza = nuevo;
        return;
    }
    Nodo* act = cabeza;
    while (act->sig != nullptr && act->sig->dato < n) {
        act = act->sig;
    }
    nuevo->sig = act->sig;
    act->sig = nuevo;
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

Nodo* fusionar(Nodo* lst1, Nodo* lst2) {
    Nodo* fus_lst = nullptr;

    //Cargo todos los datos de las dos listas
    while (lst1 != nullptr) {
        insertarOrdenado(fus_lst, lst1->dato);
        lst1 = lst1->sig;
    }
    while (lst2 != nullptr) {
        insertarOrdenado(fus_lst, lst2->dato);
        lst2 = lst2->sig;
    }

    //Analizar los duplicados
    duplicados(fus_lst);

    return fus_lst;
}

void mostrar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->sig;
    }
    cout << endl;
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
    Nodo* lst1 = nullptr;
    insertarOrdenado(lst1,0);
    insertarOrdenado(lst1,6);
    insertarOrdenado(lst1,1);
    insertarOrdenado(lst1,2);
    insertarOrdenado(lst1,3);
    mostrar(lst1);

    Nodo* lst2 = nullptr;
    insertarOrdenado(lst2,2);
    insertarOrdenado(lst2,3);
    insertarOrdenado(lst2,4);
    insertarOrdenado(lst2,1);
    mostrar(lst2);

    cout << "Fusionada: "<<endl;
    Nodo* fus_lst = fusionar(lst1,lst2);
    mostrar(fus_lst);

    liberar(lst1);
    liberar(lst2);
    liberar(fus_lst);
    return 0;
}