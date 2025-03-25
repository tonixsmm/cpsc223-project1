#include "evaluator.hpp"
#include "vector_sorter.hpp"
#include "doubly_linked_list.hpp"
#include <fstream>
#include <chrono>
#include <iostream>
#include <fstream>  
#include <iomanip>
#include <sstream> 
#include <vector>

void Evaluator::ingest(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (true) {
        if (!std::getline(file, line)) {
            break;
        }
        if (line.empty()) {
            continue;
        }

        // Parse all integers in this line
        std::stringstream ss(line);
        std::vector<int> vec;
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }
        cases.push_back(vec);

        // std::cout << "DEBUG: Loaded line with " << vec.size() << " integers." << std::endl;
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
        // std::cout << "DEBUG:Vector merge sort time: " << time << " seconds\n";

        // Doubly linked list merge sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.merge_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        merge_times.push_back(time);
        // std::cout << "DEBUG:Doubly linked list merge sort time: " << time << " seconds\n";
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
        // std::cout << "DEBUG:Vector quick sort time: " << time << " seconds\n";

        // Doubly linked list quick sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.quick_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        quick_times.push_back(time);
        // std::cout << "DEBUG:Doubly linked list quick sort time: " << time << " seconds\n";
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
        // std::cout << "DEBUG:Vector insertion sort time: " << time << " seconds\n";

        // Doubly linked list insertion sort timing
        DoublyLinkedList dll;
        for (int val : vec) dll.push_back(val);  // Use push_back to insert elements
        start = std::chrono::high_resolution_clock::now();
        dll.insertion_sort();
        end = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration<double>(end - start).count();
        insertion_times.push_back(time);
        // std::cout << "DEBUG:Doubly linked list insertion sort time: " << time << " seconds\n";
    }
}

// Runs each sorting algorithm multiple times and stores the timing data
void Evaluator::run_multiple_times(int runs) {
    for (int i = 0; i < runs; ++i) {
        std::cout << "Running iteration " << i + 1 << "...\n";

        merge_comparison();
        if (merge_times.empty()) std::cout << "DEBUG: merge_times is empty!\n";
        merge_times_runs.push_back(merge_times);
        merge_times.clear();

        quick_comparison();
        if (quick_times.empty()) std::cout << "DEBUG: quick_times is empty!\n";
        quick_times_runs.push_back(quick_times);
        quick_times.clear();

        insertion_comparison();
        if (insertion_times.empty()) std::cout << "DEBUG: insertion_times is empty!\n";
        insertion_times_runs.push_back(insertion_times);
        insertion_times.clear();
    }
}

void Evaluator::printSortResults(const std::string& sortName, const std::vector<std::vector<double>>& runs, std::ofstream& csvFileName) {
    if (runs.empty()) {
        std::cout << sortName << " - No data.\n\n";
        return;
    }

    std::cout << sortName << " (seconds):\n";

    // setting table params
    std::cout << std::left
              << std::setw(10) << "Run"
              << std::setw(10) << "Line"
              << std::setw(15) << "VectorTime"
              << std::setw(15) << "DLLTime"
              << "\n";

    std::cout << std::string(10 + 10 + 15 + 15, '-') << "\n";

    // Iterate over each run
    for (size_t runIdx = 0; runIdx < runs.size(); ++runIdx) {
        const auto& run = runs[runIdx];
        for (size_t i = 0; i + 1 < run.size(); i += 2) {
            double vectorTime = run[i];
            double dllTime = run[i + 1];

            // print line
            std::cout << std::left
                      << std::setw(10) << runIdx
                      << std::setw(10) << (i / 2)  
                      << std::setw(15) << vectorTime
                      << std::setw(15) << dllTime
                      << "\n";

            // write to csv
            if (csvFileName.is_open()) {
                csvFileName << sortName << ","
                        << runIdx << ","
                        << (i / 2) << ","
                        << vectorTime << ","
                        << dllTime << "\n";
            }
        }
    }
    std::cout << "\n";
}

void Evaluator::evaluate() {
    // Check if we have any data
    if (merge_times_runs.empty() && quick_times_runs.empty() && insertion_times_runs.empty()) {
        std::cout << "No sorting data collected\n";
        return;
    }

    std::ofstream csvFile("sorting_evaluation.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Warning: Could not open 'sorting_evaluation.csv' for writing.\n";
    } else {
        csvFile << "SortType,RunIndex,PairIndex,VectorTime,DllTime\n";
    }

    // print to terminal
    printSortResults("Merge Sort", merge_times_runs, csvFile);
    printSortResults("Quick Sort", quick_times_runs, csvFile);
    printSortResults("Insertion Sort", insertion_times_runs, csvFile);

    // Close the CSV file if open
    if (csvFile.is_open()) {
        csvFile.close();
    }
}