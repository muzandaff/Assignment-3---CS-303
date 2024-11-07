#include "Queue.h"

// Constructor initializes the queue
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// Add an element to the queue
template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node(value);
    if (rearNode) {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    if (!frontNode) {
        frontNode = newNode;
    }
    queueSize++;
}

// Remove front element from the queue
template <typename T>
void Queue<T>::pop() {
    if (!empty()) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        if (!frontNode) {
            rearNode = nullptr;
        }
    } else {
        cout << "Queue is empty. Cannot pop." << endl;
    }
}

// Get front element of the queue
template <typename T>
T Queue<T>::front() const {
    if (!empty()) {
        return frontNode->data;
    }
    throw out_of_range("Queue is empty");
}

// Get size of the queue
template <typename T>
int Queue<T>::size() const {
    return queueSize;
}

// Check if queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return queueSize == 0;
}

// Move front element to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (!empty()) {
        T frontElement = front();
        pop();
        push(frontElement);
    }
}

// Display all elements in the queue
template <typename T>
void Queue<T>::displayElements() {
    int currentSize = size();
    for (int i = 0; i < currentSize; ++i) {
        T frontElement = front();
        cout << frontElement << " ";
        pop();
        push(frontElement);
    }
    cout << endl;
}

// Sort the queue using insertion sort
template <typename T>
void Queue<T>::insertion_sort() {
    vector<T> tempVec;
    while (!empty()) {
        tempVec.push_back(front());
        pop();
    }

    for (size_t j = 1; j < tempVec.size(); j++) {
        T key = tempVec[j];
        bool insertionNeeded = false;
        size_t i;
        for (i = j - 1; i < tempVec.size() && tempVec[i] > key; i--) {
            tempVec[i + 1] = tempVec[i]; 
            insertionNeeded = true;
        }
        if (insertionNeeded)
            tempVec[i + 1] = key;
    }

    // Rebuild the queue with sorted elements
    for (T value : tempVec) {
        push(value);
    }
}

template class Queue<int>;
