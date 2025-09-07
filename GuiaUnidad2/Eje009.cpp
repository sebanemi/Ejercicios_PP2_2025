#include <iostream>
using namespace std;
enum TipoDato {E,D,C};
union Dato {
    int e;
    double d;
    char c;
};
void mostrar(Dato d, TipoDato t) {
    switch (t) {
        case E:
            cout <<"Entero:" <<d.e << endl;
            break;
        case D:
            cout <<"Double:" <<d.d<<endl;
            break;
        case C:
            cout <<"Character:" <<d.c<<endl;
            break;
    }
}

int main() {
    Dato d;
    d.e=1;
    mostrar(d,E);
    d.d=1.1;
    mostrar(d,D);
    d.c='A';
    mostrar(d,C);
    return 0;
}