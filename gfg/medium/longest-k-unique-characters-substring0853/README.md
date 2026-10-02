# Longest Substring with K Uniques

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string  **s**  consisting only lowercase alphabets and an integer  **k**. Your task is to find the  **length** of the  **longest substring**  that contains exactly  **k**  distinct characters.

 **Note :**  If no such substring exists, return  **-1**. 

 **Examples:** 

```
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

```

```
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.

```

```
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T19:34:48.618Z  

```cpp
class Solution {
  public:
int longestKSubstr(string &s, int k) {

    int low = 0, high = 0;          // Sliding window: [low ... high]
    int res = INT_MIN;              // Store maximum length
    int n = s.size();               // String length

    unordered_map<char, int> f;     // Character -> frequency

    // Expand window using high
    for (high = 0; high < n; high++) {

        f[s[high]]++;               // Add current character

        // If unique characters > k, shrink from left
        while (f.size() > k) {

            f[s[low]]--;             // Remove left character

            low++;                   // Move left pointer

            // If frequency became 0, remove character from map
            if (f[s[low - 1]] == 0)
                f.erase(s[low - 1]);
        }

        // Window has exactly k unique characters
        if (f.size() == k) {

            int len = high - low + 1; // Current window length

            res = max(res, len);      // Keep maximum length
        }
    }

    // No substring with exactly k unique characters
    if (res == INT_MIN)
        return -1;

    return res;
}
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)