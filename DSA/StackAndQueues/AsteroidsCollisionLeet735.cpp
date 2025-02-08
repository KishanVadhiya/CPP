// leetcode url - https://leetcode.com/problems/asteroid-collision/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& arr) {
            vector<int> st;
            int n=arr.size();
    
            for(int i=0;i<n;i++){
                while(st.size()>0 && st.back()>0 && arr[i]<0 && st.back()<-arr[i]){
                    st.pop_back();
                }
                if(st.size()>0 && st.back()>0 && arr[i]<0){
                    if(st.back()==-arr[i])   st.pop_back();
                }else{
                    st.push_back(arr[i]);
                }
            }
    
            return st;
        }
    };


    int main() {
        Solution sol;
        vector<int> asteroids = {5, 10, -5};
        vector<int> result = sol.asteroidCollision(asteroids);

        cout << "Result: ";
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;

        return 0;
    }