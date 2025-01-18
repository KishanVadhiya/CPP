#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        if (index == 0) {
            insertAtHead(val);
            return;
        }
        if (index == size) {
            insertAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }

    void insertAfterValue(int target, int val) {
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cerr << "Value not found" << std::endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        size++;
    }

    void deleteAtHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteAtTail() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        if (index == 0) {
            deleteAtHead();
            return;
        }
        if (index == size - 1) {
            deleteAtTail();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    void deleteByValue(int val) {
        Node* current = head;
        while (current != nullptr && current->data != val) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cerr << "Value not found" << std::endl;
            return;
        }
        if (current == head) {
            deleteAtHead();
        } else if (current == tail) {
            deleteAtTail();
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }

    bool search(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtIndex(1, 15);
    dll.insertAfterValue(15, 17);
    dll.display(); // Output: 10 15 17 20

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtIndex(1);
    dll.deleteByValue(15);
    dll.display(); // Output: (empty list)

    std::cout << "Size: " << dll.getSize() << std::endl; // Output: Size: 0

    dll.insertAtHead(30);
    dll.insertAtTail(40);
    std::cout << "Search 30: " << (dll.search(30) ? "Found" : "Not Found") << std::endl; // Output: Search 30: Found

    return 0;
}