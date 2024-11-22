class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash_t;
        for (auto& ch : t) {
            hash_t[ch]++;
        }

        int l = 0;
        int remain = hash_t.size();
        string ans;
        for (int r = 0; r < s.size(); r++) {
            if (hash_t.find(s[r]) != hash_t.end()) {
                hash_t[s[r]]--;
                if (hash_t[s[r]] == 0) remain--;
            } 
            if (remain == 0) {
                while (l < s.size() && 
                    (hash_t.find(s[l]) == hash_t.end() || 
                     hash_t[s[l]] + 1 <= 0)) {
                        if (hash_t.find(s[l]) != hash_t.end()) hash_t[s[l]]++;
                        l++;
                     }
                     if (ans.empty()) ans = s.substr(l, r-l+1);
                     else if (r - l + 1 < ans.size()) ans = s.substr(l, r-l+1);
            }
        }
        return ans;
    }
};
