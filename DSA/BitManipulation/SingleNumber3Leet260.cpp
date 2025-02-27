// leetcode url - https://leetcode.com/problems/single-number-iii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            long xorOfUnique=0;
            for(auto it:nums){
                xorOfUnique^=it;
            }
    
            int rightMostDifferentBit= (xorOfUnique&(xorOfUnique-1))^xorOfUnique;
            int bucket1=0;
            int bucket2=0;
            for(auto it:nums){
                if(it&rightMostDifferentBit){
                    bucket1^=it;
                }else{
                    bucket2^=it;
                }
            }
    
            return vector<int>{bucket1,bucket2};
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {1, 2, 1, 3, 2, 5};
        vector<int> result = sol.singleNumber(nums);
        cout << "The two unique numbers are: " << result[0] << " and " << result[1] << endl;
        return 0;
    }