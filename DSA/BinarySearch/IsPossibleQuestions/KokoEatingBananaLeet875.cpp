// leetcode url - https://leetcode.com/problems/koko-eating-bananas/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& arr,int h,int speed){
        int n=arr.size();
        for(int i=0;i<n && h>=0;i++){
            h-=(arr[i]/speed + (arr[i]%speed!=0));
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=0;
        for(auto it:piles){
            end=max(end,it);
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(piles,h,mid)){
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
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}