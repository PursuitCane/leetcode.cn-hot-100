class Solution {
public:
    int solution1(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) s.insert(nums[i]);
        }
        int ans = 1;
        while (s.find(ans) != s.end()) ans++;
        return ans;
    }
    int solution2(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= n && i != (nums[i]-1)) {
                int curr_num = nums[i];
                if (curr_num == nums[curr_num -1]) break;
                nums[i] = nums[curr_num-1];
                nums[curr_num-1] = curr_num;  
            }
        }
        for (int i = 0; i < n ; i++) {
            if (nums[i] != (i+1)) return i+1;
        }
        return n+1;
    }

    int firstMissingPositive(vector<int>& nums) {
        //return solution1(nums);
        return solution2(nums);
        
    }
};
