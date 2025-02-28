// gfg url - https://www.geeksforgeeks.org/problems/prime-factors5052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Prime-Factors
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    bool ifPrime(int n){
        if(n<2) return false;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
	public:
	vector<int>AllPrimeFactors1(int n) {
	    // Code here
	    vector<int> ans;
	    int i=1;
	    for(;i*i<n;i++){
	        if(n%i==0){
	            if(ifPrime(i)) ans.push_back(i);
	            if(ifPrime(n/i)) ans.push_back(n/i);
	        }
	    }
	    if(i*i==n && ifPrime(i)) ans.push_back(i);
	    sort(ans.begin(),ans.end());
	    
	    return ans;
	}
	vector<int>AllPrimeFactors2(int n) {
	    // Code here
        vector<int> ans;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n/=i;
                }
            }
        }
        if(n!=1) ans.push_back(n);
        
        return ans;
	}
	vector<int>AllPrimeFactors(int n) {
	    // Code here
        // return AllPrimeFactors1(n);
        return AllPrimeFactors2(n);
	}
};


int main() {
    Solution sol;
    int n = 780;
    vector<int> result = sol.AllPrimeFactors(n);
    for(int factor : result) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}