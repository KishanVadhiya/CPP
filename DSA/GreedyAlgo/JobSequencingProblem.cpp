// gfg url - https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job{
    int profit;
    int deadline;
};
class Solution {
    static bool comp(Job j1,Job j2){
        return j1.profit>j2.profit;
    }
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n=id.size();
        int maxDays=*max_element(deadline.begin(),deadline.end());
        vector<int> profitArr(maxDays+1);
        
        vector<Job> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i].profit=profit[i];
            arr[i].deadline=deadline[i];
        }
        
        sort(arr.begin(),arr.end(),comp);
        int ans1=0;
        int ans2=0;
        for(auto it:arr){
            // cout<<"At : "<<it.deadline<<" "<<it.profit<<endl;
            int end=it.deadline;
            while(end>0 && profitArr[end]!=0) end--;
            // cout<<end<<endl;
            if(end>0){
                profitArr[end]=it.profit;
                ans2+=it.profit;
                ans1++;
            }
        }
        
        return {ans1,ans2};
        
    }
};


int main() {
    Solution sol;
    vector<int> id = {1, 2, 3, 4};
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    
    vector<int> result = sol.JobSequencing(id, deadline, profit);
    
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;
    
    return 0;
}