#include "evaluator.hpp"
#include "vector_sorter.hpp"
#include "doubly_linked_list.hpp"
#include <fstream>
#include <chrono>
#include <iostream>

// Ingests evaluation cases from a file
void ingest(const std::string& filename){
    std::ifstream file(filename);
    int n;
    while (file >> n) {
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i) file >> vec[i];
        cases.push_back(vec);  // Store each case in the cases vector
    }
}

// Compares the performance of merge sort on both data structures
void Evaluator::merge_comparison() {
    for (const auto& vec : cases) {
        // Vector merge sort timing
        auto vec_copy = vec;
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vec_copy);
        auto end = std::chrono::high_resolution_clock::now();
        merge_times.push_back(std::chrono::duration<double>(end - start).count());

        // Doubly linked list merge sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.insert(val);
        start = std::chrono::high_resolution_clock::now();
        dll.merge_sort();
        end = std::chrono::high_resolution_clock::now();
        merge_times.push_back(std::chrono::duration<double>(end - start).count());
    }
}

// Compares the performance of quick sort on both data structures
void Evaluator::quick_comparison() {
    for (const auto& vec : cases) {
        // Vector quick sort timing
        auto vec_copy = vec;
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(vec_copy);
        auto end = std::chrono::high_resolution_clock::now();
        quick_times.push_back(std::chrono::duration<double>(end - start).count());

        // Doubly linked list quick sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.insert(val);
        start = std::chrono::high_resolution_clock::now();
        dll.quick_sort();
        end = std::chrono::high_resolution_clock::now();
        quick_times.push_back(std::chrono::duration<double>(end - start).count());
    }
}

// Compares the performance of insertion sort on both data structures
void Evaluator::insertion_comparison() {
    for (const auto& vec : cases) {
        // Vector insertion sort timing
        auto vec_copy = vec;
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vec_copy);
        auto end = std::chrono::high_resolution_clock::now();
        insertion_times.push_back(std::chrono::duration<double>(end - start).count());

        // Doubly linked list insertion sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.insert(val);
        start = std::chrono::high_resolution_clock::now();
        dll.insertion_sort();
        end = std::chrono::high_resolution_clock::now();
        insertion_times.push_back(std::chrono::duration<double>(end - start).count());
    }
}

// Prints a table of timing data for each sort
void Evaluator::evaluate() {
    std::cout << "Merge Sort Times (seconds):\n";
    for (double time : merge_times) std::cout << time << " ";
    std::cout << "\nQuick Sort Times (seconds):\n";
    for (double time : quick_times) std::cout << time << " ";
    std::cout << "\nInsertion Sort Times (seconds):\n";
    for (double time : insertion_times) std::cout << time << " ";
    std::cout << "\n";
}