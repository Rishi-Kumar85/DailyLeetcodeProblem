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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* mergedHead = nullptr;

        if (l1->val < l2->val) {
            mergedHead = l1;
            mergedHead->next = mergeTwoLists(l1->next, l2);
        } else {
            mergedHead = l2;
            mergedHead->next = mergeTwoLists(l1, l2->next);
        }

        return mergedHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        ListNode* mergedHead = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            mergedHead = mergeTwoLists(mergedHead, lists[i]);
        }
        return mergedHead;
    }
};