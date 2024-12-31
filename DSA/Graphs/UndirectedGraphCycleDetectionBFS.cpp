
// GFG link -https://leetcode.com/problems/rotting-oranges/description/

#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        queue<pair<int, int>> q;
        vector<bool> visited(adj.size());

        for (int i = 0; i < adj.size(); i++)
        {
            if(!visited[i]){
            q.push(make_pair(-1, i));
            visited[i] = true;
            while (!q.empty())
            {
                int prevNode = q.front().first;
                int currNode = q.front().second;
                q.pop();

                for (auto it : adj[currNode])
                {
                    if (!visited[it])
                    {
                        visited[it] = true;
                        q.push(make_pair(currNode, it));
                    }
                    else if (prevNode != it)
                    {
                        return true;
                    }
                }
            }
        }
        }
        return false;
    }
};


int main()
{
    vector<vector<int>> adj(383);
    vector<pair<int, int>> edges = {
        {383, 205}, {197, 24}, {371, 350}, {3, 138}, {341, 157}, {301, 182}, {208, 72}, {12, 376}, {368, 247}, {86, 181}, {75, 121}, {212, 341}, {137, 204}, {57, 6}, {298, 81}, {278, 95}, {377, 104}, {267, 330}, {184, 9}, {209, 127}, {299, 5}, {180, 87}, {349, 45}, {131, 2}, {136, 306}, {265, 86}, {86, 248}, {167, 193}, {243, 126}, {191, 162}, {156, 143}, {296, 198}, {304, 242}, {240, 153}, {180, 6}, {287, 357}, {147, 366}, {283, 172}, {266, 196}, {306, 182}, {75, 158}, {152, 69}, {136, 66}, {303, 353}, {278, 48}, {7, 264}, {268, 97}, {265, 263}, {262, 233}, {298, 336}, {15, 312}, {240, 0}, {46, 181}, {283, 225}, {342, 250}, {129, 304}, {31, 13}, {259, 173}, {352, 162}, {355, 244}, {225, 2}, {318, 272}, {273, 124}, {81, 290}, {135, 86}, {207, 221}, {190, 256}, {255, 295}, {187, 85}, {89, 181}, {28, 204}, {114, 167}, {338, 352}, {121, 136}, {359, 52}, {320, 217}, {77, 124}, {10, 276}, {139, 259}, {247, 125}, {214, 225}, {372, 382}, {170, 275}, {357, 318}, {170, 333}, {317, 185}, {51, 52}, {195, 10}, {101, 375}, {170, 353}, {194, 234}, {334, 318}, {327, 182}, {257, 78}, {107, 370}, {319, 56}, {19, 369}, {179, 259}, {173, 380}, {99, 278}, {75, 2}, {189, 348}, {227, 138}, {45, 75}, {16, 22}, {177, 377}, {100, 287}, {187, 139}, {336, 7}, {155, 320}, {1, 227}, {83, 302}, {22, 333}, {61, 292}, {37, 376}, {39, 356}, {174, 152}, {51, 326}, {279, 143}, {242, 324}, {300, 360}, {82, 170}, {328, 2}, {154, 299}, {298, 220}, {181, 82}, {11, 127}, {212, 99}, {200, 58}, {83, 345}, {206, 93}, {46, 102}, {373, 57}, {335, 227}, {289, 141}, {272, 71}, {251, 50}, {315, 298}, {157, 269}, {0, 273}, {142, 73}, {326, 125}, {273, 133}, {261, 217}, {31, 163}, {149, 126}, {233, 298}, {382, 308}, {306, 37}, {167, 189}, {62, 229}, {68, 248}, {37, 62}, {161, 99}, {218, 313}, {163, 17}, {186, 34}, {127, 96}, {364, 75}, {374, 136}, {210, 253}, {109, 91}, {164, 204}, {77, 135}, {330, 4}, {167, 156}, {343, 97}, {242, 137}, {242, 380}, {158, 189}, {302, 39}, {296, 237}, {88, 346}, {229, 202}, {256, 104}, {157, 52}, {15, 114}, {7, 29}, {140, 252}, {36, 188}, {305, 281}, {191, 186}, {23, 246}, {237, 151}, {203, 188}, {259, 60}, {74, 193}, {308, 309}, {334, 169}, {348, 37}, {203, 163}, {296, 361}, {38, 104}, {250, 369}, {57, 276}, {271, 190}, {78, 68}, {344, 51}, {257, 140}, {364, 245}, {55, 142}, {118, 81}, {116, 128}, {310, 303}, {244, 378}, {222, 367}};

    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    Solution sol;
    if (sol.isCycle(adj))
    {
        cout << "Graph contains cycle" << endl;
    }
    else
    {
        cout << "Graph doesn't contain cycle" << endl;
    }

    return 0;
}
