#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    getline(cin,s);

    cout<<s<<endl;
    cout<<s.length()<<endl;

    for(char i:s){
        cout<<i<<endl;
    }
}