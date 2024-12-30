class Solution {
public:
    unordered_set<string> s;
    void dfs(vector<string>& ans, string& curr, int n, int l, int r) {
        if (r == n) {
            if (s.count(curr)) return;
            ans.push_back(curr);
            s.insert(curr);
            return;
        }
        if (l == n) {
            for (int i = 0; i < n - r; i++) {
                curr += ")";
            }
            dfs(ans, curr, n, n, n);
            for (int i = 0; i < n - r; i++) {
                curr.pop_back();
            }
            return;
        }
        for (int i = 0; i < n - l; i++) {
            for (int k = 0; k < i + 1; k++) {
                curr += "(";
            }
            for (int j = 0; j <= l - r + i + 1; j++) {
                for (int k = 0; k < j; k++) {
                    curr += ")";
                }
                dfs(ans, curr, n, l + i + 1, r + j);
                for (int k = 0; k < j; k++) {
                    curr.pop_back();
                }
            }
            for (int k = 0; k < i + 1; k++) {
                curr.pop_back();
            }
        }
    }
    vector<string> solution1(int n) {
        vector<string> ans;
        string curr;
        dfs(ans, curr, n, 0, 0);
        return ans;
    }

    void backtracing(vector<string>& ans, string& curr, int n, int l, int r) {
        if (r == n) {
            ans.push_back(curr);
            return;
        }

        if (l < n) {
            curr += "(";
            backtracing(ans, curr, n, l + 1, r);
            curr.pop_back();
        }

        if (l > r) {
            curr += ")";
            backtracing(ans, curr, n, l, r + 1);
            curr.pop_back();
        }
    }

     vector<string> solution2(int n) {
        vector<string> ans;
        string curr;
        backtracing(ans, curr, n, 0, 0);
        return ans;
     }

    vector<string> generateParenthesis(int n) {
        return solution2(n);
        
    }
};
