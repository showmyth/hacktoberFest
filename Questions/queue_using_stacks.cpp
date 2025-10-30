// Design and implement a queue using only two stacks. Support the standard
// enqueue and dequeue operations.

#include <stack>
#include <stdexcept>

class QueueUsingStacks {
private:
    std::stack<int> inputStack;   // For enqueue operations
    std::stack<int> outputStack;  // For dequeue operations
    
    // Transfer elements from input to output stack
    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }
    
public:
    QueueUsingStacks() = default;
    
    // Add element to the back of queue - O(1)
    void enqueue(int value) {
        inputStack.push(value);
    }
    
    // Remove and return element from front of queue - Amortized O(1)
    int dequeue() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        
        transferIfNeeded();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }
    
    // Get front element without removing - Amortized O(1)
    int front() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        
        transferIfNeeded();
        return outputStack.top();
    }
    
    // Check if queue is empty - O(1)
    bool empty() const {
        return inputStack.empty() && outputStack.empty();
    }
    
    // Get size of queue - O(1)
    size_t size() const {
        return inputStack.size() + outputStack.size();
    }
};