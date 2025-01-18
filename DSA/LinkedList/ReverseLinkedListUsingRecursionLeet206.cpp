// leetcode url - https://leetcode.com/problems/reverse-linked-list/
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
ListNode* ans=nullptr;
public:
    ListNode* recur(ListNode* current){
        if(current->next==nullptr){
            ans=current;
            return current;
        }

        ListNode* temp= recur(current->next);
        temp->next=current;
        return current;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        recur(head)->next=nullptr;
        return ans;
    }
};

int main() {
    // Create a linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reverse the linked list
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    // Print the reversed linked list
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    // Free the allocated memory
    current = reversedHead;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}