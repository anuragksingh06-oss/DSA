# Minimum Insertions to Balance a Parentheses String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is  **balanced**  if:

- Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
- Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

- For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return  *the minimum number of insertions*  needed to make `s` balanced.

 

 **Example 1:** 

```
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.

```

 **Example 2:** 

```
Input: s = "())"
Output: 0
Explanation: The string is already balanced.

```

 **Example 3:** 

```
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of '(' and ')' only.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 87.33%)  
**Memory:** 15.6 MB (beats 53.60%)  
**Submitted:** 2026-10-09T08:14:34.144Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)