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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode* head = headA;
        while (head) {
            s.insert(head);
            head = head->next;
        }
        head = headB;
        while (head) {
            if (s.count(head) > 0) return head;
            head = head->next;
        }
        return nullptr;
        
    }
};
