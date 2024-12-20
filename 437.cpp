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
    int count;
    long long presum;
    unordered_map<long long, int> mp;
    void dfs1(TreeNode* node, int targetSum,unordered_map<long long, int>& curr_mp) {
        if (node == nullptr) return;
        
        unordered_map<long long, int> tmp_mp;
        for (auto it = curr_mp.begin(); it != curr_mp.end(); it++) {
            long long sum = it->first;
            int cnt = it->second;
            tmp_mp[sum + node->val] += cnt;
        }
        tmp_mp[node->val]++;
        if (tmp_mp.find(targetSum) != tmp_mp.end()) {
            count += tmp_mp[targetSum];
        }
        
        dfs1(node->left, targetSum, tmp_mp);
        dfs1(node->right, targetSum, tmp_mp);

    }
    
    void dfs2(TreeNode* node, int targetSum) {
        if (node == nullptr) return;
        presum += node->val;
        if (mp.count(presum - targetSum)) {
            count += mp[presum - targetSum];
        }
        mp[presum]++;
        dfs2(node->left, targetSum);
        dfs2(node->right, targetSum);
        mp[presum]--;
        presum -= node->val;
    }

    int solution1(TreeNode* root, int targetSum) {
        dfs1(root, targetSum, mp);
        return count;
    }

    int solution2(TreeNode* root, int targetSum) {
        mp[0] = 1;
        presum = 0;
        dfs2(root, targetSum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        count = 0;
        //return solution1(root, targetSum);
        return solution2(root, targetSum);
    }
};
