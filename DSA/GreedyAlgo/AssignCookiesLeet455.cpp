// leetcode url -https://leetcode.com/problems/assign-cookies/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            int i=0,j=0;
            int n1=g.size(),n2=s.size();
    
            while(i<n1 && j<n2){
                if(s[j]>=g[i]){
                    i++;
                }
                j++;
            }
    
            return i;
        }
};


int main() {
    Solution solution;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << "Number of content children: " << solution.findContentChildren(g, s) << endl;
    return 0;
}