class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x, y, xx, yy;
        x = 0; y = 0; 
        xx = m - 1; yy = n - 1;
        int mid_x = (x + xx) / 2;
        while (x <= xx) {
            mid_x = (x + xx) / 2;
            if (matrix[mid_x][n - 1] < target) {
                x = mid_x + 1;
            }
            if (matrix[mid_x][0] > target) {
                xx = mid_x - 1;
            }

            if (matrix[mid_x][0] <= target && matrix[mid_x][n - 1] >= target)
                break;
        }

        if (matrix[mid_x][0] > target || matrix[mid_x][n - 1] < target) 
            return false;


        int mid_y = (y + yy) / 2;
        while (y <= yy) {
                int mid_y = (y + yy) / 2;
                if (matrix[mid_x][mid_y] == target) return true;
                if (matrix[mid_x][mid_y] < target) {
                    y = mid_y + 1;
                } else {
                    yy = mid_y - 1;
                }  
        }
        return false;
    }
};
