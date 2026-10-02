# 3Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

 

 **Example 1:** 

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

```

 **Example 2:** 

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

```

 **Example 3:** 

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

```

 

 **Constraints:** 

- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 82.68%)  
**Memory:** 29.1 MB (beats 72.60%)  
**Submitted:** 2026-10-02T19:53:15.268Z  

```cpp

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        vector<vector<int>> result;

        sort(a.begin(), a.end());

        int n = a.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && a[i] == a[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // a[left] + a[right] = -a[i]
            int sum = -a[i];

            while (left < right) {

                int s = a[left] + a[right];

                if (s == sum) {

                    result.push_back({
                        a[i],
                        a[left],
                        a[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right && a[left] == a[left - 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right && a[right] == a[right + 1])
                        right--;
                }

                else if (s < sum) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return result;
    }
};
   

```

---

[View on LeetCode](https://leetcode.com/problems/3sum/)