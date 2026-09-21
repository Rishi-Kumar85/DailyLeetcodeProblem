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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (head == NULL || left == right) return head;

    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;

    ListNode* current = head;
    int position = 1;
    
    while(current){
        if(position == left - 1) {
            a = current; // Node before the left position
        }
        if(position == left) {
            b = current; // Node at the left position
        }
        if(position == right) {
            c = current; // Node at the right position
            d = current->next; // Node after the right position
            break;
        }
        current = current->next;
        position++;
    }

    // Reverse the sublist from b to c
    ListNode* prev = d;
    current = b;
    while(current != d) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if(a) {
        a->next = c; // Connect the node before left to the new head of reversed sublist
    } else {
        head = c; // If left is 1, update head to new head of reversed sublist
    }
    return head;
    }
};