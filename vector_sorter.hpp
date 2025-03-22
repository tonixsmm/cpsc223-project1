#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP

#include <vector>

class VectorSorter {
public:
    static void merge_sort(std::vector<int>& vec);
    static void quick_sort(std::vector<int>& vec);
    static void insertion_sort(std::vector<int>& vec);

private:
    static void merge_sort_helper(std::vector<int>& vec, int left, int right);
    static void merge(std::vector<int>& vec, int left, int mid, int right);
    static void quick_sort_helper(std::vector<int>& vec, int low, int high);
    static int partition(std::vector<int>& vec, int low, int high);
};

#endif
