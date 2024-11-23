class Solution {
public:
    vector<int> solution1(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix_product(n+1), prefix_product(n+1);
        suffix_product[n] = prefix_product[0] = 1; 
        for (int i = 0; i < nums.size(); i++) {
            prefix_product[i + 1] = prefix_product[i] * nums[i];
            suffix_product[n - i -1] = suffix_product[n - i] * nums[n - i -1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prefix_product[i] * suffix_product[i+1];
        }
        return ans; 
    }

    vector<int> solution2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre_prod = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = pre_prod;
            pre_prod *= nums[i];
        }
        int suf_prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suf_prod;
            suf_prod *= nums[i];
        }
        return ans;
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        //return solution1(nums);
        return solution2(nums);
        
    }
};
