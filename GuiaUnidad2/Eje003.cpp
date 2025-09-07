#include<iostream>
using namespace std;
struct Fecha {
    int dia;
    int mes;
    int ano;
};
struct Persona {
    string nombre;
    Fecha fechaNacimiento;
};
int main() {
    Persona persona1 = {"Juan",{16,4,2006}};
    cout <<"Nombre:"<<persona1.nombre << endl;
    cout <<"Fecha nacimiento:"<<persona1.fechaNacimiento.dia <<"/"<<persona1.fechaNacimiento.mes<<"/"<<persona1.fechaNacimiento.ano<<endl;
    return 0;
}