#include<iostream>
using namespace std;
int* getPointer(int valor) {
    int* ptr = new int;
    *ptr = valor;
    return ptr;
}
int main() {
    int* ptrVal;
    ptrVal = getPointer(25);
    cout << *ptrVal << endl;
    delete ptrVal;
    return 0;
}