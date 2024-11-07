#include <iostream>
#include <vector>
#include "Queue.h"

// Corrected Recursive Linear Search to find last occurrence of target
template <typename T>
int linear_search_last(const std::vector<T>& items, T target, size_t pos_last) {
    if (pos_last == -1) {
        return -1; // Base case: target not found
    }

    int result = linear_search_last(items, target, pos_last - 1);

    if (items[pos_last] == target) {
        return pos_last; // Return the current position if this is the last occurrence
    }

    return result; // Continue with the result found from recursion (either -1 or the position)
}

// Print menu
void displayMenu() {
    std::cout << "\nQueue Operations Menu:" << std::endl;
    std::cout << "1. Push (Add element)" << std::endl;
    std::cout << "2. Pop (Remove front element)" << std::endl;
    std::cout << "3. Display front element" << std::endl;
    std::cout << "4. Check size of the queue" << std::endl;
    std::cout << "5. Check if queue is empty" << std::endl;
    std::cout << "6. Display all elements in the queue" << std::endl;
    std::cout << "7. Move front element to rear" << std::endl;
    std::cout << "8. Recursively find last occurrence of target" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Queue<int> queue;
    int choice, value;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: // Push
                std::cout << "Enter value to push: ";
                std::cin >> value;
                queue.push(value);
                std::cout << value << " has been added to the queue." << std::endl;
                break;
            case 2: // Pop
                if (!queue.empty()) {
                    queue.pop();
                    std::cout << "Front element removed from the queue." << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 3: // Display front element
                if (!queue.empty()) {
                    std::cout << "Front element: " << queue.front() << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 4: // Check size of the queue
                std::cout << "Queue size: " << queue.size() << std::endl;
                break;
            case 5: // Check if queue is empty
                std::cout << (queue.empty() ? "Queue is empty." : "Queue is not empty.") << std::endl;
                break;
            case 6: // Display all elements in the queue
                if (!queue.empty()) {
                    std::cout << "Queue elements: ";
                    queue.displayElements();
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 7: // Move front element to rear
                if (!queue.empty()) {
                    queue.move_to_rear();
                    std::cout << "Front element moved to rear." << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 8: // Find last occurrence of target (Recursive search)
                if (!queue.empty()) {
                    int target;
                    std::cout << "Enter the target value to search for: ";
                    std::cin >> target;

                    // Transfer queue elements into a vector for searching
                    std::vector<int> queue_elements;
                    int current_size = queue.size();
                    for (int i = 0; i < current_size; ++i) {
                        queue_elements.push_back(queue.front());
                        queue.pop();
                    }

                    // Perform the recursive linear search for the last occurrence
                    int last_pos = linear_search_last(queue_elements, target, queue_elements.size() - 1);

                    // Output the result
                    if (last_pos != -1) {
                        std::cout << "The last occurrence of " << target << " is at index: " << last_pos << std::endl;
                    } else {
                        std::cout << target << " not found in the queue." << std::endl;
                    }

                    // Refill the queue with the elements after the search
                    for (int elem : queue_elements) {
                        queue.push(elem);
                    }
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 9: // Exit
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 9);

    return 0;
}
