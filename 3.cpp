class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int ans = 1;
        unordered_set<char> ch_set;
        ch_set.insert(s[0]);
        int l = 0;
        for (int i = 1; i < s.size(); i++) {
            while (l < i && ch_set.find(s[i]) != ch_set.end()) {
                ch_set.erase(s[l]);
                l++;
            }
            ans = max(ans, i - l + 1);
            ch_set.insert(s[i]);
        }
        return ans;
    }
};
