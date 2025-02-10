// leetcode url - https://leetcode.com/problems/lru-cache/
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=NULL;
        next=NULL;
    }
};


class LRUCache {
    Node *head,*tail;
    int capacity;
    unordered_map<int,Node*> umap;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        // cout<<"Constructor"<<endl;
        // printLL();
    }
    
    int get(int key) {
        // cout<<"for get()"<<key<<endl;
        // printLL();
        if(umap.find(key)!=umap.end()){
            transferToTail(umap[key]);
            return (umap[key])->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"For put key,value "<<key<<" "<<value<<endl;
        if(umap.find(key)!=umap.end()){
            umap[key]->val=value;
            transferToTail(umap[key]);
        }else{
            Node *newNode=new Node(key,value);
            umap[key]=newNode;
            placeAtTail(newNode);

            if(capacity>0){
                capacity--;
            }else{
                umap.erase(deleteFromHead());
            }

        }

        // printLL();
    }
    //helper functions 
    void transferToTail(Node *nd){
        //delete the node from current place
        Node* ndPrev=nd->prev;
        Node* ndNext=nd->next;
        ndPrev->next=ndNext;
        ndNext->prev=ndPrev;


        //transfer it to tail prev
        placeAtTail(nd);

    }

    void placeAtTail(Node *nd){
        Node* tailPrev=tail->prev;
        tailPrev->next=nd;
        tail->prev=nd;
        nd->next=tail;
        nd->prev=tailPrev;
    }

    int deleteFromHead(){
        int deletedKey=head->next->key;
        Node *delNext=head->next->next;
        delNext->prev=head;
        head->next=delNext;

        return deletedKey;
    }

    // void printLL(){
    //     Node* curr=head;
    //     while(curr!=nullptr){
    //         cout<<"("<<(curr->key)<<","<<(curr->val)<<")"<<" ";
    //         curr=curr->next;
    //     }
    //     cout<<endl;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
    LRUCache* cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3);              // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4);              // evicts key 1
    cout << cache->get(1) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cout << cache->get(4) << endl; // returns 4

    delete cache;
    return 0;
}