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
    ListNode* find_next_head(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ans = head->next;
        ListNode* next_head = find_next_head(head->next->next);
        head->next->next = head;
        head->next = next_head;
        return ans;
    }
    ListNode* swapPairs(ListNode* head) {
        return find_next_head(head);
    }
};
