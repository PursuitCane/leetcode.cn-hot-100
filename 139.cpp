class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        set<char> dict;
        int max_len = 0;
        for (string& word : wordDict) {
            st.insert(word);
            max_len = max(max_len, (int)word.size());
        }

        int n = s.size();
        vector<bool> f(n+1);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            f[i] = false;
            for (int j = 1; j <= min(max_len, i); j++) {
                if (f[i-j] && st.count(s.substr(i-j,j))) {
                    f[i] = true;
                }
            }
        }

        return f[n];
        
        
    }
};
