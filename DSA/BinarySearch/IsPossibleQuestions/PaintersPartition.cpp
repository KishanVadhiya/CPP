// gfg url - https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool isPossible(vector<int>& arr,int k,int mid){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                k--;
                sum=arr[i];
            }
        }
        
        return k>=1;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        
        int start=0;
        int end=0;
        for(auto it:arr){
            start=max(start,it);
            end+=it;
        }
        
        if(k==arr.size()) return start;
        if(k==1) return end;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(arr,k,mid)){
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
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << "Minimum time to paint: " << sol.minTime(arr, k) << endl;
    return 0;
}