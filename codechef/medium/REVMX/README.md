# REVMX

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Reversal Maximize

For a permutation $P$ of the integers $[1, N]$, define $f(P)$ as the number of fixed points it has, i.e. $f(P) =$ the number of $i$ such that $P_i = i$.

You are given a permutation $P$, and you can do the following operation  **at most once** :

- Choose $1 \le L \le R \le N$, and reverse the subarray $P[L, R]$.

Maximize $f(P)$ after at most one such reversal.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains a single integer $N$. The second line contains $N$ integers - $P_1, P_2, \ldots, P_N$.
### Output Format

For each test case, output on a new line the maximum value of $f(P)$.

### Constraints
- $1 \le T \le 10^4$
- $2 \le N \le 2 \cdot 10^5$
- $1 \le P_i \le N$
- $P_i \ne P_j$ for all $i \ne j$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
4
5
1 4 3 2 5
6
2 4 6 1 3 5
3
1 2 3
6
5 1 3 2 6 4

```

```
5
1
3
3
```

### Explanation:

 **Test Case 1:**  Reverse the subarray $[2, 4]$ to get $[1, 2, 3, 4, 5]$ which has $5$ fixed points.

 **Test Case 3:**  The original array already has $3$ fixed points, no need of any reversal.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T15:14:08.395Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

const int MOD = 998244353;
    int k;
    scanf("%d", &k);
    while (k--) {
        int n;
        scanf("%d", &n);
        vector<int> p(n + 1), pg(n + 1, 0);
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

        vector<int> tp;
        for (int i = 1; i <= n; i++) {
            while (!tp.empty() && p[tp.back()] < p[i]) tp.pop_back();
            pg[i] = tp.empty() ? 0 : tp.back();
            tp.push_back(i);
        }

        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag(n + 1, vector<int>(n + 1, 0));
        vector<long long> cnt(n + 1, 0);

        for (int s = 1; s <= n; s++) {
            vector<int> even(n + 1, 0), odd(n + 1, 0);
            if (s == 1) {
                odd[0] = 1;
            } else {
                int g = pg[s];
                for (int w = 0; w <= n; w++) {
                    odd[w] = ((pre[s - 1][w] - pre[g][w]) % MOD + MOD) % MOD;
                    if (w >= 1) {
                        int x = diag[s - 1][w - 1];
                        int wg = w - (s - g);
                        int y = (wg >= 0) ? diag[g][wg] : 0;
                        even[w] = ((x - y) % MOD + MOD) % MOD;
                    }
                }
            }
            for (int w = 0; w <= n; w++) {
                pre[s][w] = (pre[s - 1][w] + even[w]) % MOD;
                diag[s][w] = (odd[w] + (w >= 1 ? diag[s - 1][w - 1] : 0)) % MOD;

                if (even[w]) cnt[w] = (cnt[w] + even[w]) % MOD;
                if (odd[w]) {
                    int total = w + (n + 1 - s);
                    if (total <= n) cnt[total] = (cnt[total] + odd[w]) % MOD;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            long long ans = (cnt[i] + cnt[n - i]) % MOD;
            printf("%lld%c", ans, i == n ? '\n' : ' ');
        }
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/REVMX)