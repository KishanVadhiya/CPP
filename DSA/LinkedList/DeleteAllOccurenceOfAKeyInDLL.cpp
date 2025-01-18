// gfg url - https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list
#include<iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        while((*head_ref)!=nullptr && (*head_ref)->data==x){
            (*head_ref)=(*head_ref)->next;
        }
        
        if((*head_ref)==nullptr) return ;
        else (*head_ref)->prev=nullptr;
        
        Node *current=*head_ref;
        
        while(current){
            if(current->data==x){
                if(current->next) current->next->prev=current->prev;
                current->prev->next=current->next;
            }
            current=current->next;
        }
        
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.deleteAllOccurOfX(&head, 2);

    cout << "Modified list: ";
    printList(head);

    return 0;
}