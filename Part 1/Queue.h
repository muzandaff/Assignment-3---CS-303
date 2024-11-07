#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    // Node structure to represent each element in the queue
    struct Node {
        T data;
        Node* next; // pointer to the next node in the queue
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* frontNode; // pointer to the front node of the queue
    Node* rearNode;  // pointer to the rear node of the queue
    int queueSize;   // keeps size of the queue

public:
    Queue(); // constructor to initialize the queue
    void push(T value);  // adds a new element to the rear of the queue
    void pop();  // removes the front element from the queue
    T front() const; // returns the front element of the queue
    int size() const;  // returns the size of the queue
    bool empty() const; // checks if the queue is empty
    void move_to_rear(); // moves the front element to the rear of the queue
    void displayElements(); // displays the elements of the queue
};

#endif 
