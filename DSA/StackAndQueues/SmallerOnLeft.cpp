// gfg url - https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[i]<=st.top()) st.pop();
            (st.empty())?ans.push_back(-1):ans.push_back(st.top());
            st.push(a[i]);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> result = sol.leftSmaller(n, a);
    cout << "The elements of the result vector are: ";
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}