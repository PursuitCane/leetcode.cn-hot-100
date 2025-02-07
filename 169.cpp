class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
            if (mp[num] > n) return num;
        }
        
        return 0;
    }
};
