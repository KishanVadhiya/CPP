// gfg url - https://www.geeksforgeeks.org/problems/aggressive-cows/0
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std ;
class Solution {
  public:
    bool isPossible(vector<int>& nums,int k,int mid){
        int pos1=0;
        k--;
        for(int i=1;i<nums.size() && k>0;i++){
            if(abs(nums[i]-nums[pos1])>=mid){
                k--;
                pos1=i;
            }
        }
        return k==0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int start=0;
        int end= stalls[stalls.size()-1];
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(stalls,k,mid)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "The largest minimum distance is: " << sol.aggressiveCows(stalls, k) << endl;
    return 0;
}