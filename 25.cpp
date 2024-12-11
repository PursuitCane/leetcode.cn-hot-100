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
    ListNode* find_head_k(ListNode* head, int k) {
        // check if len >= k
        int count = 0;
        ListNode* curr = head;
        ListNode* next_head = nullptr;
        while (curr) {
            count++;
            if (count == k) {
                next_head = curr->next;
                break;
            }
            curr = curr->next;
        }
        if (count < k) return head;

        // reverse
        curr = head->next; count = 1;
        ListNode* pre = head;
        while (curr) {
            count++;     
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            if (count == k) break;
            curr = next;
        }

        head->next = find_head_k(next_head, k);

        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        return find_head_k(head, k);
    }
};
