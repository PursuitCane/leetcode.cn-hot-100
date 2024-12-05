/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        auto* curr = head;
        auto* iter = head->next->next;
        while (curr != nullptr && iter != nullptr) {
            if (curr == iter) return true;
            curr = curr->next;
            iter = iter->next;
            if (iter == nullptr) return false;
            iter = iter->next;
        }
        return false;
        
    }
};
