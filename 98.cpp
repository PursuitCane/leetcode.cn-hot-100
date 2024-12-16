/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* node, bool is_left_min, int left_min, bool is_right_max, int right_max) {
        if (node == nullptr) return true;
        bool mark = true;
        if (node->left) {
            if (!(node->val > node->left->val)) return false;
            if (is_left_min && !(node->left->val > left_min)) return false;
            if (is_right_max == false) {
                mark = check(node->left, is_left_min, left_min, true, node->val);
            } else {
                mark = check(node->left, is_left_min, left_min, is_right_max, min(node->val, right_max));
            }
            
        }
        if (!mark) return false;

        if (node->right) {

            if (!(node->val < node->right->val)) return false;
            if (is_right_max && !(node->right->val < right_max)) return false;
            if (is_left_min == false) {
                mark = check(node->right, true, node->val, is_right_max, right_max);
            } else {
                mark = check(node->right, is_left_min, max(left_min, node->val), is_right_max, right_max);
            }
        }
        if (!mark) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, 0, root->val, 0, root->val);
    }
};
