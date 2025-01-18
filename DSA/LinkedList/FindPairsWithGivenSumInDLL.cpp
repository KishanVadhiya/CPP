// gfg url - https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list
#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node *start=head;
        Node *end=head;
        vector<pair<int,int>> ans;
        while(end->next && end->data<(target-start->data)){
            end=end->next;
        }
        
        while(start!=end){
            if(start->data+end->data==target){
                ans.push_back({start->data,end->data});
                start=start->next;
                if(start==end) break;
                end=end->prev;
            }else if(start->data+end->data>target) end=end->prev;
            else start=start->next;
        }
        
        return ans;
    }
};

int main()
{
    // Create a doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    int target = 5;
    Solution sol;
    vector<pair<int, int>> result = sol.findPairsWithGivenSum(head, target);

    // Print the result
    for (auto &pair : result)
    {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    // Free the allocated memory
    Node* temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}