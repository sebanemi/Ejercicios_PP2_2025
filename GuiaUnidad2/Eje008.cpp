#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
};
int main() {
    Producto* ptr;
    ptr = new Producto{"a",1.1,2};
    cout << ptr->nombre << ", "<<ptr->precio<<", "<<ptr->cantidad<< endl;
    delete ptr;
    return 0;
}