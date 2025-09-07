# DSA Lab 4: To implement Binary Tree,Binary Search Tree, write Prefix Postfix and Infix Notations, and parse a mathematical expression using BODMAS. 

## Program Description
The problem in this assignment was to implement a Binary Tree, write the infix, prefix and postfix expressions for them, implement the Binary Search Tree, perform the searching operation, and parse a mathematical expression (with or without brackets) using the binary tree.

### My Solution
The Tree was implemented using the structre for a node which consists of the information and the node pointers to the right and left children of the Binary Tree.
For the input, since nothing was mentioned the input was taken in the same format as of that of a BST.
The infix, prefix and the postfix notations of the tree were done simply by using recursive functions with the proper ordering of statements respectively.
For implementing the BST, it was simple. The key is in the way how we insert the elements in the tree. The root node is the first one and from then, any number which is smaller than a node goes to its left and the larger one goes to its right. Searching in such a tree becomes very simple as the tree is already sorted. When we arrive at a node we ask three questions. Is the data equal to the key? Is it greater than the key? Or is it smaller? Then the answer to this decides the next node that we will be traversing. This process Significantly reductes the time taken to search for an element.
For parsing a Mathematical expression using BODMAS rule, we do the following:

    1. We keep two stacks, one for the operands and the other for the operators.
    2. We keep on checking for the precedence of the operators, if the operator that is being pushed in the stack is smaller in precedence than the one at the top, then the operator is popped along with the two consecutive operands and then is packed into a subtree. This subtree is then pushed back on top of the operands stack.
    3.After we are done with the input and everything now has been placed on the stack then Step-2 is continued untill all the operators are exhausted from the stack.

For verification we then print the postorder/inorder of the tree that is now containing the operators as the parent nodes and the operands/numbers as the leaf nodes.

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
./tree or ./BST or ./BodmasTree
```

## Author
Shafqat Jabbar
240150019