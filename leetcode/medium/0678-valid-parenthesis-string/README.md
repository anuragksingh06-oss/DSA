# Valid Parenthesis String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s` containing only three types of characters: `'('`, `')'` and `' *'`, return `true`* if *`s`* is  **valid** *.

The following rules define a  **valid**  string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

 **Example 1:** 

```
Input: s = "()"
Output: true

```

 **Example 2:** 

```
Input: s = "(*)"
Output: true

```

 **Example 3:** 

```
Input: s = "(*))"
Output: true

```

 **Example 4:** 

```
Input: s = "("
Output: false

```

 

 **Constraints:** 

- 1 <= s.length <= 100
- s[i] is '(', ')' or '*'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8 MB (beats 93.14%)  
**Submitted:** 2026-10-04T05:09:08.713Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)