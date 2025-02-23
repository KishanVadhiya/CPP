// leetcode url - https://leetcode.com/problems/longest-string-chain/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    bool ifPossible(string &s1,string &s2){
        int n1=s1.length();
        int n2=s2.length();
        int i=0,j=0;
        while(i<n1 && s1[i]==s2[j]){
            i++;
            j++;
        }
        j++;
        while(i<n1){
            if(s1[i++]!=s2[j++]) return false;
        }

        return true;
    }

    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int memoryOpt2(vector<string>& arr){
        sort(arr.begin(),arr.end(),comp);
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int n=arr.size();
        vector<int> dp(n,1);
        // vector<int> mp(n,-1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((arr[j].size()+1==arr[i].size()) && ifPossible(arr[j],arr[i]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
public:
    int longestStrChain(vector<string>& words) {

        return memoryOpt2(words);
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout << "Longest String Chain Length: " << sol.longestStrChain(words) << endl;
    return 0;
}