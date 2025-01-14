class Solution {
public:
    string decode(string s, int start, int& ori_len) {
        int index = start;
        int num = 0;
        while (s[index] != '[') {
            num = num* 10 +  s[index] - '0';
            index++;
        }

        string str;
        for (int i = index + 1; i < s.size(); i++) {
            if (s[i] == ']') {
                ori_len = i - start;
                break;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                int len = 0;
                str += decode(s, i, len);
                i += len;
            } else {
                str += s[i];
            }
        }

        string ans;
        while (num--) {
            ans += str;
        }

        return ans;
    }
    string decodeString(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int ori_len = 0;
                ans += decode(s, i, ori_len);
                i += ori_len;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
