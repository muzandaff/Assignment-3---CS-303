#include "Queue.h"
#include <iostream>
using namespace std;

//print menu
void displayMenu() {
    cout << "\nQueue Operations Menu:" << endl;
    cout << "1. Push (Add element)" << endl;
    cout << "2. Pop (Remove front element)" << endl;
    cout << "3. Display front element" << endl;
    cout << "4. Check size of the queue" << endl;
    cout << "5. Check if queue is empty" << endl;
    cout << "6. Display all elements in the queue" << endl;
    cout << "7. Move front element to rear" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Create a Queue object
    Queue<int> queue;
    int choice, value;

    // Display menu and process user input
    do {
        displayMenu();
        cin >> choice;
        // Perform the selected operation
        switch (choice) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                queue.push(value);
                cout << value << " has been added to the queue." << endl;
                break;
            case 2: // Pop
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
            case 4: // Check size of the queue
                cout << "Queue size: " << queue.size() << endl;
                break;
            case 5: // Check if queue is empty
                cout << (queue.empty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 6: // Display all elements in the queue
                if (!queue.empty()) {
                cout << "Queue elements: ";
                queue.displayElements(); }
                else { cout << "Queue is empty." << endl; }
                break;
            case 7: // Move front element to rear
                if (!queue.empty()) {
                queue.move_to_rear();
                cout << "Front element moved to rear." << endl;}
                else { cout << "Queue is empty." << endl; }
                break;
            case 8: // Exit
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
