#include "evaluator.hpp"
#include <cassert>
#include <iostream>

// Function to test the ingest method
void test_ingest() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");

    // Check if cases were ingested correctly
    assert(!evaluator.cases.empty());
    std::cout << "Ingest test passed.\n";
}

// Function to test the merge_comparison method
void test_merge_comparison() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.merge_comparison();

    // Check if merge_times were recorded
    assert(!evaluator.merge_times.empty());
    std::cout << "Merge comparison test passed.\n";
}

// Function to test the quick_comparison method
void test_quick_comparison() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.quick_comparison();

    // Check if quick_times were recorded
    assert(!evaluator.quick_times.empty());
    std::cout << "Quick comparison test passed.\n";
}

// Function to test the insertion_comparison method
void test_insertion_comparison() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.insertion_comparison();

    // Check if insertion_times were recorded
    assert(!evaluator.insertion_times.empty());
    std::cout << "Insertion comparison test passed.\n";
}

// Function to test the evaluate method
void test_evaluate() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.merge_comparison();
    evaluator.quick_comparison();
    evaluator.insertion_comparison();
    evaluator.evaluate();

    // Check if evaluate prints the timing data
    std::cout << "Evaluate test passed.\n";
}

int main() {
    test_ingest();
    test_merge_comparison();
    test_quick_comparison();
    test_insertion_comparison();
    test_evaluate();
    return 0;
}
