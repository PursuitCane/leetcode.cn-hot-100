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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        int count = 0;
        auto* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        int index = count / 2 + 1;
        count = 0;
        curr = head;
        while (curr) {
            count++;
            if (count == index) break;
            curr = curr->next;
        }

        ListNode* pre = nullptr;
        while (curr->next) {
            auto* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        curr->next = pre;


        while (curr && head) {
            if (curr->val != head->val) return false;
            curr = curr->next;
            head = head->next;
        }
        return true;
 
    }
};
