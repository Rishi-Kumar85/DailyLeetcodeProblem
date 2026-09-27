/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        // Step 1: Create new nodes and insert them next to original nodes
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Step 2: Assign random pointers for the new nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next; // Move to the next original node
        }

        // Step 3: Separate the two lists
        Node* newHead = head->next;
        current = head;
        while (current) {
            Node* newNode = current->next;
            current->next = newNode->next; // Restore the original list
            if (newNode->next) {
                newNode->next =
                    newNode->next
                        ->next; // Set the next pointer for the copied list
            }
            current = current->next; // Move to the next original node
        }

        return newHead;
    }
};