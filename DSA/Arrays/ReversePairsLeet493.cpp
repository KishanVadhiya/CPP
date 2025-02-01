// leetcode url - https://leetcode.com/problems/reverse-pairs/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int cnt=0;
    int binarySearch(vector<int> &nums,int start,int end,long target){
        int ans=-1;
        int temp=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]>target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        // cout<<"For temp: "<<temp<<endl;
        // cout<<ans<<endl;
        return (ans==-1)?0:temp-ans+1;
    }
    void merge(vector<int>& nums,int start,int mid,int end){
        vector<int> temp;
        int left=start;
        int right=mid+1;


        //count logic 
        int left2=left;
        int right2=right;


        while(left2<=mid && right2<=end){
            if(nums[left2]>2*long(nums[right2])){
                cnt+=(mid-left2+1);
                right2++;
            }else{
                left2++;
            }
        }


        while(left<=mid && right<=end){
            if(nums[left]<=nums[right] ){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right]);
                // if(nums[left]>2*nums[right]){
                //     cnt+=(mid-left+1);
                // }
                // cnt+=binarySearch(nums,left,mid,2*long(nums[right]));

                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }

        while(right<=end){
            temp.push_back(nums[right++]);
        }

        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
    }
    void mergeSort(vector<int>&nums,int start,int end){
        if(start>=end) return ;
        int mid=start+(end-start)/2;

        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << sol.reversePairs(nums) << endl;
    return 0;
}