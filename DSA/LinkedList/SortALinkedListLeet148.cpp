// leetcode url - https://leetcode.com/problems/sort-list/
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

    ListNode* middleNode(ListNode* list){
        ListNode* fast=list->next;
        ListNode* slow=list;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* l1,ListNode* l2){
        if(l1->next==nullptr && l2->next==nullptr){
            return mergeTwoLists(l1,l2);
        }else{
            ListNode* mid=nullptr;
            ListNode* merged1=l1;
            ListNode* merged2=l2;
            if(l1->next){
                mid=middleNode(l1);
                ListNode *temp=mid->next;
                mid->next=nullptr;
                merged1=mergeSort(l1,temp);
            }
            if(l2->next){
                mid=middleNode(l2);
                ListNode* temp=mid->next;
                mid->next=nullptr;
                merged2=mergeSort(l2,temp);
            }

            return mergeTwoLists(merged1,merged2);
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* mid=middleNode(head);
        ListNode* temp=mid->next;
        mid->next=nullptr;
        return mergeSort(head,temp);
    }
};

int main() {
    Solution solution;

    // Creating a linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Sorting the linked list
    ListNode* sortedHead = solution.sortList(head);

    // Printing the sorted linked list
    ListNode* current = sortedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Freeing the allocated memory
    while (sortedHead != nullptr) {
        ListNode* temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0;
}