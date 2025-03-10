class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[510][510];
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;


        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j-1] + 1;

                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
                dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);


            }
        }

        return dp[word1.size()][word2.size()];
        
    }
};
