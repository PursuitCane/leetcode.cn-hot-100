class Solution {
public:
    bool col[20], xx[20], yy[20];
    vector<vector<string>> ans;
    void dfs(int n, int row, vector<string>& tmp) {
        if (row == n) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col[i] == false && xx[i - row + n] == false &&
                yy[row + i] == false) {
                col[i] = true;
                xx[i - row + n] = true;
                yy[row + i] = true;
                string st;
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        st += 'Q';
                    else
                        st += '.';
                }
                tmp.push_back(st);
                dfs(n, row + 1, tmp);
                col[i] = false;
                xx[i - row + n] = false;
                yy[row + i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        memset(col, 0, sizeof col);
        memset(xx, 0, sizeof xx);
        memset(yy, 0, sizeof yy);
        vector<string> tmp;
        dfs(n, 0, tmp);
        return ans;
    }
};
