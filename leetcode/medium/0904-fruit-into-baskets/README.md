# Fruit Into Baskets

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the  **type**  of fruit the `ith` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array `fruits`, return  *the  **maximum**  number of fruits you can pick*.

 

 **Example 1:** 

```
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

```

 **Example 2:** 

```
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

```

 **Example 3:** 

```
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

```

 

 **Constraints:** 

- 1 <= fruits.length <= 105
- 0 <= fruits[i] < fruits.length

## Solution

**Language:** C++  
**Runtime:** 24 ms (beats 90.66%)  
**Memory:** 84.8 MB (beats 82.91%)  
**Submitted:** 2026-10-04T05:49:06.319Z  

```cpp
class Solution {
public:
    int totalFruit(vector<int>& a) {
        
        unordered_map<int, int> f;  // fruit type -> frequency
        
        int low = 0, high = 0;
        int n = a.size();
        int res = INT_MIN;
        
        for (high = 0; high < n; high++) {
            
            // Add current fruit to the window
            f[a[high]]++;
            
            // More than 2 fruit types -> shrink window
            while (f.size() > 2) {
                
                // Remove leftmost fruit
                f[a[low]]--;
                
                // If no more of this fruit exists, remove its type
                if (f[a[low]] == 0) {
                    f.erase(a[low]);
                }
                
                // Move left pointer
                low++;
            }
            
            // Current valid window length
            int len = high - low + 1;
            
            // Update maximum length
            res = max(res, len);
        }
        
        return res;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/fruit-into-baskets/)