#include<iostream>
using namespace std;
struct Punto {
    int x,y;
};
int main() {
    Punto punto = {1,1};
    cout << punto.x << " " << punto.y << endl;
    return 0;
}