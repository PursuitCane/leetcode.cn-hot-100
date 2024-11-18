class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> str_map;
        vector<vector<string>> ans;
        int count = 0;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (str_map.find(tmp) != str_map.end()) {
                ans[str_map[tmp]].push_back(strs[i]);
                continue;
            }
            str_map[tmp] = count++;
            vector<string> tmp_vec;
            tmp_vec.push_back(strs[i]);
            ans.push_back(tmp_vec);
        }
        return ans;      
    }
};
