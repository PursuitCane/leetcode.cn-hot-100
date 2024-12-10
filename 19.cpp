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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        auto* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        int count = len - n + 1;
        if (count == 0) return nullptr;
        if (count == 1) return head->next;
        
        tmp = head;
        len = 0;
        while (tmp) {
            len++;
            if (len + 1 == count) {
                tmp->next = tmp->next->next;
                return head;
            }
            tmp = tmp->next;
        }
        return head;
        
    }
};
