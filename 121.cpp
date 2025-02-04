class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > min_price) {
                ans = max(ans, prices[i] - min_price);
            } else {
                min_price = prices[i];
            }
        }

        return ans;
        
    }
};
