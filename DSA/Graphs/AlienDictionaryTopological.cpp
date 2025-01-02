// gfg url - https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution
{
public:
    string findOrder(vector<string> dict, int k)
    {
        // code here
        vector<vector<int>> adj(k);

        for (int i = 0; i < dict.size() - 1; i++)
        {
            int x = dict[i].length();
            int y = dict[i + 1].length();

            int x1 = 0;

            while (x1 < x and x1 < y)
            {
                if (dict[i][x1] != dict[i + 1][x1])
                {
                    if (dict[i][x1] <= 'Z')
                    {
                        if (dict[i + 1][x1] <= 'Z')
                        {
                            adj[dict[i][x1] - 'A'].push_back(dict[i + 1][x1] - 'A');
                        }
                        else
                        {
                            adj[dict[i][x1] - 'A'].push_back(dict[i + 1][x1] - 'a');
                        }
                    }
                    else
                    {
                        if (dict[i + 1][x1] <= 'z')
                        {
                            adj[dict[i][x1] - 'a'].push_back(dict[i + 1][x1] - 'a');
                        }
                        else
                        {
                            adj[dict[i][x1] - 'a'].push_back(dict[i + 1][x1] - 'A');
                        }
                    }
                    break;
                }

                x1++;
            }
        }

        for (int i = 0; i < k; i++) {
            cout << "Adjacency list of vertex " << char('a' + i) << ": ";
            for (auto it : adj[i]) {
                cout << char('a' + it) << " ";
            }
            cout << endl;
        }

        vector<int> indegree(k);
        for (int i = 0; i < k; i++)
        {
            for(auto it:adj[i]){
                ++indegree[it];
            }
        }

        queue<int> q;

        for(int i=0;i<k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        for (int i = 0; i < k; i++) {
            cout << "Indegree of vertex " << char('a' + i) << ": " << indegree[i] << endl;
        }

        string ans="";

        while(!q.empty()){
            int node = q.front();
            cout << "Processing node: " << char('a' + node) << endl;
            ans+= 'a'+node;
            q.pop();

            for(auto it:adj[node]){
                --indegree[it];
                cout<<"Indegree of node : "<<char('a'+it)<<" is "<<indegree[it]<<endl;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};




int main() {
    Solution obj;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4; // Number of characters in the alien language
    string order = obj.findOrder(dict, k);
    cout << "The order of characters is: " << order << endl;
    return 0;
}