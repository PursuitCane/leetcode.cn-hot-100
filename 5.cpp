class Solution {
public:
    string ret;
    int len;
    void extend(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && 
            s[left] == s[right]) {
                if (right - left + 1 > len) {
                    len = right - left + 1;
                    ret = "";
                    for (int i = left; i <= right; i++) {
                        ret += s[i];
                    }
                }
                left--;
                right++;
            }
    }
    
    string longestPalindrome(string s) {
        len = 1;
        ret = s[0];
        for (int i = 0; i < s.size()-1; i++) {
            extend(s, i, i);
            extend(s, i, i+1);
        }
        return ret;
        
    }
};
