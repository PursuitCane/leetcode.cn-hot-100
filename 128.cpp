class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> m;
        for (int num : nums) {
            m[num] = 1;
        }
        int ans = 1;
        for (const auto& pair : m) {
            int key = pair.first;
            if (m.find(key-1) != m.end()) {
                int tmp = m[key] = m[key-1] + 1;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
