#include <iostream>
#include <cassert>
#include <vector>
#include "vector_sorter.hpp"

bool assert_sorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        assert(vec[i - 1] <= vec[i]);
    }
    return true;
}

bool test_insertion_sort() {    
    // test 1: not sorted
    {
        std::vector<int> data {5, 2, 9, 1, 5, 6};
        VectorSorter::insertion_sort(data);
        assert_sorted(data);
    }

    // test 2: already sorted
    {
        std::vector<int> data {1, 2, 3, 4, 5};
        VectorSorter::insertion_sort(data);
        assert_sorted(data);
    }

    // test 3: reverse order
    {
        std::vector<int> data {5, 4, 3, 2, 1};
        VectorSorter::insertion_sort(data);
        assert_sorted(data);
    }

    // test 4: single element
    {
        std::vector<int> data {42};
        VectorSorter::insertion_sort(data);
        assert_sorted(data);
    }
    return true;
}

bool test_merge_sort() {
    // test 1: not sorted
    {
        std::vector<int> data {5, 2, 9, 1, 5, 6};
        VectorSorter::merge_sort(data);
        assert_sorted(data);
    }

    // test 2: already sorted
    {
        std::vector<int> data {1, 2, 3, 4, 5};
        VectorSorter::merge_sort(data);
        assert_sorted(data);
    }

    // test 3: reverse order
    {
        std::vector<int> data {5, 4, 3, 2, 1};
        VectorSorter::merge_sort(data);
        assert_sorted(data);
    }

    // test 4: single element
    {
        std::vector<int> data;
        VectorSorter::merge_sort(data);
        assert_sorted(data);
    }
    return true;
}

bool test_quick_sort() {
    // test 1: not sorted
    {
        std::vector<int> data {5, 2, 9, 1, 5, 6};
        VectorSorter::quick_sort(data);
        assert_sorted(data);
    }

    // test 2: already sorted
    {
        std::vector<int> data {1, 2, 3, 4, 5};
        VectorSorter::quick_sort(data);
        assert_sorted(data);
    }

    // test 3: reverse order
    {
        std::vector<int> data {5, 4, 3, 2, 1};
        VectorSorter::quick_sort(data);
        assert_sorted(data);
    }

    // test 4: single element
    {
        std::vector<int> data {7, 7, 7, 7, 7};
        VectorSorter::quick_sort(data);
        assert_sorted(data);
    }
    return true;
}

int main() {
    std::string insertion_sort = test_insertion_sort() ? "Passed" : "Failed";
    std::cout << "Insertion Sort:\t" << insertion_sort << std::endl;

    std::string merge_sort = test_merge_sort() ? "Passed" : "Failed";
    std::cout << "Merge Sort:\t" << merge_sort << std::endl;

    std::string quick_sort = test_quick_sort() ? "Passed" : "Failed";
    std::cout << "Quick Sort:\t" << quick_sort << std::endl;

    return 0;
}
