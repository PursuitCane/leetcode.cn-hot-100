class Solution {
public:
    void dfs(vector<int>& nums, int index,vector<vector<int>>& ans, vector<int>& tmp) {
        if (index == nums.size()) return;
        for (int i = index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
            dfs(nums, i + 1, ans, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        dfs(nums, 0, ans, tmp);
        return ans;
    }
};
