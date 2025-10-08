#ifndef STACK_H
#define STACK_H

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
        if (arr.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        arr.pop_back();
    }

    int topElement() {
        if (arr.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() {
        return arr.empty();
    }

    int count() {
        return arr.size();
    }
};

#endif
