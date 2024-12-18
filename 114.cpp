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
    TreeNode* find_last(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) return node;
        TreeNode* last_node;
        while (node->right) {
            last_node = node;
            if (node->left) {
                last_node = find_last(node->left);
                last_node->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = last_node->right;
        }

        if (node->left) {
            last_node = find_last(node->left);
            node->right = node->left;
            node->left = nullptr;
            return last_node;
        }
        return node;


    }
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        find_last(root);
        
    }
};
