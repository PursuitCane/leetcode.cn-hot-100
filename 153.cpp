class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        while (l < r) {
            int mid = (l+r)/2;
            if (nums[r] < nums[l]) {
                if (nums[l] <= nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                r = mid -1;

            }
            
        }
        return nums[l];
        
    }
};
