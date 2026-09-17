/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
        return nullptr; // An empty list cannot have a cycle
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by 1 step
        fast = fast->next->next;     // Move fast pointer by 2 steps

        if (slow == fast) {
            // Cycle detected, now find the entry point of the cycle
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Return the node where the cycle begins
        }
    }

    return nullptr; // No cycle detected
    }
};