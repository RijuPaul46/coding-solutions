# RMEN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Reverse Mirror Encoding

You are given an encoded string $S$ representing a message written using lowercase English letters.

The message uses a  **reverse mirror encoding**.

For letters from `a` to `n`, each letter is replaced by its mirror within this range. For example, `a` becomes `n`, `b` becomes `m`, and `j` becomes `e`.

For letters from `o` to `z`, each letter is replaced by its mirror within this range, followed by `#`. For example, `z` becomes `o#`, `y` becomes `p#`, and `t` becomes `u#`.

You are given a message encoded using these rules. Decode it and print the  **original message**.

### Input Format
- The first line contains the encoded string $S$.
### Output Format
- Print a single string — the decoded message.
### Constraints
- $2 \le |S| \le 10^3$
- $S$ contains only lowercase English letters and #.
- Every # appears immediately after a letter from o to z.
- The encoded string is guaranteed to be valid.
### Sample 1:
Input
Output

```
u#jlg
```

```
tech
```

### Explanation:

The encoded tokens are decoded as:

`u#` $\rightarrow$ `t`, `j` $\rightarrow$ `e`, `l` $\rightarrow$ `c`, `g` $\rightarrow$ `h`.

Therefore, the decoded message is `tech`.

### Sample 2:
Input
Output

```
mjt#av#u#z#y#y#nmcj
```

```
beunstoppable
```

### Explanation:

Decoding each token in order gives:

`b`, `e`, `u`, `n`, `s`, `t`, `o`, `p`, `p`, `a`, `b`, `l`, `e`.

Therefore, the decoded message is `beunstoppable`.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T13:50:38.874Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/RMEN)