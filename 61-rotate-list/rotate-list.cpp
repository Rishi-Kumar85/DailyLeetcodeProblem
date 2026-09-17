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
    ListNode* rotateRight(ListNode* head, int k) {
       if (!head || !head->next || k == 0) return head;

    ListNode *curr = head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;

    curr->next = head; // Make it a circular list
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    ListNode *newHead = curr->next;
    curr->next = NULL;
    return newHead;  
    }
};