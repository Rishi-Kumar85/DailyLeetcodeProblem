/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Create a gap of n+1 nodes
        for (int i = 0; i <= n; i++) {
            if(fast==nullptr) return head->next;
            fast = fast->next;
        }

        // Move both pointers
        while (fast!= nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return head;
    }
};