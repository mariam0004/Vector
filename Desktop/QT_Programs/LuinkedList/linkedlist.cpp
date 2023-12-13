// linkedlist.cpp
#include "linkedlist.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    Node* next;

    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (!head) {
        head = tail = newNode;
    } else if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* current = head;

        while (current->next && current->next->data < value) {
            current = current->next;
        }

        if (current->next) {
            newNode->next = current->next;
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }

        newNode->prev = current;
        current->next = newNode;
    }
}

void DoublyLinkedList::display() {
    Node* current = head;

    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}
