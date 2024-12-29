#include <iostream>
using namespace std;

int main(){
    int arr[5]={10,20,30,40,50};

    int* ptr=arr;

    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"*ptr+1: "<<*(ptr+1)<<endl;
    cout<<"*ptr+2: "<<*(ptr+2)<<endl;
    cout<<"*ptr+3: "<<*(ptr+3)<<endl;
    cout<<"*ptr+4: "<<*(ptr+4)<<endl;

    cout<<endl;
    cout<<"arr: "<<arr<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"&arr: "<<&arr<<endl;

    cout<<endl;
    cout<<"ptr + 1: "<<ptr+1<<endl;
    cout<<"&arr[1]: "<<&arr[1]<<endl;
    
    cout<<endl;
    cout<<"ptr + 2: "<<ptr+2<<endl;
    cout<<"&arr[2]: "<<&arr[2]<<endl;

    cout<<endl;
    cout<<"ptr + 3: "<<ptr+3<<endl;
    cout<<"&arr[3]: "<<&arr[3]<<endl;

    cout<<endl;
    cout<<"ptr + 4: "<<ptr+4<<endl;
    cout<<"&arr[4]: "<<&arr[4]<<endl;


    return 0;
}