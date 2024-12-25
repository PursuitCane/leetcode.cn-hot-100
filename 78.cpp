class Solution {
public:
    vector<bool> visited;
    void dfs(vector<int>& nums, int index,vector<vector<int>>& ans, vector<int>& tmp) {
        if (index == nums.size()) return;
        for (int i = index; i < nums.size(); i++) {
            if (visited[i]) continue;
            tmp.push_back(nums[i]);
            visited[i] = true;
            ans.push_back(tmp);
            dfs(nums, i + 1, ans, tmp);
            visited[i] = false;
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        visited.resize(n);
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        dfs(nums, 0, ans, tmp);
        return ans;
    }
};
