class Solution {
public:
    int minInsertions(string s) {

        int ans = 0;      // Number of insertions needed
        int left = 0;     // Number of '(' waiting for '))'

        for (int i = 0; i < s.size(); i++) {

            // Case 1: We found an opening '('
            if (s[i] == '(') {
                left++;
            }

            // Case 2: We found a closing ')'
            else {

                // Check whether another ')' is available
                if (i + 1 < s.size() && s[i + 1] == ')') {

                    // We found a complete '))' pair
                    i++;

                    // If an '(' is waiting, this '))' matches it
                    if (left > 0) {
                        left--;
                    }

                    // No '(' is waiting, so insert one '('
                    else {
                        ans++;
                    }
                }

                // Only one ')' is available
                else {

                    // We need one more ')' to make '))'
                    ans++;

                    // If an '(' is waiting, it is now satisfied
                    if (left > 0) {
                        left--;
                    }

                    // No '(' is waiting
                    else {
                        // We also need to insert '('
                        ans++;
                    }
                }
            }
        }

        // Every remaining '(' needs two ')'
        ans += 2 * left;

        return ans;
    }
};