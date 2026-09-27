/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            if (temp->child) {
                Node* c = temp->child;
                c = flatten(c);
                temp->next = c;
                c->prev = temp;
                temp->child = nullptr;
                while (c->next) {
                    c = c->next;
                }
                c->next = nextNode;
                if (nextNode)
                    nextNode->prev = c;
            }
            temp = temp->next;
        }
        return head;
    }
};