class Solution {
public:
    bool visit[10][10];
    vector<vector<int>> dir; 
    bool ans;
    void dfs(vector<vector<char>>& board, int x, int y, string& word, int index) {
        if (ans) return;
        if (index >= word.size()) {
            ans = true;
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < dir.size(); i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
            if (board[xx][yy] == word[index] && visit[xx][yy] == false) {
                visit[xx][yy] = true;
                dfs(board, xx, yy, word, index + 1);
                visit[xx][yy] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        ans = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    memset(visit, 0, sizeof visit);
                    visit[i][j] = true;
                    dfs(board, i, j, word, 1);
                }
            }
        }
        dfs(board, 0, 0, word, 0);
        return ans;
    }
};
