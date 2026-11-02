# Minimum Moves to Equal Array Elements II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` of size `n`, return  *the minimum number of moves required to make all array elements equal*.

In one move, you can increment or decrement an element of the array by `1`.

Test cases are designed so that the answer will fit in a  **32-bit**  integer.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

```

 **Example 2:** 

```
Input: nums = [1,10,2,9]
Output: 16

```

 

 **Constraints:** 

- n == nums.length
- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.7 MB (beats 79.95%)  
**Submitted:** 2026-11-02T07:43:38.058Z  

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Step 1: Sort the array so we can find the median
        sort(nums.begin(), nums.end());

        // Step 2: Find the middle element (median)
        int n = nums.size();
        int median = nums[n / 2];

        // Step 3: Store the total number of moves
        int ans = 0;

        // Step 4: Calculate distance of every element from median
        for(int i = 0; i < n; i++) {

            // Number of moves needed to make nums[i] equal to median
            ans += abs(nums[i] - median);
        }

        // Step 5: Return minimum total moves
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)