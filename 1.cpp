class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums_map.find(target-nums[i]) != nums_map.end() && (nums_map[target - nums[i]] != i)) {
                ans.push_back(i);
                ans.push_back(nums_map[target-nums[i]]);
                return ans;
            }
        }
        return ans;
        
    }
};
