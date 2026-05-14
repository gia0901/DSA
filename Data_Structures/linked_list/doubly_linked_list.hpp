#pragma once

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    explicit Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {

};