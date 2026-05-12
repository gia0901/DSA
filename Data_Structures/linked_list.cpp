#include <iostream>
#include <list>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node()      : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class LinkedList {
    Node* head = nullptr;
    int length = 0;
public:
    LinkedList() = default;
    LinkedList(int val) : head(new Node(val)), length(1) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    int size()    const { return length; }
    
    bool empty()  const { return length == 0; }

    Node& front() {

    }

    Node& back() {

    }

    void clear() {

    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void push_back(int val) {
        if (head == nullptr) {
            head = new Node(val);
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
        length++;
    }

    void pop_back() {
        if (length == 0) return;
        if (length == 1) {
            delete head;
            head = nullptr;
        }
        else { // length >= 2
            Node* temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        length--;
    }

    void push_front(int val) {
        if (head == nullptr) {
            head = new Node(val);
        }
        else {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void pop_front() {
        if (length == 0) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

};

int main() {
    LinkedList l(2);
    l.push_back(5);
    l.push_back(7);
    l.push_back(8);
    l.push_front(0);
    l.pop_back();
    l.printList();
}
