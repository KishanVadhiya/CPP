#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort0to1(vector<float>& arr){
    int n=arr.size();
    vector<vector<float>> buckets(n);
    for(int i=0;i<n;i++){
        int idx=arr[i]*n;
        buckets[idx].push_back(arr[i]);
    }
    int curr=0;
    for(int i=0;i<n;i++){
        sort(buckets[i].begin(),buckets[i].end());
        for(auto it:buckets[i]){
            arr[curr++]=it;
        }
    }
}
void bucketSortRange(vector<float>& arr){
    int n=arr.size();
    vector<vector<float>> buckets(n);
    float maxi=*max_element(arr.begin(),arr.end());
    float mini=*min_element(arr.begin(),arr.end());
    float range=(maxi-mini)/range;
    for(int i=0;i<n;i++){
        int idx=(arr[i]-mini)/range;
        buckets[idx].push_back(arr[i]);
    }
    int curr=0;
    for(int i=0;i<n;i++){
        sort(buckets[i].begin(),buckets[i].end());
        for(auto it:buckets[i]){
            arr[curr++]=it;
        }
    }
}



int main(){
    vector<float> arr={0.1,0.01,0.5,0.43,0.41,0.9,0.1,0.44};
    bucketSort0to1(arr);
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
    vector<float> arr2={0.1,0.01,0.5,0.43,0.41,0.9,1.1,10.44};
    bucketSortRange(arr2);
    for(auto it:arr2) cout<<it<<" ";
    cout<<endl;
}