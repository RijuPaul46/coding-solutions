# Brace Expansion II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Under the grammar given below, strings can represent a set of lowercase words. Let `R(expr)` denote the set of words the expression represents.

The grammar can best be understood through simple examples:

- Single letters represent a singleton set containing that word. R("a") = {"a"} R("w") = {"w"}
- When we take a comma-delimited list of two or more expressions, we take the union of possibilities. R("{a,b,c}") = {"a","b","c"} R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
- When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression. R("{a,b}{c,d}") = {"ac","ad","bc","bd"} R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}

Formally, the three rules for our grammar:

- For every lowercase letter x, we have R(x) = {x}.
- For expressions e1, e2,..., ek with k >= 2, we have R({e1, e2,...}) = R(e1) ∪ R(e2) ∪...
- For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.

Given an expression representing a set of words under the given grammar, return  *the sorted list of words that the expression represents*.

 

 **Example 1:** 

```
Input: expression = "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]

```

 **Example 2:** 

```
Input: expression = "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.

```

 

 **Constraints:** 

- 1 <= expression.length <= 60
- expression[i] consists of '{', '}', ','or lowercase English letters.
- The given expression represents a set of words based on the grammar given in the description.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 49.56%)  
**Memory:** 15.3 MB (beats 52.63%)  
**Submitted:** 2026-09-25T21:42:23.191Z  

```cpp
class Solution {
    string expression;
    int idx;

    // item -> letter | { expr }
    set<string> item() {
        set<string> ret;
        if (expression[idx] == '{') {
            idx++;
            ret = expr();
        } else {
            ret = {string(1, expression[idx])};
        }
        idx++;
        return move(ret);
    }

    // term -> item | item term
    set<string> term() {
        // Initialize an empty set and take its Cartesian product with
        // subsequent results
        set<string> ret = {""};
        // An item starts with { or a lowercase letter; continue matching only
        // when this condition is met
        while (idx < expression.size() &&
               (expression[idx] == '{' || isalpha(expression[idx]))) {
            auto sub = item();
            set<string> tmp;
            for (auto& left : ret) {
                for (auto& right : sub) {
                    tmp.insert(left + right);
                }
            }
            ret = move(tmp);
        }
        return move(ret);
    }

    // expr -> term | term, expr
    set<string> expr() {
        set<string> ret;
        while (true) {
            // Take the union with the result of term()
            ret.merge(term());
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < expression.size() && expression[idx] == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return move(ret);
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expression = expression;
        this->idx = 0;
        auto ret = expr();
        return {ret.begin(), ret.end()};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/brace-expansion-ii/)