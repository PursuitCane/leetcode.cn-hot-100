class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = -1;
            for (int j = 0; j < coins.size(); j++) {
                int c = coins[j];
                if (i- c >= 0 && dp[i-c] >= 0) {
                    if (dp[i] == -1) dp[i] = dp[i-c] + 1;
                    else dp[i] = min(dp[i], dp[i-c] + 1);

                }
            }
            
        }
        
        return dp[amount];

        
    }
};
