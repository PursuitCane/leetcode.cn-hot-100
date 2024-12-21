class Solution {
public:
    vector<vector<int> > dir;
    void dfs(int x, int y, vector<vector<char>>& grid) {
        int xx = grid.size(); 
        int yy = grid[0].size();
        if (x < 0 || x >= xx || y < 0 || y >= yy) return;
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        for (int d = 0; d < dir.size(); d++) {
            dfs(x + dir[d][0], y + dir[d][1], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        dir.push_back({-1, 0});
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({0, -1});
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};
