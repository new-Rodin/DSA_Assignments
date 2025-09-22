#include <bits/stdc++.h>
using namespace std;
const int HASH_SIZE = 1009;

struct Node {
    int key, value;
    Node* next;
};

Node* hashTable[HASH_SIZE];

int hashFunc(int key) {
    return key % HASH_SIZE;
}

void hashInsertOrIncrement(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) {
            curr->value += 1;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = new Node{key, 1, hashTable[idx]};
    hashTable[idx] = newNode;
}

int hashGet(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return 0;
}

int main() {
    int arr[] = {1, 5, 2, 1, 5, 1, 3, 2, 5, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array: "<<endl;
    for (int i = 0; i < n; i++) {
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < n; i++) {
        hashInsertOrIncrement(arr[i]);
    }

    cout << "Frequency Count:\n";
    for (int i = 0; i < n; i++) {
        int freq = hashGet(arr[i]);
        if (freq > 0) {
            cout << arr[i] << " -> " << freq << "\n";
            hashInsertOrIncrement(arr[i]);
        }
    }

    return 0;
}

