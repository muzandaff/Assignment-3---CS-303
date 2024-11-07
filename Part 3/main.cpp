#include <iostream>
#include "Queue.h"          
#include "LinearSearch.h"     

using namespace std;

// Display menu for queue operations
void displayMenu() {
    cout << "\nQueue Operations Menu:" << endl;
    cout << "1. Push (Add element)" << endl;
    cout << "2. Pop (Remove front element)" << endl;
    cout << "3. Display front element" << endl;
    cout << "4. Check size of the queue" << endl;
    cout << "5. Check if queue is empty" << endl;
    cout << "6. Display all elements in the queue" << endl;
    cout << "7. Move front element to rear" << endl;
    cout << "8. Recursively find last occurrence of target" << endl;
    cout << "9. Sort the queue using Insertion Sort" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Queue<int> queue;    // Create a queue of integers
    int choice, value;

    do {
        displayMenu();    // Display menu
        cin >> choice;    // User choice input

        switch (choice) {
            case 1: // Push element to queue
                cout << "Enter value to push: ";
                cin >> value;
                queue.push(value);
                cout << value << " has been added to the queue." << endl;
                break;
            case 2: // Pop element from queue
                if (!queue.empty()) {
                    queue.pop();
                    cout << "Front element removed from the queue." << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3: // Display front element
                if (!queue.empty()) {
                    cout << "Front element: " << queue.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 4: // Display queue size
                cout << "Queue size: " << queue.size() << endl;
                break;
            case 5: // Check if queue is empty
                cout << (queue.empty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 6: // Display all elements in the queue
                if (!queue.empty()) {
                    cout << "Queue elements: ";
                    queue.displayElements();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 7: // Move front element to rear
                if (!queue.empty()) {
                    queue.move_to_rear();
                    cout << "Front element moved to rear." << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 8: // Find last occurrence of target element
                if (!queue.empty()) {
                    int target;
                    cout << "Enter the target value to search for: ";
                    cin >> target;

                    vector<int> queue_elements;
                    int current_size = queue.size();
                    for (int i = 0; i < current_size; ++i) {
                        queue_elements.push_back(queue.front());
                        queue.pop();
                    }

                    int last_pos = linear_search_last(queue_elements, target, queue_elements.size() - 1);
                    cout << "Last occurrence of " << target << " is at position: " << last_pos << endl;

                    // Restore original queue
                    for (int element : queue_elements) {
                        queue.push(element);
                    }
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 9: // Sort the queue using insertion sort
                if (!queue.empty()) {
                    queue.insertion_sort();
                    cout << "Queue has been sorted using insertion sort." << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 10: // Exit program
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 10);  // Keep showing menu until exit option

    return 0;
}
