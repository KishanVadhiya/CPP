// gfg url - https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
      // Function to get the maximum total value in the knapsack.
      static bool comp(pair<int,int> &a,pair<int,int> &b){
          return a.first/(1.0*a.second)>b.first/(1.0*b.second);
      }
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // Your code here
          vector<pair<int,int>> arr;
          int n=val.size();
          for(int i=0;i<n;i++){
              arr.push_back({val[i],wt[i]});
          }
          
          sort(arr.begin(),arr.end(),comp);
          double ans=0;
          for(auto it:arr){
              if(capacity>it.second){
                  ans+=it.first;
                  capacity-=it.second;
              }else{
                  ans+= capacity*(it.first/(1.0*it.second));
                  break;
              }
          }
          
          return ans;
      }
  };


int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    Solution sol;
    double maxValue = sol.fractionalKnapsack(values, weights, capacity);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}