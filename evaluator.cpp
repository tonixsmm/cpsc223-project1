#include "evaluator.hpp"
#include "vector_sorter.hpp"
#include "doubly_linked_list.hpp"
#include <fstream>
#include <chrono>
#include <iostream>

void Evaluator::ingest(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<int> vec;
    std::string line;
    int group_sizes[] = {1000, 10000, 100000};  // Sizes of the groups
    int group_count = 3;  // Number of groups

    for (int group = 0; group < group_count; ++group) {
        for (int i = 0; i < 4; ++i) {  // Each group has 4 lines
            vec.clear();
            vec.reserve(group_sizes[group]);
            for (int j = 0; j < group_sizes[group]; ++j) {
                int num;
                if (!(file >> num)) {
                    std::cerr << "Error reading number from file. Group: " << group 
                              << ", Line: " << i << ", Number: " << j << std::endl;
                    std::cerr << "Line content: " << line << std::endl;
                    return;
                }
                vec.push_back(num);
            }
            cases.push_back(vec);  // Store each case in the cases vector
            std::cout << "Loaded group " << group << ", line " << i << " with " 
                      << vec.size() << " numbers." << std::endl;
        }
    }

    std::cout << "Total cases loaded: " << cases.size() << std::endl;
}

// Compares the performance of merge sort on both data structures
void Evaluator::merge_comparison() {
    for (const auto& vec : cases) {
        // Vector merge sort timing
        auto vec_copy = vec;
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vec_copy);
        auto end = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double>(end - start).count();
        merge_times.push_back(time);
        std::cout << "Vector merge sort time: " << time << " seconds\n";

        // Doubly linked list merge sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.merge_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        merge_times.push_back(time);
        std::cout << "Doubly linked list merge sort time: " << time << " seconds\n";
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
        double time = std::chrono::duration<double>(end - start).count();
        quick_times.push_back(time);
        std::cout << "Vector quick sort time: " << time << " seconds\n";

        // Doubly linked list quick sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.quick_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        quick_times.push_back(time);
        std::cout << "Doubly linked list quick sort time: " << time << " seconds\n";
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
        double time = std::chrono::duration<double>(end - start).count();
        insertion_times.push_back(time);
        std::cout << "Vector insertion sort time: " << time << " seconds\n";

        // Doubly linked list insertion sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.insertion_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        insertion_times.push_back(time);
        std::cout << "Doubly linked list insertion sort time: " << time << " seconds\n";
    }
}

// Runs each sorting algorithm multiple times and stores the timing data
void Evaluator::run_multiple_times(int runs) {
    for (int i = 0; i < runs; ++i) {
        merge_comparison();
        merge_times_runs.push_back(merge_times);
        merge_times.clear();

        quick_comparison();
        quick_times_runs.push_back(quick_times);
        quick_times.clear();

        insertion_comparison();
        insertion_times_runs.push_back(insertion_times);
        insertion_times.clear();
    }
}

// Prints a table of timing data for each sort
void Evaluator::evaluate() {
    std::cout << "Merge Sort Times (seconds):\n";
    for (const auto& run : merge_times_runs) {
        for (double time : run) {
            std::cout << time << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\nQuick Sort Times (seconds):\n";
    for (const auto& run : quick_times_runs) {
        for (double time : run) {
            std::cout << time << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\nInsertion Sort Times (seconds):\n";
    for (const auto& run : insertion_times_runs) {
        for (double time : run) {
            std::cout << time << " ";
        }
        std::cout << "\n";
    }
}
