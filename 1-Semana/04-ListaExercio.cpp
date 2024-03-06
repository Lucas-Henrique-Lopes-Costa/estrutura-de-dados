#include <iostream>

using namespace std;

int main(){
    int vetor[5]={0,1,2,3,4};
    
    int a = 8;
    char b = 'x';
    float c = 7;
    double d = 13.1;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    
    cout << "MUITA CACA NESSA HORA!" << endl;

    vetor[-3] = 163;
    vetor[-2] = 198;
    vetor[-1] = 145;
    vetor[6] = 125;
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;    

    return 0;	
}
