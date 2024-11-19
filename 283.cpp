class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) 
                nums[curr_index++] = nums[i];
        }
        for (int i = curr_index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
