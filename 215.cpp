class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mark[20010];
        memset(mark, 0, sizeof mark);
        int offset = 10000;
        for (auto num : nums) {
            num += offset;
            mark[num]++;
            //printf("num %d true\n", num);
        }

        k = nums.size() - k + 1;
        int count = 0;
        int ans = 0;
        for (int i = 0; i< 20010; i++) {
            count += mark[i];
            if (count >= k) {
                ans = i;
                break;
            }
        }
        return ans - offset;
    }
};
