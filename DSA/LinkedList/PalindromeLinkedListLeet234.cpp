// leetcode url - https://leetcode.com/problems/palindrome-linked-list/
#include<iostream>
#include<stack>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
stack<int> st;
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            st.push(slow->val);
            slow=slow->next;
            // if(fast->next==nullptr) break;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;

        while(slow){
            if(slow->val !=st.top()) return false;
            st.pop();
            slow=slow->next;
        }

        return true;

    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 2 -> 1
    ListNode* node4 = new ListNode(1);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);

    Solution sol;
    bool result = sol.isPalindrome(head);

    if(result) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free allocated memory
    delete node4;
    delete node3;
    delete node2;
    delete head;

    return 0;
}