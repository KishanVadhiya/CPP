#include<iostream>
#include<vector>
using namespace std;

void cyclicSort(vector<int>& arr){
    int i=0;
    int n=arr.size();

    while(i<n){
        if(arr[i]==i+1) i++;
        else{
            swap(arr[i],arr[arr[i]-1]);
        }
    }
}


int main(){
    vector<int> arr={9,8,7,6,5,4,1,2,3};
    cyclicSort(arr);
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
}