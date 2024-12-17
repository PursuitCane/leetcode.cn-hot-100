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
    list<int> tree_to_list(TreeNode* node) {
        list<int> left;
        if (node == nullptr) return left;
        left = tree_to_list(node->left);
        left.push_back(node->val);
        list<int> right = tree_to_list(node->right);
        left.splice(left.end(), right);
        return left;
    }
    int kthSmallest(TreeNode* root, int k) {
        list<int> l;
        l = tree_to_list(root);
        auto it = l.begin();
        std::advance(it, k-1);
        return *it;
    }
};
