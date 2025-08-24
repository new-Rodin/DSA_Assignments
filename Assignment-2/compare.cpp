#include <iostream>
#include <list> // For the STL list
#include <chrono> // For timing the operations

using namespace std;
using namespace std::chrono;

// --- Your Custom Linked List (Naive Version) ---
struct node {
    int data;
    node* next;
};

// Head for the naive implementation
node* head_naive = NULL;

// This function has to walk the entire list for every single insertion.
// This is an O(N) operation for each insertion.
void insert_end_naive(int val) {
    node* newnode = new node();
    newnode->data = val;
    newnode->next = NULL;

    if(head_naive == NULL) {
        head_naive = newnode;
        return;
    }
    node* temp = head_naive;
    while(temp->next != NULL) { // This loop is the performance bottleneck
        temp = temp->next;
    }
    temp->next = newnode;
}

// --- Optimized Custom Linked List ---
// We keep track of the tail, so we don't have to search for it.
node* head_optimized = NULL;
node* tail_optimized = NULL;

// By using a tail pointer, this becomes an O(1) operation.
void insert_end_optimized(int val) {
    node* newnode = new node();
    newnode->data = val;
    newnode->next = NULL;

    if(head_optimized == NULL) {
        head_optimized = newnode;
        tail_optimized = newnode; // The first node is both the head and the tail
    } else {
        tail_optimized->next = newnode; // Go directly to the end
        tail_optimized = newnode;      // Update the tail to be the new node
    }
}


int main() {
    // Number of elements to insert
    int N = 50000;

    // --- 1. Benchmarking your Naive Custom List ---
    auto start1 = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        insert_end_naive(i);
    }
    auto stop1 = high_resolution_clock::now();
    cout << "1. Custom List (Naive O(N^2)): "
         << duration_cast<milliseconds>(stop1 - start1).count() << " ms" << endl;

    // --- 2. Benchmarking the Optimized Custom List ---
    auto start2 = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        insert_end_optimized(i);
    }
    auto stop2 = high_resolution_clock::now();
    cout << "2. Custom List (Optimized O(N)): "
         << duration_cast<milliseconds>(stop2 - start2).count() << " ms" << endl;

    // --- 3. Benchmarking the STL std::list ---
    list<int> stl_list;
    auto start3 = high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        stl_list.push_back(i);
    }
    auto stop3 = high_resolution_clock::now();
    cout << "3. STL std::list (O(N)):          "
         << duration_cast<milliseconds>(stop3 - start3).count() << " ms" << endl;

    return 0;
}