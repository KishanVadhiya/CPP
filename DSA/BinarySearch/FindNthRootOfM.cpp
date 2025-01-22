// gfg url - https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m
#include<iostream>
#include<climits>
using namespace std;
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int start=0;
        int end=m;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            long ans=mid;
            bool broke=false;
            for(int i=1;i<n;i++){
                ans*=mid;
                if(ans>INT_MAX){
                    end=mid-1;
                    broke=true;
                    break;
                }
            }
            if(broke) continue;
            
            if(ans==m) return mid;
            else if(ans>m) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n, m;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of m: ";
    cin >> m;
    
    int result = sol.nthRoot(n, m);
    if (result == -1) {
        cout << "No integer nth root of " << m << " exists." << endl;
    } else {
        cout << "The " << n << "th root of " << m << " is " << result << "." << endl;
    }
    
    return 0;
}