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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        // Calculate lengths of both linked lists
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != nullptr) {
            lenA++;
            tempA = tempA->next;
        }

        while (tempB != nullptr) {
            lenB++;
            tempB = tempB->next;
        }

        // Move the pointer of the longer list ahead by the difference in
        // lengths
        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            for (int i = 0; i < diff; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                headB = headB->next;
            }
        }

        // Traverse both lists together to find the intersection point
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA; // Intersection point found
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr; // No intersection found
    }
};