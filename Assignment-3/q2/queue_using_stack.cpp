#include <iostream>
#include "stack.h"
using namespace std;

class MyQueueUsingStack {
    MyStack sA, sB;
public:
    MyQueueUsingStack() {}

    void push(int val) {
        sA.insert(val);
    }

    void pop() {
        if (sA.isEmpty() && sB.isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        if (sB.isEmpty()) {
            while (!sA.isEmpty()) {
                int value = sA.topElement();
                sA.remove();
                sB.insert(value);
            }
        }
        cout << "Removed: " << sB.topElement() << "\n";
        sB.remove();
    }
};

int main() {
    MyQueueUsingStack q;
    q.push(100);
    q.push(200);
    q.push(300);
    q.pop();
    q.pop();
}
