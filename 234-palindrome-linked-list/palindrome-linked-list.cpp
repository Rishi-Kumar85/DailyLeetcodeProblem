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
    bool isPalindrome(ListNode* head) {
         if(head == NULL || head->next == NULL) return true;

    // Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    ListNode* prev = NULL;
    ListNode* current = slow;
    while(current != NULL){
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Compare the first half with the reversed second half
    ListNode* firstHalf = head;
    ListNode* secondHalf = prev;
    while(secondHalf != NULL){
        if(firstHalf->val != secondHalf->val) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
    }
};