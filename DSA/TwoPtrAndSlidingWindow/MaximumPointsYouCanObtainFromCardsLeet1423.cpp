// leetcode url - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int sum=0;
            int n=cardPoints.size();
            for(int i=n-k;i<n;i++){
                sum+=cardPoints[i];
            }
    
            int ans=sum;
            int start=n-k;
            int end=0;
    
            while(end<k){
                sum-=cardPoints[start++];
                sum+=cardPoints[end++];
                ans=max(ans,sum);
            }
    
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
        int k = 3;
        int result = sol.maxScore(cardPoints, k);
        cout << "Maximum points you can obtain: " << result << endl;
        return 0;
    }