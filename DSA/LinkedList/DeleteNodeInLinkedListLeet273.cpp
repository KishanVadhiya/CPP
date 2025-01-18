// leetcode url - https://leetcode.com/problems/delete-node-in-a-linked-list/
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next){
            node->val=node->next->val;
            node=node->next;
        }
        node->val=node->next->val;
        node->next=NULL;
    }
};


int main() {
    // Creating a linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Node to be deleted: 5
    Solution sol;
    sol.deleteNode(head->next);

    // Printing the modified linked list
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }

    // Freeing allocated memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}