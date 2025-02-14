class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            for (int i = 0; i < n / 2; i++) {
                swap(nums[i], nums[n - i - 1]);
            }
            return;
        }

        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);

                int k1 = index + 1;
                int k2 = n - 1;
                while (k1 < k2) {
                    swap(nums[k1], nums[k2]);
                    k1++;
                    k2--;
                }

                return;
            }
        }
    }
};
