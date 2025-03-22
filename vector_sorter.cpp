#include "vector_sorter.hpp"
#include <algorithm>

void VectorSorter::merge_sort(std::vector<int>& vec) {
    if (vec.size() > 1) {
        merge_sort_helper(vec, 0, static_cast<int>(vec.size()) - 1);
    }
}

void VectorSorter::merge_sort_helper(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort_helper(vec, left, mid);
        merge_sort_helper(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

void VectorSorter::merge(std::vector<int>& vec, int left, int mid, int right) {
    int sizeLeft  = mid - left + 1;
    int sizeRight = right - mid;

    // create temp sub-vectors
    std::vector<int> leftArr(sizeLeft);
    std::vector<int> rightArr(sizeRight);

    // populate data
    for (int i = 0; i < sizeLeft; ++i) {
        leftArr[i] = vec[left + i];
    }
    for (int j = 0; j < sizeRight; ++j) {
        rightArr[j] = vec[mid + 1 + j];
    }

    // merge the temp arrays back into vec
    int i = 0, j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            vec[k++] = leftArr[i++];
        } else {
            vec[k++] = rightArr[j++];
        }
    }

    // copy any remaining elements
    while (i < sizeLeft) {
        vec[k++] = leftArr[i++];
    }
    while (j < sizeRight) {
        vec[k++] = rightArr[j++];
    }
}

void VectorSorter::quick_sort(std::vector<int>& vec) {
    if (vec.size() > 1) {
        quick_sort_helper(vec, 0, static_cast<int>(vec.size()) - 1);
    }
}

void VectorSorter::quick_sort_helper(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(vec, low, high);
        quick_sort_helper(vec, low, pivotIndex - 1);
        quick_sort_helper(vec, pivotIndex + 1, high);
    }
}

int VectorSorter::partition(std::vector<int>& vec, int low, int high) {
    int pivot = vec[low]; // choose the first element as pivot
    int i = low + 1;

    // rearrange elements
    for (int j = low + 1; j <= high; ++j) {
        if (vec[j] < pivot) {
            std::swap(vec[i], vec[j]);
            ++i;
        }
    }

    // correct position i-1
    std::swap(vec[low], vec[i - 1]);

    return i - 1;
}


void VectorSorter::insertion_sort(std::vector<int>& vec) {
    for (int i = 1; i < static_cast<int>(vec.size()); ++i) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}
