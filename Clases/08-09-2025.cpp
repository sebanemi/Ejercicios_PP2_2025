#include<iostream>
using namespace std;

//Estructuras dinámicas
struct Nodo
{
    int numero;
    Nodo* sig;
};

int main(){
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

    return 0;
}
