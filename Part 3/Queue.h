#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// Queue class definition
template <typename T>
class Queue {
private:
    // Node structure for linked list implementation
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* frontNode;   // Points to the front node in the queue
    Node* rearNode;    // Points to the rear node in the queue
    int queueSize;     // Tracks the number of elements in the queue

public:
    Queue();           // Constructor
    void push(T value); // Add element to the queue
    void pop();         // Remove front element from the queue
    T front() const;    // Get front element
    int size() const;   // Get current size of the queue
    bool empty() const; // Check if queue is empty
    void move_to_rear(); // Move front element to rear
    void displayElements(); // Display all elements
    void insertion_sort(); // Sort elements using insertion sort
};

#endif 
