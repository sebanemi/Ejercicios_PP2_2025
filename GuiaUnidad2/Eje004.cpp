#include<iostream>
using namespace std;
struct Empleado {
    string nombre;
    double salario;
    string depto;
};
int main() {
    Empleado e1 = {"Pedro",4.2,"a"};
    Empleado e2 = {"Pedra",5.0,"b"};
    Empleado e3 = {"Pedri",6.0,"c"};

    double prom = (e1.salario + e2.salario + e3.salario)/3;
    cout<<"El promedio es: "<< prom;
    return 0;
}