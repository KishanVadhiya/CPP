// leetcode url - https://leetcode.com/problems/sum-of-subarray-ranges/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    void leftSmallestEl(vector<int>& arr,vector<int>& ans){
        stack<int> st;
        int n=arr.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]= (st.empty())?i+1:i-st.top();
            st.push(i);
        }
    }
    
    void rightSmallestEl(vector<int>& arr,vector<int>& ans){
        stack<int> st;
        int n=arr.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]= (st.empty())?n-i:st.top()-i;
            st.push(i);
        }
    }


    void leftLargestEl(vector<int>& arr,vector<int>& ans){
        stack<int> st;
        int n=arr.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]= (st.empty())?i+1:i-st.top();
            st.push(i);
        }
    }
    
    void rightLargestEl(vector<int>& arr,vector<int>& ans){
        stack<int> st;
        int n=arr.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]= (st.empty())?n-i:st.top()-i;
            st.push(i);
        }
    }


public:
    long long subArrayRanges(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        vector<int> leftSmallest(n);
        vector<int> rightSmallest(n);
        vector<int> leftLargest(n);
        vector<int> rightLargest(n);

        leftSmallestEl(arr,leftSmallest);
        rightSmallestEl(arr,rightSmallest);
        leftLargestEl(arr,leftLargest);
        rightLargestEl(arr,rightLargest);

        for(int i=0;i<n;i++){
            ans+=(1LL*rightLargest[i]*leftLargest[i])*arr[i] - (1LL*rightSmallest[i]*leftSmallest[i])*arr[i];
        }

        // for(auto it:rightSmallest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        // for(auto it:leftSmallest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:rightLargest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        // for(auto it:leftLargest){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    cout << sol.subArrayRanges(arr) << endl;
    return 0;
}