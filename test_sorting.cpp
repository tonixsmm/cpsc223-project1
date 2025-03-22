#include <cassert>      // For assert()
#include <vector>       // For using std::vector
#include "vector_sorter.hpp"  // Header file where sorting functions are declared

// Test merge sort functionality
void test_merge_sort() {
    // Regular input
    std::vector<int> input = {7, 2, 5};
    std::vector<int> expected = {2, 5, 7};
    std::vector<int> output = VectorSorter::merge_sort(input);
    assert(output == expected);  // Check if sorting worked

    // Edge case: Empty vector
    std::vector<int> empty_input;
    std::vector<int> empty_output = VectorSorter::merge_sort(empty_input);
    assert(empty_output.empty());  // Should return an empty vector
}

// Test merge function (merging two sorted vectors)
void test_merge() {
    std::vector<int> a = {1, 4};
    std::vector<int> b = {2, 3};
    std::vector<int> expected = {1, 2, 3, 4};
    std::vector<int> merged = VectorSorter::merge(a, b);
    assert(merged == expected);  // Check merge result

    // Edge cases: One input is empty
    std::vector<int> empty = {};
    assert(VectorSorter::merge(a, empty) == a);
    assert(VectorSorter::merge(empty, b) == b);
}

// Test quick sort functionality
void test_quick_sort() {
    std::vector<int> input = {9, 2, 8};
    std::vector<int> expected = {2, 8, 9};
    std::vector<int> output = VectorSorter::quick_sort(input);
    assert(output == expected);  // Ensure correct sorting

    // Edge case: All elements are the same
    std::vector<int> dup = {5, 5, 5};
    std::vector<int> sorted_dup = VectorSorter::quick_sort(dup);
    assert(sorted_dup == dup);  // Duplicates should stay intact
}

// Test insertion sort functionality
void test_insertion_sort() {
    std::vector<int> input = {4, 3, 5};
    std::vector<int> expected = {3, 4, 5};
    std::vector<int> output = VectorSorter::insertion_sort(input);
    assert(output == expected);

    // Edge case: Vector with one element
    std::vector<int> single = {42};
    assert(VectorSorter::insertion_sort(single) == single);
}

// Entry point - runs all sorting tests
int main() {
    test_merge_sort();
    test_merge();
    test_quick_sort();
    test_insertion_sort();
    return 0;  // Success
=======
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