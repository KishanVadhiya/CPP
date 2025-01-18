// gfg url - https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


class Solution
{
public:
    Node * removeDuplicates(struct Node *head)
    {
        Node *current=head->next;
        
        while(current){
            if(current->data==current->prev->data){
                current->prev->next=current->next;
                if(current->next) current->next->prev=current->prev;
            }
            current=current->next;
        }
        return head;
    }
};


void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;

    Solution sol;
    head = sol.removeDuplicates(head);

    printList(head);

    return 0;
}