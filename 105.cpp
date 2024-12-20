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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return root;
        }
        vector<int> tmp_pre, tmp_in;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) break;
            tmp_in.push_back(inorder[i]);
            tmp_pre.push_back(preorder[i + 1]);
        }
        root->left = build(tmp_pre, tmp_in);

        int n = tmp_in.size() + 1;
        tmp_in.clear(); tmp_pre.clear();
        
        for (int i = n; i < preorder.size(); i++) {
            tmp_in.push_back(inorder[i]);
            tmp_pre.push_back(preorder[i]);
        }
        root->right = build(tmp_pre, tmp_in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
};
