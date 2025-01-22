// leetcode url -https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& arr,int ans,int m,int k){
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n && m>0;i++){
            if(arr[i]<=ans){
                cnt++;
                if(cnt==k){
                    m--;
                    cnt=0;
                }
            }else{
                if(ans==12){
                    cout<<i<<endl;
                }
                cnt=0;
            }

            // cout<<"At arr["<<i<<"]"<<" : "<<arr[i]<<endl;
            // cout<<"m: "<<m<<endl;
            // cout<<"k: "<<k<<endl;
            // cout<<"cnt: "<<cnt<<endl;
        }

        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=INT_MAX;
        int end=INT_MIN;

        int n=bloomDay.size();

        for(int i=0;i<n;i++){
            start=min(start,bloomDay[i]);
            end=max(end,bloomDay[i]);
        }
        int sol=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPossible(bloomDay,mid,m,k)){
                sol=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return sol;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days to make " << m << " bouquets: " << result << endl;
    return 0;
}