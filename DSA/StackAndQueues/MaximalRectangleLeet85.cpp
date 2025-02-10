// leetcode url - https://leetcode.com/problems/maximal-rectangle/description/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
    int maxRectangle(vector<int>& arr){
        stack<int> st;
        int n=arr.size();
        int ans=0;
        arr.push_back(0);
        for(int i=0;i<n+1;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int h=arr[st.top()];st.pop();

                int start=(st.empty())?-1:st.top();
                ans=max(ans,h*(i-start-1));
            }
            st.push(i);
        }

        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> histogram(n);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    histogram[j]=0;
                }else{
                    histogram[j]++;
                }
            }
            ans=max(ans,maxRectangle(histogram));

        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "The maximal rectangle area is: " << result << endl;

    return 0;
}