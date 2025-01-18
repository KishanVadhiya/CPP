// leetcode url - https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        int size=0;
        for(int i=0;i<k && fast;i++,size++){
            fast=fast->next;
        }

        if(fast==nullptr && size<=k){
            // cout<<size<<endl;
            k%=size;
            fast=head;
            for(int i=0;i<k;i++){
            fast=fast->next;
            }
        }


        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};

int main() {
    // Create a linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Number of rotations

    Solution sol;
    ListNode* result = sol.rotateRight(head, k);

    // Print the rotated list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}