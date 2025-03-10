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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto* curr = head->next;
        auto* pre = head;
        while (curr->next) {
            auto* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        curr->next = pre;
        head->next = nullptr;
        return curr;
        
    }
};
