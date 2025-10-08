#include <iostream>
#include <chrono>
#include "stack.h"
#include "queue.h"
using namespace std;
using namespace std::chrono;

class StackUsingQueue {
    MyQueue q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.peek());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }
    bool isEmpty() { return q1.empty(); }
};

class QueueUsingStack {
    MyStack s1, s2;
public:
    void enqueue(int x) {
        s1.insert(x);
    }
    void dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) return;
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                int val = s1.topElement();
                s1.remove();
                s2.insert(val);
            }
        }
        s2.remove();
    }
    bool isEmpty() { return s1.isEmpty() && s2.isEmpty(); }
};

int main() {
    vector<int> testSizes = {1000, 5000, 10000, 20000};

    cout << "N, StackUsingQueue(ms), QueueUsingStack(ms)\n";

    for (int N : testSizes) {
        StackUsingQueue sq;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) sq.push(i);
        while (!sq.isEmpty()) sq.pop();
        auto stop = high_resolution_clock::now();
        auto stackQueueTime = duration_cast<milliseconds>(stop - start).count();

        QueueUsingStack qs;
        start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) qs.enqueue(i);
        while (!qs.isEmpty()) qs.dequeue();
        stop = high_resolution_clock::now();
        auto queueStackTime = duration_cast<milliseconds>(stop - start).count();

        cout << N << ", " << stackQueueTime << ", " << queueStackTime << "\n";
    }
}
