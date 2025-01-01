class Solution {
public:
    vector<vector<string>> ans;
    bool check(string& s) {
        int n = s.size();
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    void dfs(string& s, vector<string>& vec, string& tmp, int index) {
        if (index == s.size()) {
            if (tmp.empty()) ans.push_back(vec);
            return;
        }
        tmp += s[index];
        if (check(tmp)) {
            vec.push_back(tmp);
            tmp.clear();
            dfs(s, vec, tmp, index + 1);
            tmp = vec.back();
            vec.pop_back();
        }
        dfs(s, vec, tmp, index + 1);
    }
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        string tmp;
        dfs(s, vec, tmp, 0);
        return ans;
        
    }
};
