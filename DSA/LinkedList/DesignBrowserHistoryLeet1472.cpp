// leetcode url - https://leetcode.com/problems/design-browser-history/

#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string val;
    Node *next, *prev;
    Node(string val){
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
Node *home=nullptr;
Node *current=nullptr;
public:
    BrowserHistory(string homepage) {
        home=new Node(homepage);
        current=home;
    }
    
    void visit(string url) {
        current->next=new Node(url);
        current->next->prev=current;
        current=current->next;
    }
    
    string back(int steps) {
        while(steps && current!=home){
            current=current->prev;
            steps--;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while(steps && current->next!=nullptr){
            current=current->next;
            steps--;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    cout << browserHistory->back(1) << endl;    // returns "facebook.com"
    cout << browserHistory->back(1) << endl;    // returns "google.com"
    cout << browserHistory->forward(1) << endl; // returns "facebook.com"
    browserHistory->visit("linkedin.com");
    cout << browserHistory->forward(2) << endl; // returns "linkedin.com"
    cout << browserHistory->back(2) << endl;    // returns "google.com"
    cout << browserHistory->back(7) << endl;    // returns "leetcode.com"
    delete browserHistory;
    return 0;
}