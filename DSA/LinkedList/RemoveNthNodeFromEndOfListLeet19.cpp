// leetcode url - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* fast=head, *current=head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        // if(fast)cout<<fast->val;
        if(fast){

        while(fast->next){
            fast=fast->next;
            current=current->next;
        }
        current->next=current->next->next;
        return head;
        }else{
            return head->next;
        }
    }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int n = 2;
    head = sol.removeNthFromEnd(head, n);

    // Print the modified list
    printList(head);

    // Free allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}