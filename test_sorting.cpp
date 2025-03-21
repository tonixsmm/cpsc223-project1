#include <iostream>
#include <cassert>
#include <string>
#include "doubly_linked_list.hpp"

bool merge_sort_test(){
    DoublyLinkedList l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2); 
    l.push_back(1);
    std::cout << "Before merge_sort: ";
    l.print();
    l.merge_sort();
    std::cout << "After merge_sort: ";
    l.print();
    DLLNode* head = l.get_head();
    assert(head->value == 1); 
    assert(head->next->value == 2);
    assert(head->next->next->value == 3);   
    assert(head->next->next->next->value == 4);
    assert(head->next->next->next->next->value == 5);
    assert(head->next->next->next->next->next == nullptr);
    return true;    

}

bool quick_sort_test(){     
    // set up
    DoublyLinkedList l;
    l.push_back(10);
    l.push_back(9);
    l.push_back(8);
    l.push_back(7);
    l.push_back(6);
    std::cout << "Before quick_sort: ";
    l.print();
    l.quick_sort();
    std::cout << "After quick_sort: ";
    l.print();
    DLLNode* head = l.get_head();
    assert(head->value == 6);
    assert(head->next->value == 7);
    assert(head->next->next->value == 8); 
    assert(head->next->next->next->value == 9);
    assert(head->next->next->next->next->value == 10); 
    assert(head->next->next->next->next->next == nullptr);
    return true;
}

bool insertion_sort_test(){ 
    // set up
    DoublyLinkedList l;
    l.push_back(8);
    l.push_back(6);
    l.push_back(4);
    l.push_back(2);
    l.push_back(0);
    std::cout << "Before insertion_sort: ";
    l.print();
    l.insertion_sort();
    std::cout << "After insertion_sort: ";
    l.print();  
    DLLNode* head = l.get_head();
    assert(head->value == 0);
    assert(head->next->value == 2);
    assert(head->next->next->value == 4); 
    assert(head->next->next->next->value == 6);
    assert(head->next->next->next->next->value == 8); 
    assert(head->next->next->next->next->next == nullptr);
    return true;
}  

int main() {
    std::cout <<"----------------" << std::endl;
    std::cout << "Starting Doubly Linked List Tests" << std::endl;
    std::cout <<"----------------" << std::endl << std::endl;

    std::string result_1 = merge_sort_test() ? "Passed" : "Failed";
    std::cout << "Merge Sort:\t" << result_1 << std::endl;
    std::cout << std::endl;
    std::string result_2 = quick_sort_test() ? "Passed" : "Failed";
    std::cout << "Quick Sort:\t" << result_2 << std::endl;
    std::cout << std::endl;
    std::string result_3 = insertion_sort_test() ? "Passed" : "Failed";
    std::cout << "Insertion Sort:\t" << result_3 << std::endl;
    std::cout << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Tests Complete" << std::endl;
    return 0;
}