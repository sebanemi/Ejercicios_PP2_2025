#include <iostream>
using namespace std;

struct Estudiante {
    string Nombre;
    int edad;
};
int main() {
    Estudiante* ptrArr[] = {new Estudiante{"Pepe",10},new Estudiante{"Juan",11},new Estudiante{"Tom",5}};
    for (int i = 0; i < 3; i++) {
        cout <<ptrArr[i]->Nombre<<", "<<ptrArr[i]->edad<<endl;
    }
    for (int i = 0; i < 3; i++) {
        delete ptrArr[i];
    }
    return 0;
}