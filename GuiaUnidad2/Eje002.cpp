#include<iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double cal;
};
int main() {
    Estudiante estudiante1;
    cout<<"Introduzione el nombre: ";
    getline(cin,estudiante1.nombre);
    cout<<"Introduzione el edad: ";
    cin>>estudiante1.edad;
    cout<<"Introduzione la calificacion: ";
    cin>>estudiante1.cal;

    cout<<"\n Data ingresada:"<<endl;
    cout<<estudiante1.nombre<<endl;
    cout<<estudiante1.edad <<endl;
    cout<<estudiante1.cal<<endl;
    return 0;
}