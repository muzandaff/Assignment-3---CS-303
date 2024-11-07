#include "LinearSearch.h"

// Recursive function to find the last occurrence of the target
int linear_search_last(const std::vector<int>& items, int target, size_t pos_last) {
    if (pos_last == -1) {
        return -1;
    }
    if (items[pos_last] == target) {
        return pos_last;
    }
    return linear_search_last(items, target, pos_last - 1);
}
