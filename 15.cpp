class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int k = nums.size() - 1;
            for (int j = i + 1; j < nums.size() - 1 && j < k; j++) {
                if (j > i + 1 && nums[j-1] == nums[j]) continue;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) k--;
                if (k > j && nums[i] + nums[j] + nums[k] < 0) continue;
                if (k > j && nums[i] + nums[j] + nums[k] == 0) ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
