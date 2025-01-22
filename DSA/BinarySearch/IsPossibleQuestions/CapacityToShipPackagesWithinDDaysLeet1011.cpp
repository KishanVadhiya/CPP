// leetcode url - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool isPossible(vector<int>& arr,int ans,int days){
        int sum=0;
        int cnt=1;
        for(auto it:arr){

            if(sum+it<=ans){
                sum+=it;
            }else{
                cnt++;
                sum=it;
                if(cnt>days) return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=weights[0];
        int end=0;
        for(auto it:weights){
            start=max(start,it);
            end+=it;
        }
        int ans=-1;
        while(start<=end){
            int mid=start + (end-start)/2;

            if(isPossible(weights,mid,days)){
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
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity to ship packages within " << days << " days is: " << result << endl;
    return 0;
}