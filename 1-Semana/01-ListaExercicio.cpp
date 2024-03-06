#include <iostream>

using namespace std;

int main(){
        cout << "char " << sizeof(char) << endl;
        cout << "short " << sizeof(short) << endl;
        cout << "int " << sizeof(int) << endl;
        cout << "long " << sizeof(long) << endl;
        cout << "long long " << sizeof(long long) << endl;
        
        cout << "float " << sizeof(float) << endl;
        cout << "double " << sizeof(double) << endl;
        cout << "long double " << sizeof(long double) << endl;

        cout << "bool " << sizeof(bool) << endl;


        cout << "bool " << sizeof(int*) << endl;
        cout << "bool " << sizeof(string) << endl;
                
        return 0;
}
