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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);
        ListNode* odd = oddHead;
        ListNode* even = evenHead;

        while(head){
            odd->next=head;
            odd=odd->next;
            head=head->next;
            if(head==NULL) break;
            even->next=head;
            even=even->next;
            head=head->next;
        }
        odd->next=evenHead->next;
        even->next=NULL;

        return oddHead->next;
    }
};