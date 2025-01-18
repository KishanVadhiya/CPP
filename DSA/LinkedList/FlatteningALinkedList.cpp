// gfg url - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};


class Solution {
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if((list1&&list2&&list1->data>list2->data) || (list1==nullptr && list2!=nullptr)){
            return mergeTwoLists(list2,list1);
        }
        Node* head=list1;
        if(head==nullptr) return nullptr;
        
        while(list1->bottom && list2){
            if(list1->data<=list2->data){
                if(list1->bottom==nullptr || list1->bottom->data>list2->data){
                    Node* temp=list2;
                    list2=list2->bottom;
                    temp->bottom=list1->bottom;
                    list1->bottom=temp;
                }
            }
            list1=list1->bottom;
        }

        if(list2){
            list1->bottom=list2;
        }
        return head;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        Node *ans=root;
        while(root->next){
            ans=mergeTwoLists(ans,root->next);
            Node *temp=root->next;
            // root->next=nullptr;
            root=temp;
        }
        return ans;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        cout << Node->data << " ";
        Node = Node->bottom;
    }
}

int main() {
    // Creating the linked list
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* result = sol.flatten(head);

    cout << "Flattened list: ";
    printList(result);
    cout << endl;

    return 0;
}