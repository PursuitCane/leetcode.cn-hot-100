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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        auto* quick = head->next->next;
        auto* slow = head->next;
        while (quick != nullptr && slow != nullptr) {
            if (quick == slow) break; 
            slow = slow->next;
            quick = quick->next;
            if (quick == nullptr) return nullptr;
            quick = quick->next;
        }
        if (quick == nullptr || slow == nullptr) return nullptr;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
        
        
    }
};
