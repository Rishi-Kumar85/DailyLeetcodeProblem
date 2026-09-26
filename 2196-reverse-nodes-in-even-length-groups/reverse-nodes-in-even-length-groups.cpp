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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || m == n) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Move prev to the node before the m-th node
    for (int i = 1; i < m; i++) {
        prev = prev->next;
    }

    ListNode* start = prev->next; // The m-th node
    ListNode* then = start->next; // The (m+1)-th node

    // Reverse the sublist from m to n
    for (int i = 0; i < n - m; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy->next;
}
    ListNode* reverseEvenLengthGroups(ListNode* head) {
  ListNode* temp= head;
    int gap=1;

    while(temp && temp->next){
        int remLen=0;
        ListNode* t = temp->next;
        for(int i=1;i<=gap+1&&t;i++){
            remLen++;
            t=t->next;
        }

        if(remLen < gap+1) gap = remLen-1;
        if(gap%2!=0){
            reverseBetween(temp,2,2+gap);
    }
    gap++;
    for(int i=1;temp && i<=gap;i++){
        temp=temp->next;
    }
}


return head;

    }
};