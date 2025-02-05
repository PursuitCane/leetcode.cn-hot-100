class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        int curr_max = mp[s[0]];
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            //printf("%d %c curr_max %d mp %d count %d \n", i, s[i], curr_max, mp[s[i]], count);
            curr_max = max(curr_max, mp[s[i]]);
            count++;
            if (i == curr_max) {
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
        
    }
};
