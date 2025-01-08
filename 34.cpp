class Solution {
public:
    int find_lower(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) /2;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] == target) r = mid;
            else if (nums[mid] < target) l = mid + 1;
        }
        if (nums[l] == target) return l;
        return -1;
    }

    int find_upper(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2 + (l + r) % 2;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] == target) l = mid;
            else if (nums[mid] < target) l = mid + 1;
        }
        if (nums[r] == target) return r;
        return -1;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(find_lower(nums, target));
        ans.push_back(find_upper(nums, target));
        return ans;
    }
};
