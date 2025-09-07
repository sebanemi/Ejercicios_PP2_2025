#include <iostream>
using namespace std;

struct Circulo {
    double radio;
};
double area(Circulo c) {
    return 3.14159 * c.radio * c.radio;
}
int main() {
    Circulo circulo = {3.4};
    cout << area(circulo)<<endl;
    Circulo circulo2 = {2.5};
    cout << area(circulo2)<<endl;
    return 0;
}