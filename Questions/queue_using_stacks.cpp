// Design and implement a queue using only two stacks. Support the standard
// enqueue and dequeue operations.



/*
 * Program: Implement a Queue using two Stacks
 * Language: C++
 * Author: Umang Chandra
 * 
 * Description:
 * This program demonstrates how to design a queue data structure 
 * using only two stacks. The queue supports standard operations:
 * - enqueue(x): Insert element x at the back of the queue.
 * - dequeue(): Remove the element from the front of the queue.
 *
 * Time Complexity:
 * - Enqueue: O(1)
 * - Dequeue: Amortized O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

    // Move all elements from s1 to s2
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    // Push element x to the back of queue
    void enqueue(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue and returns it
    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty!\n";
                return -1;
            }
            transfer();
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Get the front element
    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty!\n";
                return -1;
            }
            transfer();
        }
        return s2.top();
    }

    // Check if queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // 10
    cout << "Dequeued: " << q.dequeue() << endl;     // 10

    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl;     // 20
    cout << "Front element: " << q.front() << endl;  // 30

    return 0;
}
