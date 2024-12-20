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
    int ans = 0;
    map<TreeNode*, int> max_route;
    void build(TreeNode* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            max_route[node] = node->val;
            ans = max(ans, node->val);
            return;
        }
        build(node->left);
        build(node->right);
        max_route[node] = max(node->val, max(max_route[node->left], max_route[node->right]) + node->val);
        ans = max(ans, max_route[node]);
        ans = max(ans, max_route[node->left] + max_route[node->right] + node->val); 
    }
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        max_route[nullptr] = 0;
        build(root);
        return ans;  
    }
};
