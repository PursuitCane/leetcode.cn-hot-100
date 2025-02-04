class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int max_index = 0;
        int n = nums.size()-1;
        for (int i = 0; i <= max_index; i++) {
            if (i + nums[i] >= n) return true;
            max_index = max(max_index, i + nums[i]);
            
        }
        return false;
        
    }
};
