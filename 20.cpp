class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        for (char ch : s) {
            if (m.count(ch) == 0) {
                st.push(ch);
                continue;
            }
            if (st.empty() || st.top() != m[ch]) return false;
            st.pop();            
        }

        if (st.empty()) return true;
        return false;
    }
};
