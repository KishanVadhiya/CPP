// leetcode url - https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* head2=head->next;
        ListNode* oddCurrent=head;
        ListNode* evenCurrent=head2;
        while(oddCurrent && evenCurrent && oddCurrent->next && evenCurrent->next){
            ListNode* oddTemp=evenCurrent->next;
            ListNode* evenTemp=oddTemp->next;
            oddCurrent->next=oddTemp;
            evenCurrent->next=evenTemp;
            if(oddTemp==nullptr) break;
            oddCurrent=oddTemp;
            evenCurrent=evenTemp;
        }
        oddCurrent->next=head2;
        return head;

    }
};


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a Solution object
    Solution sol;
    // Call the oddEvenList function
    ListNode* result = sol.oddEvenList(head);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}