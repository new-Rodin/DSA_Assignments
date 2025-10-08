#include <iostream>
#include "queue.h"
using namespace std;

class StackUsingQueue {
    MyQueue q1, q2;
public:
    StackUsingQueue() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.peek());  // FIX: use front()
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Empty\n";
            return;
        }
        cout << "Popped: " << q1.peek() << "\n";  // FIX: use front()
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.peek();  // FIX: use front()
    }
};

int main() {
    StackUsingQueue s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Top: " << s.top() << "\n";
    s.pop();
    cout << "Top after pop: " << s.top() << "\n";
}
