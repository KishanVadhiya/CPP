// gfg link - https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod=100000;
        if(start==end) return 0;
        vector<int> steps(mod,1e9);
        queue<pair<int,int>> q;
        q.push({0,start});
        steps[start]=0;
        while(!q.empty()){
            int node=q.front().second;
            int step=q.front().first;
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1<steps[num]){
                    steps[num]=step+1;
                    if(num==end) return steps[num];
                    q.push({step+1,num});
                }
            }
        }
        return -1;
    }
};



int main() {
    Solution sol;
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;
    int result = sol.minimumMultiplications(arr, start, end);
    cout << "Minimum multiplications to reach " << end << " from " << start << " is: " << result << endl;
    return 0;
}