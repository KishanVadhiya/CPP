// leetcode url - https://leetcode.com/problems/single-number-ii/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    int bitIndex(vector<int>& arr){
        int n=arr.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]&(1<<i)) cnt++;
            }
            // cout<<i<<" "<<cnt<<endl;
            if(cnt%3==1)    ans=ans| (1<<i);
        }

        return ans;
    }

    int sortApproach(vector<int>& arr){

        int n=arr.size();
        if(n==1) return arr[0];
        sort(arr.begin(),arr.end());

        for(int i=1;i<n;i+=3){
            if(arr[i-1]!=arr[i]) return arr[i-1];
        }
        return arr[n-1];
    }

    int optimal(vector<int>& arr){
        int ones=0,twos=0;

        for(auto it:arr){
            ones=(ones^it) & (~twos);
            twos=(twos^it) & (~ones);
        }
        return ones;
    }
public:
    int singleNumber(vector<int>& nums) {
        // return bitIndex(nums);
        // return sortApproach(nums);
        return optimal(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << "The single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}