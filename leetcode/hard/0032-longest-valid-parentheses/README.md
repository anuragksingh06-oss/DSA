# Longest Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string containing just the characters `'('` and `')'`, return  *the length of the longest valid (well-formed) parentheses **substring*.

 

 **Example 1:** 

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

 **Example 2:** 

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

 **Example 3:** 

```
Input: s = ""
Output: 0

```

 

 **Constraints:** 

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 47.47%)  
**Memory:** 11.9 MB (beats 22.45%)  
**Submitted:** 2026-10-03T11:32:19.055Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)