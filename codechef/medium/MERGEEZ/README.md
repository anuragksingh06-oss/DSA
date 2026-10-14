# MERGEEZ

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Merging (Easy)

Define $merge(A, B)$ as the array $C$ formed by the following process:

- Initialize $i = 0, j = 0, C = []$ (empty array)
- While both $i < |A|, j < |B|$ holds, do the following: if $A_i < B_j$, append $A_i$ to $C$ and increment $i$ by $1$. Else, append $B_j$ to $C$ and increment $j$ by $1$.
- While $i < |A|$, append $A_i$ to $C$ and increment $i$ by $1$.
- While $j < |B|$, append $B_j$ to $C$ and increment $j$ by $1$.

For example, it can be shown that $merge([2, 3], [1, 4]) = [1, 2, 3, 4]$, and $merge([3, 2], [4, 1]) = [3, 2, 4, 1]$.

You are given a permutation $P$ of the integers $[1, N].$

For each $i = 0, 1, 2, \ldots, N$, count how many pairs of arrays $A$ and $B$ exist such that $merge(A, B) = P$ and $|A| = i$. Since the answers may be large, output them modulo $998244353$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains a single integer $N$. The second line contains $N$ integers - $P_1, P_2, \ldots, P_N$.
### Output Format

For each test case, output on a new line $N + 1$ integers - the number of pairs of arrays $A$ and $B$ such that $|A| = i$ for each $i = 0, 1, \ldots, N$ modulo $998244353$.

### Constraints
- $1 \le T \le 100$
- $1 \le N \le 5000$
- $1 \le P_i \le N$
- $P_i \ne P_j$ for all $i \ne j$
- The sum of $N$ over all test cases does not exceed $5000$.
### Sample 1:
Input
Output

```
4
4
1 2 3 4
4
3 2 4 1
1
1
7
2 4 3 6 5 1 7

```

```
1 4 6 4 1
1 0 2 0 1
1 1
1 2 2 3 3 2 2 1
```

### Explanation:

 **Test Case 1:**  Every sorted subset of $P$ works as $A$, and its complement as $B$. This is because the merge (as defined) of $2$ sorted arrays will always be sorted.

 **Test Case 2:**  The possibilities are:

- $A = [], B = [3, 2, 4, 1]$
- $A = [3, 2], B = [4, 1]$
- $A = [4, 1], B = [3, 2]$
- $A = [3, 2, 4, 1], B = []$

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T15:12:58.420Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        vector<int> p(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        // pg[i] = index of previous greater element (0 if none)
        vector<int> pg(n + 2, 0);
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && p[st.top()] < p[i]) st.pop();
            pg[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }

        // PF[m][a]: prefix over positions of "last run is A, total A = a"
        // PG[m][b]: prefix over positions of "last run is B, total B = b"
        vector<vector<long long>> PF(n + 1), PG(n + 1);

        auto getPF = [&](int m, int a) -> long long {
            if (m < 0 || a > m) return 0;
            return PF[m][a];
        };
        auto getPG = [&](int m, int b) -> long long {
            if (m < 0 || b > m) return 0;
            return PG[m][b];
        };

        PF[0].assign(1, 1);
        PG[0].assign(1, 1);

        vector<long long> ans(n + 1, 0);

        for (int r = 1; r <= n; r++) {
            int lo = (r < n) ? pg[r + 1] : 0;
            bool ok = (lo <= r - 1);

            vector<long long> f(r + 1, 0), g(r + 1, 0);

            if (ok) {
                for (int a = 0; a <= r; a++) {
                    // last run is B, A count stays the same
                    g[a] = (getPF(r - 1, a) - getPF(lo - 1, a) + MOD) % MOD;
                    // last run is A, B count stays the same
                    int b = r - a;
                    f[a] = (getPG(r - 1, b) - getPG(lo - 1, b) + MOD) % MOD;
                }
            }

            PF[r].assign(r + 1, 0);
            PG[r].assign(r + 1, 0);
            for (int a = 0; a <= r; a++) {
                PF[r][a] = (getPF(r - 1, a) + f[a]) % MOD;
                int b = r - a;
                PG[r][b] = (getPG(r - 1, b) + g[a]) % MOD;
            }

            if (r == n) {
                for (int a = 0; a <= n; a++) {
                    ans[a] = (f[a] + g[a]) % MOD;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/MERGEEZ)