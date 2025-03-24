#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

DLLNode::DLLNode() {
    value = 0;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(int v) {
    value = v;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(DLLNode* n) {
    value = 0;
    next = n;
    prev = nullptr;
}

DLLNode::DLLNode(int v, DLLNode* n) {
    value = v;
    next = n;
    prev = nullptr;
}

DLLNode::~DLLNode() {
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    DLLNode * currNode = head;
    DLLNode * nextNode = nullptr;

    while (currNode != nullptr){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

bool DoublyLinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    DLLNode* iter = head;
    while(iter->next != nullptr) {
        iter = iter->next;
    }
    iter->next = new DLLNode(v);
    iter->next->prev = iter;
    tail = iter->next;
    return true;
}

bool DoublyLinkedList::push_front(int v) {
    DLLNode* temp = new DLLNode(v, head);
    if (is_empty()) {
        tail = temp;
    }
    else {
        head->prev = temp;
    }
    head = temp;
    return true;
}

bool DoublyLinkedList::insert(int v, int i) {
    if (i > size() || i < 0) {
        return false;
    } 
    else if (i == 0) {
        return push_front(v);
    }
    else if (i == size()) {
        return push_back(v);
    }
    else {
        DLLNode* iter = head;
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        iter->next = new DLLNode(v, iter->next);
        iter->next->prev = iter;
        iter->next->next->prev = iter->next;
        return true;
    }
}

int DoublyLinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid Index for List");
    }
    else {
        DLLNode* iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
        return iter->value;
    }
}

int DoublyLinkedList::search(int v) {
    DLLNode* iter = head;
    int count = 0;
    while (iter->next != nullptr && iter->value != v) {
        iter = iter->next;
        count++;
    }
    if (iter->value == v) {
        return count; // return index of value
    }
    return -1;
}

bool DoublyLinkedList::is_empty(){
    return head == nullptr;
}

int DoublyLinkedList::size() {
    if (is_empty()) {
        return 0;
    }
    int count = 1;
    for(DLLNode* iter = head; iter->next != nullptr; iter=iter->next) {
        count++;
    }
    return count;
}

bool DoublyLinkedList::remove(int i) {
    if(is_empty()) {
        return false;
    }
    else if (i < 0 || i >= size()) {
        return false;
    }
    else if (i == 0) {
        if (size() == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        else {
            DLLNode* temp = head->next;
            temp->prev = nullptr;
            head->next = nullptr;
            delete head;
            head = temp;
            temp = nullptr;
            return true;
        }
    }
    else {
        DLLNode* iter = head;
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        DLLNode* temp = iter->next;
        if (temp->next == nullptr) {
            delete temp;
            iter->next = nullptr;
            tail = iter;
            return true;
        }
        iter->next = temp->next;
        temp->next->prev = iter;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return true;
    }
}

bool DoublyLinkedList::remove_value(int v) {
    if (head != nullptr) {
        DLLNode * currNode = head;
        if (head->value == v){
            head = head->next;
            if (head != nullptr){
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete currNode;
            return true;
        }
        else { 
            while (currNode != nullptr && currNode->value != v){
                currNode = currNode->next;
            }
            if (currNode != nullptr){
                currNode->prev->next = currNode->next;
                if (currNode->next != nullptr){
                    currNode->next->prev = currNode->prev;
                }
                else {
                    tail = currNode->prev;
                }
                delete currNode;
                return true;
            }
        }
    }
    return false;
}

void DoublyLinkedList::print() {
    DLLNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->next;
    } 
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() {
    DLLNode* iter = tail;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->prev;
    } 
    std::cout << std::endl;
}

DLLNode* DoublyLinkedList::get_tail() {
    return tail;
}

void DoublyLinkedList::merge_sort() {
    head = merge_sort(head);
    DLLNode* iter = head;
    while (iter->next != nullptr) {
        iter = iter->next;
    }
    tail = iter;
}

DLLNode* DoublyLinkedList::merge(DLLNode* left, DLLNode* right) {
    DLLNode* result = nullptr;
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->value <= right->value) {
        result = left;
        result->next = merge(left->next, right);
        result->next->prev = result;
    }
    else {
        result = right;
        result->next = merge(left, right->next);
        result->next->prev = result;
    }
    return result;
}

DLLNode* DoublyLinkedList::merge_sort(DLLNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    DLLNode* middle = head;
    DLLNode* fast = head->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            middle = middle->next;
        }
    }
    DLLNode* left = head;
    DLLNode* right = middle->next;
    middle->next = nullptr;
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

DLLNode* DoublyLinkedList::partition(DLLNode* low, DLLNode* high) {
    int pivot = high->value;
    DLLNode* i = low->prev;
    for (DLLNode* j = low; j != high; j = j->next) {
        if (j->value < pivot) {
            i = (i == nullptr) ? low : i->next; // Move i to next node
            int temp = i->value; // Swap i and j values
            i->value = j->value;
            j->value = temp;
        }
    }
    i = (i == nullptr) ? low : i->next; // Move i to next node
    int temp = i->value;   // Swap pivot to its correct position
    i->value = high->value;
    high->value = temp;
    return i;
}

void DoublyLinkedList::quick_sort(DLLNode* low, DLLNode* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        DLLNode* pivot = partition(low, high);
        quick_sort(low, pivot->prev);
        quick_sort(pivot->next, high);
    }
}

void DoublyLinkedList::quick_sort() {
    quick_sort(head, tail); // Call recursive quick_sort with head and tail
}

void DoublyLinkedList::insertion_sort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    DLLNode* iter = head->next;
    while (iter != nullptr) {
        DLLNode* temp = iter;
        while (temp->prev != nullptr && temp->value < temp->prev->value) {
            int temp_val = temp->value;
            temp->value = temp->prev->value;
            temp->prev->value = temp_val;
            temp = temp->prev;
        }
        iter = iter->next;
    }
}