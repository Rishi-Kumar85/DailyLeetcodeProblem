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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    // Traverse both lists. When one pointer reaches the end, redirect it to the head of the other list.
    while (ptrA != ptrB) {
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }

    // Either both pointers meet at the intersection node or at nullptr if there's no intersection.
    return ptrA;
    }
};