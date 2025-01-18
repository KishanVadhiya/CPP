// gfg url - https://www.geeksforgeeks.org/problems/find-length-of-loop/1
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int len(Node*head){
        Node* current=head->next;
        int ans=1;
        while(current!=head){
            ans++;
            current=current->next;
        }
        return ans;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node* fast=head->next;
        Node* slow=head;
        
        while(fast && fast->next && fast!=slow){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast==nullptr || fast->next==nullptr) return 0;
        return len(fast);
    }
};

int main() {
    // Creating a linked list with a loop for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next; // Loop back to node 3

    Solution sol;
    int loopLength = sol.countNodesinLoop(head);
    cout << "Length of the loop is: " << loopLength << endl;

    return 0;
} 