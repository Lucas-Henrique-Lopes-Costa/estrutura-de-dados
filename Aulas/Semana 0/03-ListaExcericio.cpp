#include <iostream>

using namespace std;

int main()
{
    int aux;
    int *auxPtr;

    cout << "TRECHO PERIGOSO" << endl;
    cout << "Valor de aux:" << aux << endl;
    cout << "Endereço de aux:" << &aux << endl;
    cout << "Valor de auxPtr:" << auxPtr << endl;
    cout << "Valor apontado por auxPtr:" << *auxPtr << endl;

    aux = 7;
    auxPtr = &aux;

    cout << "TRECHO SEGURO" << endl;
    cout << "Valor de aux:" << aux << endl;
    cout << "Endereço de aux:" << &aux << endl;
    cout << "Valor de auxPtr:" << auxPtr << endl;
    cout << "Valor apontado por auxPtr:" << *auxPtr << endl;

    return 0;
}
