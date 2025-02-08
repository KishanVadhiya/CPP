// leetcode url - https://leetcode.com/problems/sum-of-subarray-minimums/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
    void leftSmallestEl(vector<int>& arr,vector<int> &ans){
        int n=arr.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?(i+1):i-st.top();
            st.push(i);
        }
    }

    void rightSmallestEl(vector<int>& arr,vector<int> &ans){
        int n=arr.size();
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?(n-i):(st.top()-i);
            st.push(i);
        }
    }

public:
    int sumSubarrayMins1(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n,0);
        // long ans=0;
        stack<int> st;
        int mod=1e9 + 7;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            int j=(st.empty())?-1:st.top();
            // cout<<j<<endl;
            // cout<<((j==-1)?0:res[j]);
            res[i]=((j==-1)?0:res[j]) + (1LL*(i-j)*arr[i])%mod;
            st.push(i);
        }

        long ans=0;
        for(auto it:res){
            ans+=it;
            ans%=mod;
        }

        return ans;
    }

    int sumSubarrayMins2(vector<int>& arr) {
        int n=arr.size();
        vector<int> leftSmallest(n);
        vector<int> rightSmallest(n);

        leftSmallestEl(arr,leftSmallest);
        rightSmallestEl(arr,rightSmallest);

        // for(auto it:leftSmallest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:rightSmallest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans= (ans+ (1L*leftSmallest[i]*rightSmallest[i]*arr[i])%mod)%mod;
        }

        return ans;

    }


    int sumSubarrayMins(vector<int>& arr) {
        return sumSubarrayMins2(arr);
    }
};


int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(arr) << endl;
    return 0;
}