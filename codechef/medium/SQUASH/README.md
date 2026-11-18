# SQUASH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Squash

You are given a string $S$ of length $N$ consisting only of the characters `A` and `B`, and an integer $K$.

In one operation, you may choose two adjacent  **equal**  characters of $S$ and delete exactly one of them.

Determine whether it is possible to obtain a string of length exactly $K$ after performing zero or more operations.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains two space-separated integers $N$ and $K$. The second line contains the string $S$.
### Output Format

For each test case, output on a new line `YES` if a string of length $K$ can be obtained, and `NO` otherwise.

Each letter of `YES` and `NO` may be printed in either uppercase or lowercase.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq K \leq N \leq 100$
- $S$ consists only of the characters A and B.
### Sample 1:
Input
Output

```
5
10 3
BBBAAAAAAB
4 3
ABAB
5 1
AAAAA
6 6
ABBAAB
9 4
ABBBAABAA

```

```
YES
NO
YES
YES
NO

```

### Explanation:

 **Test case $1$:**  `BBBAAAAAAB` can be reduced to `BAB`, which has length $3$. One valid sequence is as follows:

- Choose one of the first two characters and delete them. The string becomes BBAAAAAAB.
- Again choose one of the first two characters and delete them. The string becomes BAAAAAAB.
- Now repeatedly choose two adjacent A's and delete one of them. The string will eventually become BAB.

 **Test case 2:**  No two adjacent characters of `ABAB` are equal, so no operation can be performed and the length stays $4$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T15:26:41.569Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int M;
	cin >> M;
	while(M--){
	    int N,K;
	    string S;
	    cin >> N >> K >> S;
	    int run = 1;
	    for(int i=1 ; i<N; i++){
	        if(S[i] != S[i-1]) run++;
	    }
	    cout << (run <= K? "YES" : "NO") <<"\n";
	}
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/SQUASH)