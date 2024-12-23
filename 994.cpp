class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool visit[n][m];
        queue<pair<int, int>> que;
        memset(visit, 0, sizeof visit);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    que.push(make_pair(i, j));
                }
            }
        }
        int size = que.size();
        int depth = -1;
        while (!que.empty()) {
            depth++;
            size = que.size();
            while (size--) {
                auto p = que.front(); que.pop();
                for (int i = 0; i < dir.size(); i++) {
                    int x = p.first + dir[i][0];
                    int y = p.second + dir[i][1];
                    if (x < 0 || x >=n || y < 0 || y >= m) continue;
                    if (grid[x][y] == 1 && visit[x][y] == false) {
                        visit[x][y] = true;
                        que.push(make_pair(x, y));
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visit[i][j] == false) return -1;
            }
        }
        return max(depth, 0);
    }
};
