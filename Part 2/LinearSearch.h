#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <vector>

// Function to perform recursive linear search and return the last occurrence of the target
template <typename T>
int linear_search_last(const std::vector<T>& items, T target, size_t pos_last);

#endif 
