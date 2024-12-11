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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right) {
            return left->val > right->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)>
            hp;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                hp.push(lists[i]);
        }

        if (hp.empty()) return nullptr;

        ListNode* ans = hp.top();
        ListNode* curr = hp.top();
        hp.pop();
        if (curr->next) {
            hp.push(curr->next);
        }
        while (!hp.empty()) {
            ListNode* node = hp.top();
            hp.pop();
            curr->next = node;
            curr = node;
            if (node->next)
                hp.push(node->next);
        }
        return ans;
    }
};
