// leetcode url - https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    bool reversePossible=true;
    ListNode* currentHead=nullptr;
    ListNode* nextGroupSt=nullptr;
    ListNode* currentTail=nullptr;
    ListNode* reverseKNodes(ListNode* current,int k){
        
        if(k==1 && current!=nullptr){
            currentHead=current;
            nextGroupSt=current->next;
            return current;
        }
        if(current==nullptr){
            reversePossible=false;
            return current;
        }

        
        ListNode* temp=reverseKNodes(current->next,k-1);
        if(!reversePossible) return current;
        temp->next=current;
        // currentTail=current;
        return current;
    }    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* current=head;
        nextGroupSt=head;
        currentTail=reverseKNodes(nextGroupSt,k);
        // currentTail->next=nextGroupSt;
        if(!reversePossible) return head;
        head=currentHead;
        while(reversePossible){
            ListNode* temp=reverseKNodes(nextGroupSt,k);
            if(!reversePossible){
                currentTail->next=temp;
                break;
            }
            currentTail->next=currentHead;
            currentTail=temp;
            temp->next=nullptr;
        }


        return head;
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

    int k = 2; // Group size

    Solution solution;
    ListNode* newHead = solution.reverseKGroup(head, k);

    // Print the reversed list
    printList(newHead);

    return 0;
}