/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 1));
        ans.push_back(root->val);
        int height = 1;
        set<TreeNode*> visited;
        while (!st.empty()) {
            auto p = st.top();
            TreeNode* curr_node = p.first;
            int curr_height = p.second;
            if (visited.count(curr_node) == 0) { // right first
                while (curr_node->right != nullptr) {
                    visited.insert(curr_node);
                    curr_height++;
                    st.push(make_pair(curr_node->right, curr_height));
                    if (curr_height > height) {
                        ans.push_back(curr_node->right->val);
                        height = ans.size();
                    }
                    curr_node = curr_node->right;   
                }
                visited.insert(curr_node);
            } else { // left second
                st.pop();
                if (curr_node->left) {
                    st.push(make_pair(curr_node->left, curr_height + 1));
                    if (curr_height + 1 > height) {
                        ans.push_back(curr_node->left->val);
                        height = ans.size();
                    }
                }
            }
        }
        return ans;
        
    }
};
