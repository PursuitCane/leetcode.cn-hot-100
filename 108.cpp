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
    TreeNode* avl(vector<int>& nums, int l, int r) {
        if (r < l) return nullptr;
        if (l > r) return nullptr;
        if (l == r) {
            TreeNode* node = new TreeNode(nums[l]);
            return node;
        }
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = avl(nums, l, mid - 1);
        node->right = avl(nums, mid+1, r);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return avl(nums, 0, nums.size() - 1);
    }
};
