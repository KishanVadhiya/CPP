#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{
    vector<int> Size,Parent;

    public:
        DisjointSet(int n){
            Size.resize(n+1,0);
            Parent.resize(n+1);

            for(int i=0;i<n+1;i++){
                Parent[i]=i;
                Size[i]=1;
            }
        }

        int findUltimateParent(int node){
            if(node== Parent[node]) return node;
            return Parent[node]=findUltimateParent(Parent[node]);
        }

        void UnionBySize(int node1,int node2){
            int ultimateParentNode1=findUltimateParent(node1);
            int ultimateParentNode2=findUltimateParent(node2);

            if(ultimateParentNode1==ultimateParentNode2) return;

            if(Size[ultimateParentNode1]>Size[ultimateParentNode2]){
                Parent[ultimateParentNode2]=ultimateParentNode1;
                Size[ultimateParentNode1]+=Size[ultimateParentNode2];
            }else if(Size[ultimateParentNode2]>Size[ultimateParentNode1]){
                Parent[ultimateParentNode1]=ultimateParentNode2;
                Size[ultimateParentNode2]+=Size[ultimateParentNode1];
            }else{
                Parent[ultimateParentNode2]=ultimateParentNode1;
                Size[ultimateParentNode1]+=Size[ultimateParentNode2];
            }

            // cout << "Size array: ";
            // for(int i = 1; i < Size.size(); i++) {
            //     cout << Size[i] << " ";
            // }
            // cout << endl;

        }
};


int main(){
    DisjointSet ds=DisjointSet(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"3 and 7 belongs to same set "<<endl;
    }else{
        cout<<"3 and 7 are not from the same set"<<endl;
    }
    ds.UnionBySize(3,7);
    cout<<"After Union of 3,7"<<endl;

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"3 and 7 belongs to same set "<<endl;
    }else{
        cout<<"3 and 7 are not from the same set"<<endl;
    }

    return 0;
}