// leetcode url - https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
    public:
        int largestRectangleArea(vector<int>& arr) {
            stack<int> st;
            int n=arr.size();
            int ans=0;
            arr.push_back(0);
            for(int i=0;i<n+1;i++){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    int h=arr[st.top()];
                    st.pop();
                    int start=(st.empty())?-1:st.top();
    
                    ans=max(ans,(h*(i-start-1)));
                    
                }
                st.push(i);
            }
            return ans;
        }
    };

    int main() {
        Solution sol;
        vector<int> histogram = {2, 1, 5, 6, 2, 3};
        int maxArea = sol.largestRectangleArea(histogram);
        cout << "The largest rectangle area is: " << maxArea << endl;
        return 0;
    }