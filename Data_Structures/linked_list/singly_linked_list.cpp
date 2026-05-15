#include <iostream>

struct Node {
    int val;
    Node* next;
    Node()      : val(0), next(nullptr) {}
    explicit Node(int x) : val(x), next(nullptr) {}
    // với 2 argument, explicit gần như vô nghĩa
    // explicit thường chỉ dùng với single-argument constructor
    Node(int x, Node* next) : val(x), next(next) {}
};

class LinkedList {
    Node* _head = nullptr;
    Node* _tail = nullptr;
    size_t _size = 0;
public:
    LinkedList() = default;

    LinkedList(int val) : _head(new Node(val)), _tail(_head), _size(1) {}

    ~LinkedList() {
        clear();
    }

    // Copy
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Move
    LinkedList(LinkedList&&) = delete;
    LinkedList& operator=(LinkedList&&) = delete;

    ssize_t size() const { return _size; }
    
    bool empty() const { return _size == 0; }

    int front() const {    // O(1)
        if (_head) {
            return _head->val;
        }
        throw std::out_of_range("front node is null");
    }

    int back() const {    // O(1)
        if (_tail) {
            return _tail->val;
        }
        throw std::out_of_range("back node is null");
    }

    void clear() {
        while (_head) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _head = _tail = nullptr;
        _size = 0;
    }

    void printList() const {
        Node* temp = _head;
        while (temp) {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "null" << std::endl;
    }

    void push_back(int val) {   // O(1) - không có _tail thì là O(N)
        if (_head == nullptr) {
            _head = _tail = new Node(val);
        }
        else {
            _tail->next = new Node(val);
            _tail = _tail->next;
        }
        _size++;
    }

    void pop_back() {   // O(N)
        if (_size == 0) return;
        if (_size == 1) {
            delete _head;
            _head = _tail = nullptr;
        }
        else { // _size >= 2
            Node* temp = _head;
            while (temp->next != _tail) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            _tail = temp;
        }
        _size--;
    }

    void push_front(int val) { // O(1)
        if (_head == nullptr) {
            _head = _tail = new Node(val);
        }
        else {
            Node* newNode = new Node(val);
            newNode->next = _head;
            _head = newNode;
        }
        _size++;
    }

    void pop_front() { // O(1)
        if (_size == 0) return;
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        _size--;

        if (_head == nullptr) {
            _tail = nullptr;
        }
    }

    void insert(int val, int pos) {
        if (pos < 0 || pos > _size) {
            throw std::out_of_range("position is out of range");
        }
        if (pos == 0) {
            return push_front(val);
        }
        else if (pos == _size) {
            return push_back(val);
        }
        // insert ở giữa
        Node* prev = _head;
        for (int i = 0; i < pos-1; i++) { // VD: insert(3) thì phải dừng ở node 2
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;

        _size++;
    }

    void erase(int val) {
        if (_head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* prev = _head;
        Node* curr = prev;
        while (curr) {
            if (curr->val == val) {
                if (curr == _head) {
                    return pop_front();
                }
                else if (curr == _tail) {
                    _tail = prev;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        std::cout << "There is no node with value: " << val << std::endl;
    }
};


int main() {

}