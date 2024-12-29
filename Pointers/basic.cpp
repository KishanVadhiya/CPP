#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int* ptr= &a;

    cout<<"a : "<<a<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*(&a): "<<*&a<<endl;
    cout<<"&a: "<<&a<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*(&ptr): "<<*(&ptr)<<endl;
    cout<<"&ptr: "<<&ptr<<endl;
}