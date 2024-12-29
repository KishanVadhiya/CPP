#include <iostream>
using namespace std;

int main(){
    char s[] = "12345678";

    char st[10];

    cin.getline(st,20);
    cin>>st;


    cout<<st<<endl;

    cout<<s<<endl;
    cout<<(sizeof(s)/sizeof(s[0]));

    return 0;
}