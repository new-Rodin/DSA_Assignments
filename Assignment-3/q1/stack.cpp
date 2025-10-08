#include <iostream>
#include <vector>
using namespace std;

class MyStack {
    vector<int> arr;
public:
    void insert(int val) {
        arr.push_back(val);
    }

    void remove() {
        if (arr.size() == 0) {
            cout << "Stack Underflow\n";
            return;
        }
        arr.pop_back();
    }

    int topElement() {
        if (arr.size() == 0) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() {
        return arr.size() == 0;
    }

    int count() {
        return arr.size();
    }
};

int main() {
    MyStack s;
    s.insert(11);
    s.insert(22);
    s.insert(33);

    cout << "Top element: " << s.topElement() << "\n";
    s.remove();
    cout << "Top after remove: " << s.topElement() << "\n";

    cout << "Stack count: " << s.count() << "\n";
    cout << "Empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
