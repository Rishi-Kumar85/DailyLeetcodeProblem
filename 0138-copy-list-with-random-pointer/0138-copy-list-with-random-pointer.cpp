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
      if (!head) return nullptr;
    // Step-1: create a copy of original list
    Node* dummy = new Node(0);
    Node* tail = dummy;
    Node* current = head;
    while(current){
        Node* newNode = new Node(current->val);
        tail->next = newNode;
        tail = tail->next;
        current = current->next;

    }
   // Step-2: create a mapping of original list and copied list
    unordered_map<Node*, Node*> mapping;
    Node* original = head;
    Node* copy = dummy->next;
    while(original){
        mapping[original] = copy;
        original = original->next;
        copy = copy->next;
    }
    // Step-3: assign random pointers to the copied list
    original = head; 
    copy = dummy->next;
    while(original){
        if(original->random){
            copy->random = mapping[original->random]; // assigning the random pointer of the copied node to the corresponding copied node from the mapping
        }
        original = original->next;
        copy = copy->next;
    }

    return dummy->next;
    }
};