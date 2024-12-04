class Solution {
public:
    bool binary_search(vector<int>& vec, int target) {
        int l = 0, r = vec.size() - 1;
        while (l <= r) {
            int mid = (l + r) /2 ;
            if (vec[mid] == target) return true;
            if (vec[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {   
        bool ans = false;
        for (int i = 0; i < matrix.size(); i++) {
            ans = binary_search(matrix[i], target);
            if (ans) return ans;
        }
        return ans;
    }
};
