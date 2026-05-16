#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
    explicit Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* _head = nullptr;
    Node* _tail = nullptr;
    size_t _size = 0;
public:
    DoublyLinkedList() = default;
    explicit DoublyLinkedList(int val) : _head(new Node(val)), _tail(_head), _size(1) {}

    ~DoublyLinkedList() {
        clear();
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    DoublyLinkedList(DoublyLinkedList&&) = delete;
    DoublyLinkedList& operator=(DoublyLinkedList&&) = delete;

    size_t size() const { return _size; }

    int front() const {
        if (_head) {
            return _head->val;
        }
        throw std::out_of_range("list is empty");
    }

    int back() const {
        if (_tail) {
            return _tail->val;
        }
        throw std::out_of_range("list is empty");
    }

    void push_back(int val) {
        if (_head == nullptr) {
            _head = _tail = new Node(val);
        }
        else {
            Node* newNode = new Node(val);
            newNode->prev = _tail;
            _tail->next = newNode;
            _tail = newNode;
        }
        _size++;
    }

    void pop_back() {
        if (_head == nullptr) { return; }
        if (_head == _tail) {
            delete _head;
            _head = _tail = nullptr;
        }
        else {
            Node* temp = _tail;
            _tail = _tail->prev;
            _tail->next = nullptr;
            delete temp;
        }
        _size--;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        
        if (_head == nullptr) {
            _head = _tail = newNode;
        }
        else {
            newNode->next = _head;
            _head->prev = newNode;
            _head = newNode;
        }
        _size++;
    }

    void pop_front() {
        if (_head == nullptr) return;
        if (_head == _tail) {
            delete _head;
            _head = _tail = nullptr;
        }
        else {
            Node* temp = _head;
            _head = _head->next;
            _head->prev = nullptr;
            delete temp;
        }
        _size--;
    }

    void insert(int val, size_t pos) {
        if (pos > _size) {
            throw std::out_of_range("insert position is not valid");
        }
        if (pos == 0) return push_front(val);
        if (pos == _size) return push_back(val);
        
        Node* temp = _head;
        Node* newNode = new Node(val);

        for (int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        
        _size++;
    }

    void erase(size_t pos) {
        if (pos >= _size) {
            throw std::out_of_range("insert position is not valid");
        }
        if (pos == 0) return pop_front();
        if (pos == _size-1) return pop_back();

        Node* temp = nullptr;
        if (pos < _size/2) {
            temp = _head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = _tail;
            for (int i = _size-1; i > pos; i--) {
                temp = temp->prev;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        _size--;
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

    bool empty() const {
        return _size == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& other) {
        Node* temp = other._head;
        while (temp) {
            os << temp->val << " -> ";
            temp = temp->next;
        }
        os << "NULL";
        return os;
    }
};


int main() {
    DoublyLinkedList myDLL(3);

    std::cout << myDLL << std::endl;
}