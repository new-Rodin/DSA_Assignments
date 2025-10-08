#include <iostream>
#include <chrono>
#include "stack.h"
#include "queue.h"
#include <stack>
#include <queue>
using namespace std;
using namespace std::chrono;

int main() {
    const int N = 1000000;
    MyStack s;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) s.insert(i);
    volatile int x = s.topElement(); 

    auto end = high_resolution_clock::now();
    auto durationCustomStack = duration_cast<microseconds>(end - start).count();

    stack<int> stl_s;
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) stl_s.push(i);
    volatile int y = stl_s.top();
    end = high_resolution_clock::now();
    auto durationStlStack = duration_cast<microseconds>(end - start).count();

    MyQueue q;
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) q.push(i);
    volatile int a = q.peek();
    end = high_resolution_clock::now();
    auto durationCustomQueue = duration_cast<microseconds>(end - start).count();

    queue<int> stl_q;
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) stl_q.push(i);
    volatile int b = stl_q.front();
    end = high_resolution_clock::now();
    auto durationStlQueue = duration_cast<microseconds>(end - start).count();

    cout << "N = " << N << "\n";
    cout << "Custom Stack: " << durationCustomStack << " microseconds\n";
    cout << "STL Stack:    " << durationStlStack << " microseconds\n";
    cout << "Custom Queue: " << durationCustomQueue << " microseconds\n";
    cout << "STL Queue:    " << durationStlQueue << " microseconds\n";
}
