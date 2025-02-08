// leetcode url - https://leetcode.com/problems/trapping-rain-water/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int stIdx=st.top(); st.pop();
                if(st.empty()) break;
                int width=i-st.top()-1;

                ans+=((min(height[st.top()],height[i])-height[stIdx])*width);
                // cout<<"at i : "<<i<<" ans ; "<<ans<<endl;
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped rain water: " << sol.trap(height) << endl;
    return 0;
}