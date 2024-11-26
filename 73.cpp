class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool mark_row = 0, mark_col = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        mark_row = true;
                    }
                    if (j == 0) {
                        mark_col = true;
                    }
                    if(i== 0 || j == 0) continue;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][0] == 0) matrix[i][j] = 0;
                if (matrix[0][j] == 0) matrix[i][j] = 0;
            }
         }
        if (mark_row) {
            for (int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
        }

        if (mark_col) {
            for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        
    }
};
