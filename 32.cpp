class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        int dp[30010];
        memset(dp, 0, sizeof dp);
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans = max(ans, dp[i-1]);
            if (s[i] == '(') {
                dp[i] = 0;
                continue;
            }
            // s[i] == ')'
            if (s[i-1] == '(') {
                if (i >=2 ) dp[i] = dp[i-2] + 2;
                else dp[i] = 2;
                continue;
            }
            // s[i - 1] == ')'
            int len = dp[i-1];
            if (len == 0 || len == i) continue;
            if (s[i - len - 1] == '(') {
                if (i - len -2 >=0) {
                    dp[i] = dp[i-1] + 2 + dp[i-len -2];
                } else {
                    dp[i] = dp[i-1] + 2;
                }   
            }
        }
        return max(ans, dp[s.size() -1]);     
    }
};
