// leetcode url - https://leetcode.com/problems/binary-subarrays-with-sum/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int numSubarraysWithSum1(vector<int>& nums, int goal) {
            int n=nums.size();
            int start=0,end=0,ans=0;
    
            if(goal==0){
                while(end<n){
                    while(end<n && nums[end]==0){
                        end++;
                    }
                    ans+=((end-start)*(end-start+1))/2;
                    start=++end;
                }
                return ans;
            }
    
            while(start<n){
                if(nums[start]==1){
                    break;
                }
                start++;
            }
            if(start==n) return 0;
            end=start;
            while(goal>0 && end<n){
                goal-=nums[end];
                if(goal==0) break;
                end++;
            }
            if(goal>0) return 0;
            int prevOne=-1;
            int nextOne=end+1;
            // cout<<"before : nextOne"<<nextOne<<endl;
            while(end<n){
                while(nextOne<n && nums[nextOne]==0){
                    nextOne++;
                }
                // cout<<"prevOne: "<<prevOne<<"start: "<<start<<" end: "<<end<<"nextOne: "<<nextOne<<endl;
                ans+=(start-prevOne)*(nextOne-end);
                prevOne=start++;
                end=nextOne++;
                // start++;
                while(start<n && nums[start]==0) start++;
            }
    
    
            return ans;
        }
    
    
        int numSubarraysWithSum2(vector<int>& nums, int goal) {
            return findSubarrayLessThanSumK(nums,goal)-findSubarrayLessThanSumK(nums,goal-1);
        }
    
        int findSubarrayLessThanSumK(vector<int>& nums,int goal){
            if(goal<0) return 0;
    
            int start=0;
            int cnt=0;
            int n=nums.size();
            for(int end=0;end<n;end++){
                goal-=nums[end];
                while(goal<0){
                    goal+=nums[start++];
                }
    
                cnt+= end-start+1;
            }
            return cnt;
        }
    
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return numSubarraysWithSum2(nums,goal);
        }
    };


    int main() {
        Solution sol;
        vector<int> nums = {1, 0, 1, 0, 1};
        int goal = 2;
        cout << "Number of subarrays with sum " << goal << " is: " << sol.numSubarraysWithSum(nums, goal) << endl;
        return 0;
    }