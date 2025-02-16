// gfg url - https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Meeting{
    int start;
    int end;
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(Meeting m1,Meeting m2){
        return m1.end<m2.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<Meeting> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i].start=start[i];
            arr[i].end=end[i];
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        
        
        int cnt=0;
        int freeAt=-1;
        
        for(auto it:arr){
            // cout<<it.start<<" "<<it.end<<endl;
            if(it.start>freeAt){
                cnt++;
                freeAt=it.end;
            }
        }
        
        return cnt;
    }
};


int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    
    Solution sol;
    int maxMeetings = sol.maxMeetings(start, end);
    
    cout << "Maximum number of meetings: " << maxMeetings << endl;
    
    return 0;
}