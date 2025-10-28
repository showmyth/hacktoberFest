#include <iostream>
#include <stack>
using namespace std;

// Insert an element into a sorted stack
void insertSorted(stack<int>& st, int val) {
    // Base case: stack empty or top <= val → safe to push
    if (st.empty() || st.top() <= val) {
        st.push(val);
        return;
    }
    // Otherwise, pop top and recurse
    int temp = st.top();
    st.pop();
    insertSorted(st, val);
    st.push(temp);
}

// Sort the stack recursively
void sortStack(stack<int>& st) {
    if (st.empty()) return;

    int topVal = st.top();
    st.pop();
    sortStack(st);         // sort remaining stack
    insertSorted(st, topVal); // insert current element in sorted order
}

int main() {
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
// Given a stack of integers, sort it in ascending order using only stack
// operations(no other data structures allowed)
