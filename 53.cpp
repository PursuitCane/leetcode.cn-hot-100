class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int presum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (presum > 0) presum += nums[i];
            else presum = nums[i];
            ans = max(ans, presum);
        }
        return ans;
        
    }
};
