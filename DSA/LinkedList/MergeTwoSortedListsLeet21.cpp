// leetcode url - https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if((list1&&list2&&list1->val>list2->val) || (list1==nullptr && list2!=nullptr)){
            return mergeTwoLists(list2,list1);
        }
        ListNode* head=list1;
        if(head==nullptr) return nullptr;
        
        while(list1->next && list2){
            if(list1->val<=list2->val){
                if(list1->next==nullptr || list1->next->val>list2->val){
                    ListNode* temp=list2;
                    list2=list2->next;
                    temp->next=list1->next;
                    list1->next=temp;
                }
            }
            list1=list1->next;
        }

        if(list2){
            list1->next=list2;
        }
        return head;
    }
};

int main() {
    // Create first sorted linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge the two sorted lists
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}