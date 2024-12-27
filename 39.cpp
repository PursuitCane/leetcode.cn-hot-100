class Solution {
public:
    void dfs(vector<int>& candidates, int target, int index, int sum, vector<vector<int>>& ans, vector<int>& tmp) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (index >= candidates.size()) return;

        dfs(candidates, target, index + 1, sum, ans, tmp);
        int size = target / candidates[index];
        for (int i = 1; i <= size; i++) {
            tmp.push_back(candidates[index]);
            dfs(candidates, target, index + 1, sum + candidates[index] * i, ans, tmp);
        }
        while (size--) {
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(candidates, target,0,  0, ans, tmp);
        return ans;
        
    }
};
