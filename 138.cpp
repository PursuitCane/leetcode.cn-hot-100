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
        if (head == nullptr) return head;
        unordered_map<Node*, Node*> mp;
        Node* new_head = new Node(head->val);
        mp[head] = new_head;

        // deep copy node, update next
        Node* curr = head;
        Node* new_curr = new_head;
        while (curr->next) {
            Node* new_node = new Node(curr->next->val);
            new_curr->next = new_node;
            new_curr = new_node;
            curr = curr->next;
            mp[curr] = new_curr;
        }

        // update random
        curr = head;
        while (curr) {
            if (curr->random) {
                mp[curr]->random = mp[curr->random];
            }
            curr = curr->next;
        }
        return new_head;        
    }
};
