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
    void deleteNode(ListNode* node) {
         if (node == nullptr || node->next == nullptr) return; // Edge case: last node can't be deleted this way
        node->val=node->next->val;
        node->next=node->next->next;
    
    }
};