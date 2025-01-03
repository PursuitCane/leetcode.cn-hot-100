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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* ans;
        ListNode* curr;
        if (list1->val <= list2->val) {
            ans = list1;
            list1 = list1->next;
        }
        else {
            ans = list2;
            list2 = list2->next;
        }

        curr = ans;
        while (list1 || list2) {
            if (list1 == nullptr) {
                curr->next = list2;
                return ans;
            }

            if (list2 == nullptr) {
                curr->next = list1;
                return ans;
            }
    
            if (list1->val <= list2->val) {
                curr->next = list1;
                curr = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = list2;
                list2 = list2->next;
            }
        }

        return ans;
        
    }
};
