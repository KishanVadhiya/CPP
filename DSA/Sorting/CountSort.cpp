#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int>& arr){
    int k=0;
    for(auto it:arr) k=max(it,k);

    vector<int> cnt(k+1);

    for(auto it:arr) cnt[it]++;

    int n=arr.size();
    // for(auto it:cnt) cout<<it<<" ";
    // cout<<endl;

    for(int i=1;i<n;i++){ // for positions
        cnt[i]+=cnt[i-1];
    }

    // for(auto it:cnt) cout<<it<<" ";
    // cout<<endl;

    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        cnt[arr[i]]--;
        ans[cnt[arr[i]]]=arr[i];
    }

    return ans;
}


int main(){
    vector<int> arr={7,5,3,5,7,2,6,8,10,1,0,0,0,3,1};

    vector<int> ans=countSort(arr);

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}