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
    bool check(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr && node2 != nullptr) return false;
        if (node1 != nullptr && node2 == nullptr) return false;
        if (node1->val != node2->val) return false;
        return check(node1->left, node2->right) && check(node1->right, node2->left);
    }

    bool solution1(TreeNode* root) {
        return check(root->left, root->right);
    }

    bool solution2(TreeNode* root) {
        queue<TreeNode*> left, right;
        if (root->left) left.push(root->left);
        if (root->right) right.push(root->right);
        if (left.size() != right.size()) return false;
        while (!left.empty()) {
            auto* l = left.front();left.pop();
            auto* r = right.front(); right.pop();
            if (l->val != r->val) return false;

            if (l->left) left.push(l->left);
            if (r->right) right.push(r->right);
            if (left.size() != right.size()) return false;

            if (l->right) left.push(l->right);
            if (r->left) right.push(r->left);
            if (left.size() != right.size()) return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return true;
        //return solution1(root);
        return solution2(root);
        
    }
};
