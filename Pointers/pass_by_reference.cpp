#include <iostream>
using namespace std;

void swap_by_address(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}

void swap_by_reference(int* a,int* b){
    int c = *a;
    *a=*b;
    *b= c;
}

int main(){
    int x=10;
    int y=20;
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
    cout<<"&x: "<<&x<<endl<<"&y: "<<&y<<endl<<endl;
    swap_by_address(x,y);
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;

    cout<<"&x: "<<&x<<endl<<"&y: "<<&y<<endl<<endl;
    swap_by_reference(&x,&y);
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
    cout<<"&x: "<<&x<<endl<<"&y: "<<&y<<endl<<endl;

    swap(x,y);
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
    cout<<"&x: "<<&x<<endl<<"&y: "<<&y<<endl<<endl;
    
}