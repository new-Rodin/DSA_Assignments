#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
    vector<int> arr;
    int start;
public:
    MyQueue() { start = 0; }

    void push(int val) {
        arr.push_back(val);
    }

    void pop() {
        if (empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        start++;
    }

    int peek() {
        if (empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[start];
    }

    bool empty() {
        return start >= (int)arr.size();
    }

    int length() {
        return (int)arr.size() - start;
    }
};

int main() {
    MyQueue q;
    q.push(5);
    q.push(15);
    q.push(25);

    cout << "First element: " << q.peek() << "\n";
    q.pop();
    cout << "Front after pop: " << q.peek() << "\n";

    cout << "Queue length: " << q.length() << "\n";
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << "\n";

    return 0;
}
