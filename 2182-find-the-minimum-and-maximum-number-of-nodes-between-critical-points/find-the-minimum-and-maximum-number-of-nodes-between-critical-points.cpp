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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
           vector<int> criticalPoints;
    ListNode* a = head;
    ListNode* b = head->next;
    ListNode* c = head->next->next;
    int index = 0;

    while (c != nullptr) {
        if ((a->val < b->val && b->val > c->val) ||
            (a->val > b->val && b->val < c->val)) {
            criticalPoints.push_back(index + 1); // Store the index of the critical point
        }
        a = a->next;
        b = b->next;
        c = c->next;
        index++;
    }

    if (criticalPoints.size() < 2) {
        return {-1, -1}; // Not enough critical points
    }

    int minDistance = INT_MAX;
    for (int i = 1; i < criticalPoints.size(); i++) {
        minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }

    return {minDistance, criticalPoints.back() - criticalPoints.front()};
    }
};