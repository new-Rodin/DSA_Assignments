# Linked List Implementations and Examples

This project contains the C++ implementations for three fundamental types of linked lists: **Singly**, **Doubly**, and **Circular**. It also includes practical examples for each type to demonstrate their real-world use cases. The code is written as an interactive command-line interface.

---

## File Structure

The project is organized into two main folders: `lists` for the core data structure implementations and `examples` for their practical applications.

```

/
├── lists/
│   ├── SingleLL.cpp
│   ├── DoubleLL.cpp
│   └── CircularLL.cpp
└── examples/
├── 1\_Playlist\_SinglyLL.cpp
├── 2\_BrowserHistory\_DoublyLL.cpp
└── 3\_GameTurns\_CircularLL.cpp

```

---

## Linked List Implementations (`lists/` folder)

This folder contains the full implementations of the linked lists with a menu-driven program to perform various operations.

### 1. Singly Linked List (`SingleLL.cpp`)
This is the most basic linked list. It's a collection of nodes where traversal is only possible in one direction (forward).

* **Structure:** Each node contains an integer `info` and a `next` pointer that points to the subsequent node. The last node's `next` pointer is `NULL`.
* **Operations Implemented:** Insertion (at end, after a node), Deletion of a specific value, Searching for a value, Reversing the list, and Displaying the list.

### 2. Doubly Linked List (`DoubleLL.cpp`)
This is a more complex list that allows for traversal in both forward and backward directions.

* **Structure:** Each node contains an integer `info`, a `next` pointer to the next node, and a `prev` pointer to the previous node.
* **Operations Implemented:** Insertion (at end, after/before a node), Deletion, Searching, Reversing, and Displaying the list. The `prev` pointer makes operations like "insert before" and deletion more efficient than in a singly linked list.

### 3. Circular Linked List (`CircularLL.cpp`)
This is a list where all nodes are connected in a continuous circle. There is no `NULL` at the end.

* **Structure:** Each node contains an integer `info` and a `next` pointer. The key difference is that the `next` pointer of the very last node points back to the head node, creating a loop.
* **Operations Implemented:** All the same operations as the singly linked list, but the logic is adapted for the circular structure. For example, traversal involves looping until you arrive back at the head node.

---

## Examples of Linked Lists in Action (`examples/` folder)

This folder contains simplified, non-interactive programs that demonstrate a clear use case for each type of linked list.

### 1. Singly Linked List: Music Playlist 🎵
* **Overview:** This example shows how a singly linked list can be used to manage a simple music playlist.
* **How it Works:** Each song title is stored in a node. Since you typically only go to the **next** song, the forward-only nature of a singly linked list is a perfect and memory-efficient fit. The program creates a playlist and simulates playing through it one song at a time.

### 2. Doubly Linked List: Browser History 🌐
* **Overview:** This program simulates the "back" and "forward" functionality of a web browser's session history.
* **How it Works:** Each webpage URL is a node. A `current_page` pointer keeps track of your location. The `next` pointer allows you to move **forward**, and the `prev` pointer allows you to go **back**. This two-way navigation is only possible because of the doubly linked structure.

### 3. Circular Linked List: Game Turns 🎲
* **Overview:** This example demonstrates how a circular linked list can manage turns in a multiplayer game.
* **How it Works:** Each player is a node in the list. After the last player takes their turn, the list naturally loops back to the first player. This creates a continuous, fair cycle of turns that is ideal for round-robin scenarios. The program simulates several rounds of a game, showing how the turn passes from player to player in a circle.

## Performance Comparison: Custom vs. STL

A benchmark was performed to compare the speed of the custom linked list implementations against the highly optimized C++ Standard Template Library (STL) containers. The test measured the time taken to insert 50,000 elements at the end of a list.

### The Bottleneck: Inefficient Insertion
The initial custom `insertend` function was extremely slow. This is because for every new item added, the code had to walk the entire list from the very beginning (`head`) just to find the end.

* **Complexity:** This approach has a time complexity of **O(N²)**. It's like adding a new car to a very long train by walking from the engine to the back *every single time*. As the train gets longer, the walk takes longer.

### The Optimized Approach: A Fairer Fight
The STL's `push_back` function is incredibly fast. This is because it always keeps a pointer to the last element, so it can add a new element in a single step (**O(1)**).

To make a fair comparison, the custom list was improved by adding a `tail` pointer. This also makes its `insertend` operation **O(1)**, and its performance becomes just as fast as the STL version.

### Summary Table: Custom vs. STL

| Feature | Custom Implementation | STL Implementation (`std::list`, etc.) |
| :--- | :--- | :--- |
| **Memory Management** | **Manual and Error-Prone.** You must manually use `new` and `delete`. Forgetting to `delete` causes memory leaks. | **Automatic and Safe.** The STL container automatically manages memory. When the list goes out of scope, it frees all memory. |
| **Ease of Use** | **Verbose and Complex.** Requires direct pointer manipulation (`p->next`, etc.), which is hard to read and easy to get wrong. | **High-Level and Readable.** Operations are clear and concise (`myList.push_back(value)`). Easy to use with modern `for` loops. |
| **Features & Algorithms** | **Barebones.** Every operation (sorting, reversing, finding an element) must be written by hand. | **Rich and Powerful.** Comes with many built-in functions (`.sort()`, `.reverse()`) and works with the C++ `<algorithm>` library. |

## Author

- **Name:** Shafqat Jabbar
- **Roll Number:** 240150019