#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DLLNode {
    public:
        int value;
        DLLNode* next;
        DLLNode* prev;
        DLLNode();
        DLLNode(int v);
        DLLNode(DLLNode* n);
        DLLNode(int v, DLLNode* n);
        ~DLLNode();
};

class DoublyLinkedList {
    private: 
        DLLNode* head;
        DLLNode* tail;

        DLLNode* merge(DLLNode* left, DLLNode* right); // Merge sort helper
        DLLNode* merge_sort(DLLNode* head); // Merge sort helper
        DLLNode* partition(DLLNode* head, DLLNode* end); // Quick sort helper

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool push_back(int v);
        bool push_front(int v);
        bool insert(int v, int i);
        int at(int i);
        int search(int v);
        bool is_empty();
        int size();
        bool remove(int i);
        bool remove_value(int v);
        void print();
        DLLNode* get_head() { return head; }
        void print_reverse();
        DLLNode* get_tail();

        void merge_sort();
        void quick_sort(DLLNode* low, DLLNode* high);
        void quick_sort();
        void insertion_sort();
};

#endif