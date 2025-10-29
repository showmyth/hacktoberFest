// Given the head of a singly linked list, reverse the list and return the new
// head.
#include <memory>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

class Solution {
public:
    // Iterative approach - Most efficient
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;  // Save next node
            curr->next = prev;                 // Reverse the link
            prev = curr;                       // Move prev forward
            curr = nextTemp;                   // Move curr forward
        }
        
        return prev;  // New head
    }
    
    // Recursive approach - More elegant
    ListNode* reverseListRecursive(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseListRecursive(head->next);
        
        // Reverse the current link
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};