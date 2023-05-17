#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {

    int tam=2;
    float arr1[]={1.4,2.3};
    string arr2[]={"ana","aquino","mamani"};

    DynamicArray<int> pi;
    cout << pi.getSize() << endl;

    DynamicArray<float> pf(arr1, tam);

    DynamicArray<string> ps(arr2, 3);

    cout << endl;

    pi.print();

    pf.insert(4.2,1);
    pf.print();

    cout << endl;
    
    ps.remove(1);
    ps.print();

    return 0;
}