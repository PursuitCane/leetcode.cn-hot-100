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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int sum = l1->val + l2->val;
        head->val = sum % 10;
        sum /= 10;
        l1 = l1->next; l2 = l2->next;
        while (l1 || l2) {
            if (l1 == nullptr) {
                sum += l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                sum += l1->val;
                l1 = l1->next;
            } else {
                sum = sum + l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            ListNode* node = new ListNode(sum % 10, nullptr);
            curr->next = node
            curr = node;
            sum /= 10;

            
        }

        while (sum) {
            ListNode* node = new ListNode(sum % 10, nullptr);
            curr->next = node;
            curr = node;
            sum /= 10;
        }
        return head;
        
    }
};
