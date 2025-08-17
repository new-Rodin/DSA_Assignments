# DSA Lab 1: To check for palindrome in a continuos stream of numbers

## Program Description
The problem in this assignment was to check if a number is palindrome or not and the code was to be implemented in c++. This program gives us the answer to this problem.

## The Solution
There are multiple ways to solve this problem. The most common being the one where we find out the reverse of a number, compare it with the original, and check if they are equal. Hence, we ultimately check if reverse == number , which is essentially the whole concept of palindrome.The time complexity for this program is O(n). 
### My Solution
However, this program explores a different solution. To do this we convert the number into a String of length n (the number of digits in the number). And then call a function bool isPalindrome(String s) which checks for palindrome, by checking the characters at the upper(u from the end ) and lower(l from the start), indices respectively. If equal the loop updates the values of u and l by decreasing(u--) and increasing(l++) them repectively. If at some point the characters are not equal. It breaks out of the loop and returns false. The time take to do this is almost half the time as compared to the above solution.

## How to Run the Code

### Pre-requisites
- Languages: cpp (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
- Compiler: gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0

### Execution
To run the main script, navigate to the project's root directory and use the following command:
- First, ensure your package manager's lists are up to date.
- Open the command prompt and use:

```bash
make
./palindrome
```

## Author
Shafqat Jabbar
240150019