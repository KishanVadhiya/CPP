#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sieve(int n){
    vector<int> prime(n+1,1);
    vector<int> ans;

    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i]) ans.push_back(i);
    }

    return ans;
}

vector<int> segmentedSieve(int l,int r){
    int rootR= sqrt(r);

    vector<int> primeFactors=sieve(rootR);
    vector<int> segment(r-l+1,1);

    for(auto i:primeFactors){
        int lower=l/i;

        if(lower<=1){ // if l is smaller or equal than i
            lower=i+i; // doing i+i as i is prime number
        }else if(l%i==0){ // if l is the first factor in the range
            lower= lower*i; // restore the old value ;
        }else{
            lower=lower*i+i;
        }

        // int lower= max(i*i,l+(i-l%i)%i); //alternative method

        for(int j=lower;j<=r;j+=i){
            segment[j-l]=0;
        }
    }

    vector<int> ans;

    for(int x=l;x<=r;x++){
        if(segment[x-l]) ans.push_back(x);
    }

    return ans;
}



int main(){
    int l=30;
    int r=50;

    vector<int> ans=segmentedSieve(l,r);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}