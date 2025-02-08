// leetcode url - https://leetcode.com/problems/next-greater-element-i/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> st;
        vector<int> ans;
        int n2=nums2.size();
        for(int i=0;i<n2;i++){
            while(!st.empty() && st.top()<nums2[i]){
                umap[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(auto it:nums1){
            if(umap.find(it)==umap.end()) ans.push_back(-1);
            else ans.push_back(umap[it]);
        }

        return ans;
    }

    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> st;
        vector<int> ans;
        int n2=nums2.size();
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            umap[nums2[i]]=(st.empty())?-1:st.top();
            st.push(nums2[i]);
        }

        for(auto it:nums1){
            if(umap.find(it)==umap.end()) ans.push_back(-1);
            else ans.push_back(umap[it]);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return nextGreaterElement2(nums1,nums2);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    cout << "Next greater elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}