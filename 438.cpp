class Solution {
public:
    bool is_equal(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {    
        vector<int> ans;
        if (s.size() < p.size()) return ans;
        vector<int> p_count(26);
        for (char& ch : p) {
            p_count[ch - 'a']++;
        }
        vector<int> s_count(26);
        for (int i = 0; i < p.size()-1; i++) {
            char ch = s[i];
            s_count[ch - 'a']++;
        }
        for (int i = 0; i < s.size() - p.size() + 1; i++) {
            char ch = s[i + p.size()-1];
            s_count[ch - 'a']++;
            if (is_equal(p_count, s_count)) ans.push_back(i);
            s_count[s[i] - 'a']--;
        }
        return ans;
        
    }
};
