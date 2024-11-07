#include "LinearSearch.h"

template <typename T>
int linear_search_last(const std::vector<T>& items, T target, size_t pos_last) {
    if (pos_last == -1) {
        return -1; // Base case: target not found
    }

    // Perform the recursive search, checking if the current position holds the target
    int result = linear_search_last(items, target, pos_last - 1);

    if (items[pos_last] == target) {
        return pos_last; // Return the current position if this is the last occurrence
    }

    return result; // Continue with the result found from recursion (either -1 or the position)
}

template int linear_search_last(const std::vector<int>& items, int target, size_t pos_last);
