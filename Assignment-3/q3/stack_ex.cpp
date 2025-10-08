#include <iostream>
#include "stack.h"
using namespace std;

string reverseString(const string &s) {
    MyStack st;
    string result = "";

    // Push all characters
    for (char ch : s) {
        st.insert(ch);
    }

    // Pop all characters back
    while (!st.isEmpty()) {
        result += (char)st.topElement();
        st.remove();
    }
    return result;
}

int main() {
    string word = "datastructures";
    cout << "Original: " << word << endl;
    cout << "Reversed: " << reverseString(word) << endl;
    return 0;
}
