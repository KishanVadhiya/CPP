// url - https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133?leftPanelTabValue=PROBLEM
#include<iostream>
#include<string>
#include<climits>
using namespace std;
string minWindow(string S, string T)
{
	// Write your Code here
	int n1=S.length();
	int n2=T.length();
	int j=0;
	int stIdx=-1;
	int lenSubSeq=INT_MAX;
	for(int i=0;i<n1;i++){
		if(S[i]==T[j]) j++;

		if(j==n2){
			int end=i+1;
			j--;
			while(j>=0){
				if(S[i]==T[j]){
					j--;
				}
				i--;
			}
			i++;
			j++;
			if(lenSubSeq>end-i){
				lenSubSeq=end-i;
				stIdx=i;
			}


		}
	}

	return (stIdx==-1)?"":S.substr(stIdx,lenSubSeq);
}


int main() {
    string S = "dynamicprogramming";
    string T = "mm";
    string result = minWindow(S, T);
    cout << "The minimum window subsequence is: " << result << endl;
    return 0;
}