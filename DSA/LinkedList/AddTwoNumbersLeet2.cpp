// leetcode url - https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=l1->val+l2->val;
        int carry=sum/10;
        ListNode* ans=new ListNode(sum%10);
        ListNode* head=ans;
        l1=l1->next;
        l2=l2->next;
        while(l1 && l2){
            sum=carry+l1->val+l2->val;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum=carry+l1->val;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            l1=l1->next;
        }
        while(l2){
            sum=carry+l2->val;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            l2=l2->next;
        }

        while(carry>0){
            sum=carry;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
        }
        return head;
    }
};


int main() {
    // Create first linked list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr) {
        cout << result->val;
        if (result->next != nullptr) {
            cout << " -> ";
        }
        result = result->next;
    }
    cout << endl;

    // Free the allocated memory
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}