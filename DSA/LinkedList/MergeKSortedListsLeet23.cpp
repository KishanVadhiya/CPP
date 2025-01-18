// leetcode url - https://leetcode.com/problems/merge-k-sorted-lists/
#include<iostream>
#include<vector>
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


ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return nullptr;
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ans=mergeTwoLists(ans,lists[i]);
        }
        return ans;
}
};

int main() {
    // Create some test lists
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {list1, list2, list3};

    Solution solution;
    ListNode* result = solution.mergeKLists(lists);

    // Print the merged list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}