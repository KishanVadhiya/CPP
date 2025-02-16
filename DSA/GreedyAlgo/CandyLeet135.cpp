// leetcode url - https://leetcode.com/problems/candy/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int ans=1;
            int peak=1;
            int down=0;
            int i=1;
            int n=ratings.size();
    
            while(i<n){
                while(i<n && ratings[i]==ratings[i-1]){
                    ans++;
                    i++;
                }
                peak=1;
                while(i<n && ratings[i]>ratings[i-1]){
                    peak++;
                    ans+=peak;
                    i++;
                }
    
                down=1;
                while(i<n && ratings[i]<ratings[i-1]){
                    ans+=down;
                    down++;
                    i++;
                }
    
                if(down>peak){
                    ans+=down-peak;
                }
            }
    
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> ratings = {1, 0, 2};
        cout << "Minimum candies required: " << sol.candy(ratings) << endl;
        return 0;
    }