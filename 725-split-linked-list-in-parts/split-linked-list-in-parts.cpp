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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> parts(k, nullptr);
    int length = 0;
    ListNode* current = head;

    // Calculate the length of the linked list
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    int partSize = length / k;
    int extraNodes = length % k;

    current = head;
    for (int i = 0; i < k; i++) {
        parts[i] = current;
        int currentPartSize = partSize + (i < extraNodes ? 1 : 0);

        for (int j = 0; j < currentPartSize - 1; j++) {
            if (current != nullptr) {
                current = current->next;
            }
        }

        if (current != nullptr) {
            ListNode* nextPartHead = current->next;
            current->next = nullptr; // Break the link
            current = nextPartHead;
        }
    }

    return parts;
    }
};