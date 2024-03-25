#include <iostream>

using namespace std;

int main(){
    int a=20;
    cout << &a << endl;

    int v[5];
    cout << v << endl;
    cout << &v << endl;
    cout << &v[0]<< endl;
		
	return 0;	
}
