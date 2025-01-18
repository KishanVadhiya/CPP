// leetcode url - https://leetcode.com/problems/linked-list-cycle/

#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *fast=head->next,*slow=head;

        while(fast&& fast->next){
            if(fast==slow) return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};

int main() {
    // Creating a linked list with a cycle for testing
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    Solution solution;
    if (solution.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Freeing the allocated memory (note: this won't free the entire list due to the cycle)
    delete head->next->next->next; // -4
    delete head->next->next; // 0
    delete head->next; // 2
    delete head; // 3

    return 0;
}