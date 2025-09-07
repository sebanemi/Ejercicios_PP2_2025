#include <iostream>
using namespace std;
struct Persona {
    string Nombre;
    int edad;
};
int main() {
    Persona arr[] = {{"jose",10},{"pedro",15},{"manu",11}};
    for (int i = 0; i < 3; i++) {
        cout << arr[i].Nombre << ", " << arr[i].edad << endl;
    }
    return 0;
}