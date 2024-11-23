class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        int ans_index = 0;
        int end_curr = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start_i = intervals[i][0], end_i = intervals[i][1];
            ans_index = ans.size() -1;
            if (end_curr >= start_i) {
                end_curr = max(end_curr, end_i);
                ans[ans_index][1] = end_curr;
            } else {
                ans.push_back({start_i, end_i});
                end_curr = end_i;
            }
        }

        return ans;   
    }
};
