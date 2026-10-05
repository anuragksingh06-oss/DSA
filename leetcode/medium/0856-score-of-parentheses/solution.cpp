class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;

        // Base score for the outermost level
        st.push(0);

        for (int i = 0; i < s.length(); i++) {

            // '(' -> enter a new level
            if (s[i] == '(') {
                st.push(0);
            }

            // ')' -> finish the current level
            else {

                // Get the score inside the current pair
                int inside = st.top();
                st.pop();

                // () has score 1
                // (A) has score 2 * A
                int score = (inside == 0) ? 1 : 2 * inside;

                // Add this score to the previous level
                st.top() += score;
            }
        }

        return st.top();
    }
};