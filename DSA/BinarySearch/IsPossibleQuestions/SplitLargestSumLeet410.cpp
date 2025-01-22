// leetcode url - https://leetcode.com/problems/split-array-largest-sum/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool isPossible(vector<int> &arr,int k,int mid){
        // int maxPages=0;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sum=arr[i];
                k--;
            }
        }
        return k>=1;
    }
public:
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        if(n<k) return -1;
        
        int start=0,end=0;
        for(auto it:arr){
            start=max(start,it);
            end+=it;
        }
        
        if(n==k) return start;
        if(k==1) return end;
        // cout<<start<<" "<<end<<endl;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(arr,k,mid)){
                // cout<<"Inside if block"<<endl;
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    int result = sol.splitArray(arr, k);
    cout << "The minimum largest sum is: " << result << endl;
    return 0;
}