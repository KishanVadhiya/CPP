#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* current=head;
        Node* newNode=new Node(data);
        Node* next=nullptr;
        for(int i=0;i<pos && current->next;i++){
            // prev=current;
            // cout<<"Error here"<<endl;
            current=current->next;
        }
        next=current->next;
        current->next=newNode;
        newNode->next=next;
        // cout<<"current->data"<<current->data<<endl;
        if(next)
        next->prev=newNode;
        newNode->prev=current;
        
        
        return head;
    }
};


int main() {
    // Create the doubly linked list
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;

    Solution sol;
    int pos = 0;
    int data = 6;

    // Insert the new node
    head = sol.addNode(head, pos, data);

    // Print the updated list
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}