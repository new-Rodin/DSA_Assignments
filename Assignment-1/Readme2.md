# DSA Lab 1: To give the matrix multiplication of two randomly generated matrices.

## Program Description
The problem in this assignment was to give the matrix multiplication of two randomly generated matrices A(MxN) and B(NxP) where M,N and P were to be entered by the user.

### My Solution
First of all the inputs M N and P are to be taken and then, to generate the random matrices I used rand() % 99 function to generate a number between 0-99 as entries to these matrices. A point to be noted is the srand(time(NULL)) command that was used at the beginning of the program. It was did so to ensure that a truly random number is generate everytime the program is invoked. And for the multiplication part, the matrices were multiplied by using three nested loops giving a total time complexity of the O(mnp) to the program. 

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
./matrix
```

## Author
Shafqat Jabbar
240150019