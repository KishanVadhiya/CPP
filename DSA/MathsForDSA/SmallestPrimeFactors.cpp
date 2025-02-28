
#include<iostream>
#include<vector>
using namespace std;
vector<int> findPrimeFactors(int N) {

    // Write your code here
    vector<long> spf;
int n;
    n=N;
    for(int i=0;i<=n;i++){
        spf.push_back(i);
    }
    
    for(long i=2;i<=n;i++){
        if(i==spf[i]){
            for(long j=i*i;j<=n;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
    vector<int> ans;
    while(N>1){
        ans.push_back(spf[N]);
        N/=spf[N];
    }
    
    return ans;
}
int main() {
    int N = 12246;
    vector<int> primeFactors = findPrimeFactors(N);
    cout << "Prime factors of " << N << " are: ";
    for(int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}
