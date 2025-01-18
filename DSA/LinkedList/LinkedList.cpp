#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val,Node* next=nullptr){
        this->val=val;
        this->next=next;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void addAtHead(int val) {
        Node* newNode = new Node(val, head);
        head = newNode;
    }

    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void addAtKthPosition(int k, int val) {
        if (k == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < k - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (temp) {
            temp->next = new Node(val, temp->next);
        }
    }

    void addAfterValue(int target, int val) {
        Node* temp = head;
        while (temp && temp->val != target) {
            temp = temp->next;
        }
        if (temp) {
            temp->next = new Node(val, temp->next);
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteAtHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtKthPosition(int k) {
        if (k == 0) {
            deleteAtHead();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < k - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (temp && temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    void deleteValue(int target) {
        if (!head) return;
        if (head->val == target) {
            deleteAtHead();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->val != target) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
    bool search(int target) {
    Node* temp = head;
    while (temp) {
        if (temp->val == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int length() {
    int len = 0;
    Node* temp = head;
    while (temp) {
        ++len;
        temp = temp->next;
    }
    return len;
}
};


int main() {
    LinkedList list;

    list.addAtHead(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtKthPosition(1, 4); // List: 1 -> 4 -> 2 -> 3 -> nullptr
    list.addAfterValue(2, 5); // List: 1 -> 4 -> 2 -> 5 -> 3 -> nullptr

    cout << "Initial list: ";
    list.printList();

    cout << "Length of list: " << list.length() << endl;

    int searchValue = 5;
    cout << "Searching for value " << searchValue << ": " << (list.search(searchValue) ? "Found" : "Not Found") << endl;

    list.deleteAtHead(); // List: 4 -> 2 -> 5 -> 3 -> nullptr
    cout << "After deleting head: ";
    list.printList();

    list.deleteAtTail(); // List: 4 -> 2 -> 5 -> nullptr
    cout << "After deleting tail: ";
    list.printList();

    list.deleteAtKthPosition(1); // List: 4 -> 5 -> nullptr
    cout << "After deleting at position 1: ";
    list.printList();

    list.deleteValue(5); // List: 4 -> nullptr
    cout << "After deleting value 5: ";
    list.printList();

    cout << "Length of list: " << list.length() << endl;

    searchValue = 3;
    cout << "Searching for value " << searchValue << ": " << (list.search(searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}


