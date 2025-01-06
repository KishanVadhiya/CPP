#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{
    vector<int> Rank,Parent;

    public:
        DisjointSet(int n){
            Rank.resize(n+1,0);
            Parent.resize(n+1);

            for(int i=0;i<n+1;i++){
                Parent[i]=i;
            }
        }

        int findUltimateParent(int node){
            if(node== Parent[node]) return node;
            return Parent[node]=findUltimateParent(Parent[node]);
        }

        void UnionByRank(int node1,int node2){
            int ultimateParentNode1=findUltimateParent(node1);
            int ultimateParentNode2=findUltimateParent(node2);

            if(ultimateParentNode1==ultimateParentNode2) return;

            if(Rank[ultimateParentNode1]>Rank[ultimateParentNode2]){
                Parent[ultimateParentNode2]=ultimateParentNode1;
            }else if(Rank[ultimateParentNode2]>Rank[ultimateParentNode1]){
                Parent[ultimateParentNode1]=ultimateParentNode2;
            }else{
                Parent[ultimateParentNode2]=ultimateParentNode1;
                Rank[ultimateParentNode2]++;
            }

        }
};


int main(){
    DisjointSet ds=DisjointSet(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"3 and 7 belongs to same set "<<endl;
    }else{
        cout<<"3 and 7 are not from the same set"<<endl;
    }
    ds.UnionByRank(3,7);
    cout<<"After Union of 3,7"<<endl;

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"3 and 7 belongs to same set "<<endl;
    }else{
        cout<<"3 and 7 are not from the same set"<<endl;
    }

    return 0;
}