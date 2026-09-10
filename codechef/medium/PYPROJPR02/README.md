# PYPROJPR02

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Get a random number

Let us start with the simplest component. Our project has to generate a hidden number randomly.

### How to generate a random number?

In Python, the `randrange()` function is a part of the `random` module and is used to generate a random integer within a specified range.
It allows you to generate random integers similar to the built-in `range()` function.

Here's the syntax of the randrange() function:

```
# random.randrange(start, stop, [step])

random_even_number = random.randrange(10, 20, 2)
print(random_even_number)

```

 **Note:**  The parameter  **step**  is not required if you just want to generate a random number without conditions.

### Task

Update the function `getRandomNumber()` in the IDE to generate a random number between 1 and 100 (including `1` and excluding `100`).

Run the code and see the output in Preview tab. When you are satisfied with your output, you can  **Submit**  your code.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-10T08:33:19.965Z  

```cpp
import random

#complete this function to generate a random number between 1 and 100 
def getRandomNumber():
    return random.randrange(1,100)


def runGuess():
    secretNumber = getRandomNumber()
    print("The number is", secretNumber)


if __name__ == '__main__':
    runGuess()
```

---

[View on CodeChef](https://www.codechef.com/problems/PYPROJPR02)