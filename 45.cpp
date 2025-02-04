class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        for (int i = 0; i < nums.size() -1; i++) {
            if (nums[i] == 0) continue;
            int m = min(n-1, i + nums[i]);
            for (int j = i + 1; j <= m; j++) {
                if (vec[j] == 0) vec[j] = vec[i] + 1;
                else vec[j] = min(vec[j], vec[i] + 1);
            }
        }
        return vec[n-1];
        
    }
};
