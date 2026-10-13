# Maximum Alternating Sum of Squares

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`. You may  **rearrange the elements**  in any order.

The  **alternating score**  of an array `arr` is defined as:

- score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 +...

Return an integer denoting the  **maximum possible alternating score**  of `nums` after rearranging its elements.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3]

 **Output:**  12

 **Explanation:** 

A possible rearrangement for `nums` is `[2,1,3]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = 22 - 12 + 32 = 4 - 1 + 9 = 12`

 **Example 2:** 

 **Input:**  nums = [1,-1,2,-2,3,-3]

 **Output:**  16

 **Explanation:** 

A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16`

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -4  *104 <= nums[i] <= 4*  104

## Solution

**Language:** C++  
**Runtime:** 56 ms (beats 66.25%)  
**Memory:** 175.9 MB (beats 90.09%)  
**Submitted:** 2026-10-13T04:35:15.601Z  

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return 1LL * a * a > 1LL * b * b;
        });

        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];

            if (i < (n + 1) / 2)
                ans += sq;       // largest squares get '+'
            else
                ans -= sq;       // remaining squares get '-'
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)