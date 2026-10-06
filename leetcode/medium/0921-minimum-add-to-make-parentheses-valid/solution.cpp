class Solution {
public:
    int minAddToMakeValid(string s) {

        int balance = 0;  // Unmatched '('
        int ans = 0;      // Number of '(' we need to add

        for (int i = 0; i < s.length(); i++) {

            // Opening bracket needs a future ')'
            if (s[i] == '(') {
                balance++;
            }

            // Closing bracket
            else {

                // No '(' available to match this ')'
                if (balance == 0) {
                    ans++;
                }

                // Match ')' with an existing '('
                else {
                    balance--;
                }
            }
        }

        // Remaining '(' need corresponding ')'
        return ans + balance;
    }
};