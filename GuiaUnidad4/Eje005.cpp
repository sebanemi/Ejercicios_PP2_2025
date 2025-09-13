#include <iostream>
using namespace std;

struct Nodo{
    string cadena;
    Nodo* sig;
    Nodo* ant;
};

void insertar(Nodo*& lista, string cadena){
    Nodo* nodo = new Nodo;
    nodo->cadena = cadena;
    nodo->sig = nullptr;
    nodo->ant = nullptr;
    if(lista == nullptr) {
        lista = nodo;
        return;
    }
    Nodo* aux;
    aux = lista;
    while(aux->sig != nullptr) {
        aux = aux->sig;
    }
    aux->sig = nodo;
    nodo->ant = aux;
}
void mostrar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout<<cabeza->cadena<<endl;
        cabeza->ant = cabeza;
        cabeza = cabeza->sig;
    }
}

int main() {
    Nodo* lst = nullptr;
    insertar(lst,"Hola");
    insertar(lst,"Chau");
    insertar(lst,"Si");
    mostrar(lst);
    return 0;
}