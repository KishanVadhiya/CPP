#include <iostream>
using namespace std;

int main(){
    int a=10;
    
    int* ptr=&a;

    int** double_ptr=&ptr;

    cout<<"a: "<<a<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"**double_ptr: "<<**double_ptr<<endl;
    cout<<endl;

    cout<<"ptr: "<<ptr<<endl;
    cout<<"&a: "<<&a<<endl;
    cout<<"*double_ptr: "<<*double_ptr<<endl;
    cout<<endl;

    cout<<"&ptr: "<<&ptr<<endl;
    cout<<"double_ptr: "<<double_ptr<<endl;
    cout<<endl;

    cout<<"&double_ptr"<<&double_ptr<<endl;

    return 0;
}