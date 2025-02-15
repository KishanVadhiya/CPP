// leetcode url - https://leetcode.com/problems/fruit-into-baskets/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int arrSize=1e5;
            vector<int> cnt(arrSize);
            int k=2;
            int n=fruits.size();
            int start=0,end=0,ans=0;
    
            while(end<n){
                if(cnt[fruits[end]]>0){
                    cnt[fruits[end++]]++;
                }else{
                    if(k>0){
                        cnt[fruits[end++]]++;
                        k--;
                    }else{
                        while(k==0){
                            cnt[fruits[start]]--;
                            if(cnt[fruits[start++]]==0){
                                k++;
                            }
                        }
                    }
                }
    
                ans=max(ans,end-start);
            }
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> fruits = {1, 2, 1, 2, 3, 2, 2, 2};
        cout << "Maximum number of fruits: " << sol.totalFruit(fruits) << endl;
        return 0;
    }