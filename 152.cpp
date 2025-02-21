class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxdp(n), mindp(n);
        maxdp[0] = nums[0];
        mindp[0] = nums[0];
        int ans = max(maxdp[0], maxdp[0]);
        for (int i = 1; i < nums.size(); i++) {
            maxdp[i] = max(nums[i], maxdp[i-1] * nums[i]);
            maxdp[i] = max(maxdp[i], mindp[i-1]* nums[i]);

            mindp[i] = min(nums[i], mindp[i-1] * nums[i]);
            mindp[i] = min(mindp[i], maxdp[i-1] * nums[i]);
            ans = max(ans, mindp[i]);
            ans = max(maxdp[i], ans);
        }
        
        return ans;
        
    }
};
