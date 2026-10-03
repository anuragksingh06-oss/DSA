class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Boundary before the string starts
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            // Opening bracket → store its index
            if (s[i] == '(') {
                st.push(i);
            }

            // Closing bracket
            else {

                // Match/remove the previous opening bracket
                st.pop();

                // No valid base left → current index becomes new boundary
                if (st.empty()) {
                    st.push(i);
                }

                // Valid substring exists
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};