// leetcode url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy=INT_MAX;
            int ans=0;
            int n=prices.size();
            for(int i=0;i<n;i++){
                buy=min(buy,prices[i]);
                ans=max(ans,prices[i]-buy);
            }
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << "Max Profit: " << sol.maxProfit(prices) << endl;
        return 0;
    }