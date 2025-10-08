#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    MyQueue line;

    // Customers arrive
    line.push(101);
    line.push(102);
    line.push(103);

    cout << "First customer: " << line.peek() << endl;
    line.pop();

    cout << "Next customer: " << line.peek() << endl;
    line.pop();

    cout << "Remaining in line: " << line.length() << endl;
    cout << "Is line empty? " << (line.empty() ? "Yes" : "No") << endl;

    line.pop();
    cout << "Line empty after serving all: " << (line.empty() ? "Yes" : "No") << endl;

    return 0;
}
