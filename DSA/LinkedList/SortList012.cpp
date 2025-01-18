// gfg url - https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
    }
};

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        Node* head0=new Node(-1);
        Node* head1=new Node(-1);
        Node* head2=new Node(-1);
        Node* current0=head0;
        Node* current1=head1;
        Node* current2=head2;
        Node* current=head;
        
        while(current){
            if(current->data==0){
                current0->next=current;
                current0=current0->next;
            }else if(current->data==1){
                current1->next=current;
                current1=current1->next;
            }else{
                current2->next=current;
                current2=current2->next;
            }
            current=current->next;
        }

        head=nullptr;
        if(head2!=current2){
            current2->next=head;
            head=head2->next;
            Node* temp=head;
        }
        
        if(head1!=current1){
            current1->next=head;
            head=head1->next;
            Node* temp=head;
        }
        if(head0!=current0){
            current0->next=head;
            head=head0->next;
        }

        return head;
    }    
};