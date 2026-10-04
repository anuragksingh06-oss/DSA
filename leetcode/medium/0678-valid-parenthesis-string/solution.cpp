class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;   // Minimum possible balance
        int high = 0;  // Maximum possible balance

        for (int i = 0; i < s.length(); i++) {

            // '(' increases the balance
            if (s[i] == '(') {
                low++;
                high++;
            }

            // ')' decreases the balance
            else if (s[i] == ')') {
                low--;
                high--;
            }

            // '*' can be '(', ')' or empty
            else {
                low--;      // Treat '*' as ')'
                high++;     // Treat '*' as '('
            }

            // Balance can never be negative
            low = max(0, low);

            // Even maximum balance is negative → impossible
            if (high < 0) {
                return false;
            }
        }

        // Valid if zero balance is possible
        return low == 0;
    }
};