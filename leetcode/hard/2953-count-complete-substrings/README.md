# Count Complete Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `word` and an integer `k`.

A substring `s` of `word` is  **complete**  if:

- Each character in s occurs exactly k times.
- The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.

Return  *the number of  **complete** substrings of*  `word`.

A  **substring**  is a  **non-empty**  contiguous sequence of characters in a string.

 

 **Example 1:** 

```
Input: word = "igigee", k = 2
Output: 3
Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.

```

 **Example 2:** 

```
Input: word = "aaabbbccc", k = 3
Output: 6
Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.

```

 

 **Constraints:** 

- 1 <= word.length <= 105
- word consists only of lowercase English letters.
- 1 <= k <= word.length

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.1 MB  
**Submitted:** 2026-09-14T13:14:43.319Z  

```cpp
class Solution {
public:
    int solve(int start,int end,string &word,int k){
        int mx_window=end-start+1;
        int window=k;
        int cnt=0;
        while(window<=mx_window){
            // cout<<window<<endl;
            unordered_map<char,int> mp;
            int j=start;
            for(int i=start;i<=end;i++){
                if(i<start+window){
                    mp[word[i]]++;
                }
                else{
                    mp[word[i]]++;
                    mp[word[j]]=mp[word[j]]-1;
                    if(mp[word[j]]==0)mp.erase(word[j]);
                    j++;
                    

                }
                if(i>=start+window-1){
                    if(mp.size()*k==(i-j+1)){
                    cout<<j<<" "<<i<<endl;
                    cnt++;
                    }
                }
                
            }
            window+=k;
        }
        return cnt;
    }
    int countCompleteSubstrings(string word, int k) {
        int n=word.size();
        int j=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(abs(word[i]-word[i-1])>2){
                cout<<j<<" "<<i-1<<endl;
                cnt+=solve(j,i-1,word,k);
                j=i;
            }
        }
        cnt+=solve(j,n-1,word,k);
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-complete-substrings/)