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
}