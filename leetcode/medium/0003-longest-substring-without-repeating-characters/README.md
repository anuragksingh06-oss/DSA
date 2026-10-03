# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** C++  
**Runtime:** 191 ms (beats 32.82%)  
**Memory:** 56.8 MB (beats 31.80%)  
**Submitted:** 2026-10-02T19:37:58.734Z  

```cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int ans = 0;

        map<char, int> mp;

        for (int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while (mp[s[right]] > 1) {

                mp[s[left]]--;

                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};   //trying to push on git hub

   
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)