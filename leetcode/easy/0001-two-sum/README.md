# Two Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of integers `nums` and an integer `target`, return  *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have  ***exactly *one solution**, and you may not use the* same* element twice.

You can return the answer in any order.

 

 **Example 1:** 

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

```

 **Example 2:** 

```
Input: nums = [3,2,4], target = 6
Output: [1,2]

```

 **Example 3:** 

```
Input: nums = [3,3], target = 6
Output: [0,1]

```

 

 **Constraints:** 

- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

 

 **Follow-up:** Can you come up with an algorithm that is less than `O(n2)` time complexity?

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 77.58%)  
**Memory:** 14.8 MB (beats 58.14%)  
**Submitted:** 2026-10-02T11:25:42.621Z  

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Store: number -> its index
        unordered_map<int, int> mp;

        // Check each number one by one
        for (int i = 0; i < nums.size(); i++) {

            // Find the number required to make target
            int needed = target - nums[i];

            // If needed number is already stored, answer found
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            // Store current number and its index
            mp[nums[i]] = i;
        }

        // No pair found (normally won't happen due to problem constraint)
        return {};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/two-sum/)