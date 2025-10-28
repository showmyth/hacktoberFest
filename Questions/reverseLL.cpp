#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next; // store next
        curr->next = prev;               // reverse link
        prev = curr;                     // move prev forward
        curr = nextNode;                 // move curr forward
    }
    return prev; // new head
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseList(head); // reverse the list

    printList(head); // Output: 5 4 3 2 1
    return 0;
}
// Given the head of a singly linked list, reverse the list and return the new
// head.
