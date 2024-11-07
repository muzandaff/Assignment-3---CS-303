#include "Queue.h"

template <typename T>
// Constructor
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}


template <typename T>
// push () function
void Queue<T>::push(T value) {
    // Create a new node with the given value
    Node* newNode = new Node(value);
    // If the queue is empty, set both front and rear to the new node
    if (rearNode) {
        rearNode->next = newNode;
    }
    // If the queue is not empty, set the next pointer of the rear node to the new node
    rearNode = newNode;
    if (!frontNode) {
        frontNode = newNode;
    }
    queueSize++;
}

// Explicit template instantiation for int type
template <typename T>
// pop() function to remove the front element from the queue
void Queue<T>::pop() {
    // If the queue is empty, do nothing    
    if (!empty()) {
        // If there is only one element in the queue, set both front and rear to nullptr  
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        if (!frontNode) {
            rearNode = nullptr;
        }
    // print message
    } else {
        std::cout << "Queue is empty. Cannot pop." << std::endl;
    }
}

template <typename T>
// front() function to return the front element of the queue
T Queue<T>::front() const {
    if (!empty()) {
        return frontNode->data;
    }
    // throw exception
    throw std::out_of_range("Queue is empty");
}


template <typename T>
// size() function to return the size of the queue
int Queue<T>::size() const {
    return queueSize;
}

template <typename T>
// empty() function to check if the queue is empty
bool Queue<T>::empty() const {
    return queueSize == 0;
}

template <typename T>
// displayElements() function to display all elements in the queue
void Queue<T>::move_to_rear() {
    if (!empty()) {
        T frontElement = front();
        // Remove the front element from the queue
        pop();
        push(frontElement);
    }
}

template <typename T>
// displayElements() function to display all elements in the queue
void Queue<T>::displayElements() {
    int currentSize = size();
    for (int i = 0; i < currentSize; ++i) {
        T frontElement = front();
        std::cout << frontElement << " ";
        pop();
        push(frontElement);
    }
    std::cout << std::endl;
}

template class Queue<int>;
