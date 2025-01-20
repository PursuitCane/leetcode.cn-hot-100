class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (st.size() && temperatures[st.top()] < temperatures[i]) {
                int top_index = st.top();
                ans[top_index] = i - top_index;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
