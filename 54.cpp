class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> col_border(col + 4), row_border(row + 4);
        for (int i = 0; i <= (col / 2 + 1); i++) {
            col_border[i * 2] = col - i - 1;
            col_border[i*2 + 1] = i;
        }
        for (int i = 0; i <= (row /2 +1); i++) {
            row_border[i * 2] = row - i - 1;
            row_border[i*2 + 1] = i + 1;
        }
        vector<vector<bool>> m(row, vector<bool>(col));
        int x, y, d, step;
        x = y = d = step = 0;
        vector<int> ans;
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        while (true) {
            while (y != col_border[step]) {
                ans.push_back(matrix[x][y]);
                m[x][y] = true;
                x += dir[d][0], y += dir[d][1];
            }
            ans.push_back(matrix[x][y]);
            m[x][y] = true;
            d = (d+1) % 4;
            x += dir[d][0], y += dir[d][1];
            if (x >= row || x < 0) return ans;
            if (m[x][y]) return ans;
            while (x != row_border[step]) {
                ans.push_back(matrix[x][y]);
                m[x][y] = true;
                x += dir[d][0], y += dir[d][1];
            }
            ans.push_back(matrix[x][y]);
            m[x][y] = true;
            d = (d+1) % 4;
            x += dir[d][0], y += dir[d][1];
            if (y >= col || y < 0) return ans;
            if (m[x][y]) return ans;
            step++;
        }
        return ans;
    }
};
