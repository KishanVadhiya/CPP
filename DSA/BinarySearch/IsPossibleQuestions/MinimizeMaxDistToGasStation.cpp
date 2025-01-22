// gfg url - https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/0
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
    bool isPossible(vector<int>& arr,int &n,int k,double mid){
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>mid){
                int inBetween=((arr[i]-arr[i-1])/mid);
                if((arr[i]-arr[i-1])/mid==inBetween*mid){
                    inBetween--;
                }
                k-=inBetween;
            }
        }
        return k>=0;
    }
  public:
   double findSmallestMaxDistHeap(vector<int> &arr,int k){
        priority_queue<pair<double,int>> pq;
        int n=arr.size();
        vector<int> intervals(n-1);

        for(int i=1;i<n;i++){
            double gap=arr[i]-arr[i-1];
            pq.push({gap,i-1});
        }

        for(int i=0;i<k;i++){
            // cout<<"heap top before: "<<pq.top().first<<endl;
            int idx=pq.top().second;pq.pop();
            intervals[idx]++;
            // cout<<"Increased station at interval : "<<idx<<endl;
            double gap=round((arr[idx+1]-arr[idx])/double(intervals[idx]+1)*100.0)/100.0;
            // cout<<"gap : "<<gap<<endl;
            pq.push({gap,idx});
            // cout<<"heap top: "<<pq.top().first<<endl;

        }
        return (pq.top().first);
    }
    
    double findSmallestMaxDistBS(vector<int> &arr, int k) {
        // Code here
        double start=0;
        double end=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            end=max(end,double(arr[i]-arr[i-1]));
        }
        if(k==0) return end;
        start=end/(k+1);
        
        double diff=1e-6;
        
        while(end-start>diff){
            double mid=(start+end)/2;
            
            if(isPossible(arr,n,k,mid)){
                end=mid;
            }else{
                start=mid;
            }
        }
        return end;
    }

    double findSmallestMaxDist(vector<int> &arr, int k) {
        return findSmallestMaxDistHeap(arr,k);
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 7};
    int k = 1;
    cout << "Smallest maximum distance (Heap): " << sol.findSmallestMaxDistHeap(arr, k) << endl;
    cout << "Smallest maximum distance (Binary Search): " << sol.findSmallestMaxDistBS(arr, k) << endl;

    vector<int> arr2 = {1, 2, 3, 4, 9};
    int k2 = 2;
    cout << "Smallest maximum distance (Heap): " << sol.findSmallestMaxDistHeap(arr2, k2) << endl;
    cout << "Smallest maximum distance (Binary Search): " << sol.findSmallestMaxDistBS(arr2, k2) << endl;

    vector<int> arr3 = {176, 274, 498, 586, 1184, 1596, 1622, 2065, 2371, 2440, 2749, 2863, 3343, 3451, 3582, 4022, 4089, 4491, 4618, 4678, 4787, 5407, 6217, 6425, 6740, 7013, 7682, 8736, 8771, 8984, 9145, 9320, 9449, 9511, 9641, 9661, 9738, 10369, 10374, 10443, 10571, 10913, 11238, 11420, 11448, 11483, 12762, 12875, 12880, 13038, 13128, 13282, 13391, 13573, 13615, 13657, 13897, 13940, 14213, 14272, 14513, 14749, 15451, 15719, 15733, 16027, 16219, 16543, 16577, 16590, 16805, 16825, 17053, 17238, 17273, 17580, 17723, 17725, 18026, 18528, 19370, 19371, 19382, 19754, 19852, 19935, 20066, 20154, 20278, 20748, 20827, 20941, 20982, 21000, 21068, 21306, 21422, 21893, 22269, 22359, 22562, 22596, 22642, 22802, 23196, 23387, 23634, 23797, 23815, 24143, 24655, 24679, 25044, 25846, 26281, 26287, 26346, 26667, 26675, 26817, 26982, 27409, 27601, 29652, 29772, 30070, 30587, 30622, 31462, 31611, 31662, 31686, 31948};
    int k3 = 1638;
    cout << "Smallest maximum distance (Heap): " << sol.findSmallestMaxDistHeap(arr3, k3) << endl;
    cout << "Smallest maximum distance (Binary Search): " << sol.findSmallestMaxDistBS(arr3, k3) << endl;

    return 0;
}


