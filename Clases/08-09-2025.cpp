#include<iostream>
using namespace std;

//Estructuras dinámicas
struct Nodo
{
    int numero;
    Nodo* sig;
};

//Listas doblemente enlazadas
struct Doble
{
    int valor;
    Doble* sig;
    Doble* ant;
};

int main()
{
    //Reservo memoria dinamicamente en la memoria HEAP
    int* ptr = new int;
    *ptr = 72;
    cout<<*ptr<<endl;
    delete ptr;

    //Uso de estructura dinámica
    Nodo* n = new Nodo;
    n->numero = 18;
    n->sig = nullptr;
    cout<<"Numero de nodo: "<<n->numero<<endl;
    delete n;

    //Estructuras auto-referenciadas
    Nodo* cabeza = new Nodo;
    Nodo* n1 = new Nodo{1,nullptr};
    Nodo* n2 = new Nodo{2,nullptr};
    n1->sig = n2;
    cabeza = n1;
    for (Nodo* aux = cabeza; aux != nullptr; aux = aux->sig )
    {
        cout<<"Valor nodo: "<<aux->numero<<endl;
    }
    delete cabeza;
    delete n2;

    /*
     *Lista doblemente enlazada:
     *Estructura de datos con dos puntero, uno al siguiente y otro al anterior
     *Principales operaciones: agregar al inicio, al final, eliminar del principio, del final, mostrar
     */
    Doble* cabecera = new Doble;
    Doble* d1 = new Doble{1,nullptr,nullptr};
    cabecera = d1;
    Doble* d2 = new Doble{2,nullptr,d1};
    d1->sig = d2;
    Doble* d3 = new Doble{3, nullptr,d2};
    d2->sig = d3;
    for (Doble* aux = cabecera;aux!=nullptr;aux = aux->sig)
    {
        cout<<"Actual: " <<aux->valor<<", Anterior: "<<aux->ant->valor<<endl;
    }
    for (Doble* aux = cabecera;aux!=nullptr;aux = aux->sig)
    {
        delete aux;
    }


    return 0;
}
