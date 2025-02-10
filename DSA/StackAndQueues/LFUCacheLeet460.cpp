// leetcode url - https://leetcode.com/problems/lfu-cache/description/
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int key;
    int val;
    int freq;
    Node *prev;
    Node *next;

    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->freq=1;
        prev=NULL;
        next=NULL;
    }
};

class LFUCache {
    unordered_map<int,Node*> umap;
    unordered_map<int,Node*> freqStart;
    unordered_map<int,Node*> freqEnd;
    int capacity;
    Node *head,*tail;
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;

        updateFreq(umap[key]);

        return umap[key]->val;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            umap[key]->val=value;
            updateFreq(umap[key]);
        }else{
            Node* nd=new Node(key,value);
            if(capacity>0) capacity--;
            else{
                umap.erase(deleteNode(head->next));
            }
            addNode(nd,head);
            umap[key]=nd;
        }

    }

    void updateFreq(Node* nd){
            Node* currFreqTail=head;
        if(freqStart.find(nd->freq + 1)==freqStart.end()){
            currFreqTail=freqEnd[nd->freq];
            if(currFreqTail==nd){
                    currFreqTail=currFreqTail->prev;
            }
        }
            deleteNode(nd);
            nd->freq=nd->freq+1;
            addNode(nd,currFreqTail);
    }

    int deleteNode(Node* nd){
        int freq=nd->freq;
        Node* ndPrev=nd->prev;
        Node* ndNext=nd->next;
        ndPrev->next=ndNext;
        ndNext->prev=ndPrev;

        if(freqStart[freq]==nd){
            if(freqEnd[freq]==nd){
                freqStart.erase(freq);
                freqEnd.erase(freq);
            }else{
                freqStart[freq]=freqStart[freq]->next;
            }
        }else if (freqEnd[freq]==nd){
            freqEnd[freq]=freqEnd[freq]->prev;
        }

        return nd->key;
    }

    void addNode(Node *nd,Node* prevFreqEnd){
        int freq=nd->freq;
        Node* tempNext=prevFreqEnd->next;
        Node* tempPrev=prevFreqEnd;
        if(freqStart.find(freq)!=freqStart.end()){
            tempPrev=freqEnd[freq];
            tempNext=freqEnd[freq]->next;
        }else{
            freqStart[freq]=nd;
        }
            tempPrev->next=nd;
            nd->prev=tempPrev;
            nd->next=tempNext;
            tempNext->prev=nd;
            freqEnd[freq]=nd;
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main() {
    LFUCache* cache = new LFUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3);              // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cache->put(4, 4);              // evicts key 1
    cout << cache->get(1) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cout << cache->get(4) << endl; // returns 4

    delete cache;
    return 0;
}