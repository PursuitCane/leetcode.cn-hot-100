class Solution {
public:
    void dfs(string& digits, int index, vector<vector<char>>& num, vector<string>& ans, string& tmp) {
        if (index == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < num[digits[index] - '0'].size(); i++) {
            tmp.push_back(num[digits[index] - '0'][i]);
            dfs(digits, index + 1, num, ans, tmp);
            tmp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        vector<vector<char>> num(10);
        num[2] = {'a', 'b', 'c'};
        num[3] = {'d', 'e', 'f'};
        num[4] = {'g', 'h', 'i'};
        num[5] = {'j', 'k', 'l'};
        num[6] = {'m', 'n', 'o'};
        num[7] = {'p', 'q', 'r', 's'};
        num[8] = {'t', 'u', 'v'};
        num[9] = {'w', 'x', 'y', 'z'};

        
        string tmp;
        dfs(digits, 0, num, ans, tmp);
        return ans;
    }
};
