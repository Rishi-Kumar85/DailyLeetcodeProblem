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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head; // No duplicates possible
    }

    ListNode* a = head;
    ListNode* b = head->next;
    while(b!=nullptr){
        while(b!=nullptr && a->val == b->val){
            b=b->next; // Skip duplicates
        }
        a->next = b; // Link to the next unique node
        a=b; // Move a to the next unique node
        if(b!=nullptr){
            b=b->next; // Move b to the next node
        }
    }
    return head;
    }
};