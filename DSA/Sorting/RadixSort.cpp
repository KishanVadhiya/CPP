#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countSort(vector<int>& arr,int pos){
    vector<int> cnt(10);
    int n=arr.size();
    for(auto it:arr){
        int digit=(it/pos)%10;
        cnt[digit]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]+=cnt[i-1];
    }
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/pos)%10;
        cnt[digit]--;
        ans[cnt[digit]]=arr[i];
    }


    arr=ans;
}


void radixSort(vector<int>& arr){
    int pos=1;
    int maxi=*max_element(arr.begin(),arr.end());

    while((maxi/pos)>0){
        countSort(arr,pos);
        pos*=10;
    }


}




int main(){
    vector<int> arr={10,102,101,223,21,92};

    radixSort(arr);

    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
}