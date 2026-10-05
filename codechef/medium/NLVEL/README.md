# NLVEL

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Next Level

Chef is playing a video game and has collected $X$ stars. He needs  **at least $60$ stars**  to unlock the next level.

Determine whether Chef can unlock the next level.

### Input Format

The only line contains an integer $X$ — the number of stars Chef has collected.

### Output Format

Print `YES` if Chef can unlock the next level, otherwise print `NO`.

Each letter of the output may be printed in either uppercase or lowercase, i.e, the strings `NO`, `no`, `No`, and `nO` will all be treated as equivalent.

### Constraints
- $1 \leq X \leq 100$
### Sample 1:
Input
Output

```
45
```

```
No
```

### Explanation:

Chef has $45$ stars, which is fewer than the required $60$ stars.

### Sample 2:
Input
Output

```
80
```

```
Yes
```

### Explanation:

Chef has $80$ stars, which is more than the required $60$ stars.

### Sample 3:
Input
Output

```
60

```

```
Yes

```

### Explanation:

Chef has $60$ stars, which is equal to the required $60$ stars.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T13:31:14.893Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int x;
    cin>>x;
    if(x>=60){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/NLVEL)