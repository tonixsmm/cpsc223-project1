#include <cassert>     // For assert()
#include "evaluator.hpp" // Header where Evaluator class is declared
#include "doubly_linked_list.hpp" // For using DoublyLinkedList
#include <vector>

// Test ingesting data into the Evaluator system
void test_ingest() {
    Evaluator e;
    std::vector<int> v = {3, 1, 2};

    DoublyLinkedList dll;
    dll.append(3); dll.append(1); dll.append(2);

    e.ingest(v, dll);  // Load data into the evaluator

    // Placeholder: assumes you have a method to verify data was ingested
    assert(e.has_data());  // Should confirm that data was stored
}

// Test Evaluator's merge sort comparison between vector and list
void test_merge_comparison() {
    Evaluator e;
    e.record_merge_sort_time("vector", 5.1);
    e.record_merge_sort_time("list", 7.2);

    // Retrieve performance summary
    auto result = e.merge_comparison();

    // Check if result includes both vector and list data
    assert(result.find("vector") != std::string::npos);
    assert(result.find("list") != std::string::npos);
}

// Test quick sort comparison results
void test_quick_comparison() {
    Evaluator e;
    e.record_quick_sort_time("vector", 3.3);
    e.record_quick_sort_time("list", 6.0);

    auto result = e.quick_comparison();
    assert(result.find("vector") != std::string::npos);
    assert(result.find("list") != std::string::npos);
}

// Test insertion sort comparison results
void test_insertion_comparison() {
    Evaluator e;
    e.record_insertion_sort_time("vector", 4.0);
    e.record_insertion_sort_time("list", 4.5);

    auto result = e.insertion_comparison();
    assert(result.find("vector") != std::string::npos);
    assert(result.find("list") != std::string::npos);
}

// Test full evaluate() summary table
void test_evaluate_full() {
    Evaluator e;

    // Simulate some data
    e.record_merge_sort_time("vector", 2.0);
    e.record_quick_sort_time("vector", 3.0);

    // Generate output summary
    auto result = e.evaluate();

    // Should contain at least the two sorting algorithm names
    assert(result.find("Merge") != std::string::npos);
    assert(result.find("Quick") != std::string::npos);
}

// Entry point - runs all evaluator tests
int main() {
    test_ingest();
    test_merge_comparison();
    test_quick_comparison();
    test_insertion_comparison();
    test_evaluate_full();
    return 0;  // Success
}