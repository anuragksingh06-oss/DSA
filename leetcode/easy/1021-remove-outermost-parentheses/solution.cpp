class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";   // Stores the final answer
        int balance = 0;   // Tracks current nesting depth

        for (char ch : s) {

            // If current character is '('
            if (ch == '(') {

                // If already inside a group,
                // this '(' is NOT outermost
                if (balance > 0) {
                    ans += ch;
                }

                // Enter one level deeper
                balance++;
            }

            // Current character is ')'
            else {

                // Come one level back
                balance--;

                // If still inside the group,
                // this ')' is NOT outermost
                if (balance > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};