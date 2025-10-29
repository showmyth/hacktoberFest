// Given a stack of integers, sort it in ascending order using only stack
// operations(no other data structures allowed)
#include <stack>
#include <climits>

class Solution {
public:
    // Sort stack in ascending order (top = smallest)
    void sortStack(std::stack<int>& mainStack) {
        if (mainStack.empty()) {
            return;
        }
        
        // Remove top element
        int temp = mainStack.top();
        mainStack.pop();
        
        // Recursively sort remaining stack
        sortStack(mainStack);
        
        // Insert the removed element in sorted order
        insertSorted(mainStack, temp);
    }
    
private:
    // Insert element in sorted stack maintaining order
    void insertSorted(std::stack<int>& stack, int element) {
        // Base case: empty stack or element is greater than top
        if (stack.empty() || element > stack.top()) {
            stack.push(element);
            return;
        }
        
        // Remove top and recursively insert element
        int temp = stack.top();
        stack.pop();
        insertSorted(stack, element);
        
        // Put back the removed element
        stack.push(temp);
    }
};

// Alternative approach with auxiliary stack (if one helper stack allowed)
class SolutionWithHelper {
public:
    void sortStack(std::stack<int>& mainStack) {
        std::stack<int> auxStack;
        
        while (!mainStack.empty()) {
            int temp = mainStack.top();
            mainStack.pop();
            
            // Move elements from aux to main if they're greater than temp
            while (!auxStack.empty() && auxStack.top() > temp) {
                mainStack.push(auxStack.top());
                auxStack.pop();
            }
            
            // Push temp in correct position
            auxStack.push(temp);
        }
        
        // Transfer back to main stack (now sorted)
        while (!auxStack.empty()) {
            mainStack.push(auxStack.top());
            auxStack.pop();
        }
    }
};