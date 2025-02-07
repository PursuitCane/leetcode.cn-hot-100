class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (auto item : nums) {
            mp[item]++;
        }
        int index = 0;
        while (index < mp[0]) {
            nums[index] = 0;
            index++;
        }
        while (index < mp[0] + mp[1]) {
            nums[index] = 1;
            index++;
        }
        while (index < nums.size()) {
            nums[index] = 2;
            index++;
        }
        
    }
};
