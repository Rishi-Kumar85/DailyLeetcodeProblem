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
          int position = 1;

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = INT_MAX;
        int maxDistance = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            ListNode* next = curr->next;

            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                if (firstCritical == -1) {

                    // First critical point
                    firstCritical = position;
                    lastCritical = position;

                } else {

                    // Distance from previous critical point
                    minDistance = min(
                        minDistance,
                        position - lastCritical
                    );

                    // Distance from first critical point
                    maxDistance =
                        position - firstCritical;

                    lastCritical = position;
                }
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (firstCritical == -1 || minDistance == INT_MAX) {
            return {-1, -1};
        }

        return {minDistance, maxDistance};
    }
};