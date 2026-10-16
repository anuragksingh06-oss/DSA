# Subarrays Distinct Element Sum of Squares II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed** integer array `nums`.

The  **distinct count**  of a subarray of `nums` is defined as:

- Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].

Return  *the sum of the  **squares**  of  **distinct counts**  of all subarrays of* `nums`.

Since the answer may be very large, return it  **modulo**  `109 + 7`.

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

```

 **Example 2:** 

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 369 ms (beats 35.07%)  
**Memory:** 148.5 MB (beats 57.14%)  
**Submitted:** 2026-10-16T10:59:50.961Z  

```cpp
class Solution {
public:
    const long long MOD = 1000000007;

    vector<long long> sum;      // sum of distinct counts
    vector<long long> sq;       // sum of squares of distinct counts
    vector<long long> lazy;     // pending range increment

    // Apply +val to every element in this segment
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // (x + val)^2 = x^2 + 2*x*val + val^2
        sq[node] = (sq[node] + 2 * val % MOD * sum[node]) % MOD;
        sq[node] = (sq[node] + len % MOD * val % MOD * val) % MOD;

        // Update sum
        sum[node] = (sum[node] + len % MOD * val) % MOD;

        // Store lazy update
        lazy[node] += val;
        lazy[node] %= MOD;
    }

    // Push pending update to children
    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(2 * node, l, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    // Add +val to range [ql, qr]
    void update(int node, int l, int r,
                int ql, int qr, long long val) {

        // No overlap
        if (qr < l || r < ql)
            return;

        // Complete overlap
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);

        // Combine children
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        // Segment tree arrays
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // Previous occurrence of every number
        unordered_map<int, int> last;

        long long ans = 0;

        for (int right = 0; right < n; right++) {

            int prev = -1;

            // Find previous occurrence
            if (last.count(nums[right]))
                prev = last[nums[right]];

            /*
                nums[right] is new for starting positions
                prev+1 ... right

                Therefore distinct count increases by 1
                for this whole range.
            */
            update(1, 0, n - 1, prev + 1, right, 1);

            // Remember latest occurrence
            last[nums[right]] = right;

            // Root stores sum of squares for all subarrays
            // ending at 'right'
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)