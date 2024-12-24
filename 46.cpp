class Solution {
public:
    vector<bool> visited;
    void dfs(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& tmp) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == true) continue;
            
            visited[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, i, ans, tmp);
            tmp.pop_back();
            visited[i] = false;

        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        visited.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            std::fill(visited.begin(), visited.end(), false);
            tmp.clear();
            tmp.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, i, ans, tmp);
        }
        return ans;
    }
};
