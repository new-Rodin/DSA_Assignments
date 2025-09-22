#include<iostream>
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

void hashInsert(int key, int value) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = new Node{key, value, hashTable[idx]};
    hashTable[idx] = newNode;
}

bool hashContains(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

int hashGet(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    throw runtime_error("Key not found");
}

void hashRemove(int key) {
    int idx = hashFunc(key);
    Node* curr = hashTable[idx];
    Node* prev = nullptr;
    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else hashTable[idx] = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
int main() {
    
    hashInsert(1, 100);
    hashInsert(2, 200);
    hashInsert(42, 420);
    hashInsert(1009, 500);

    cout << "Hash contains key 2? " 
         << (hashContains(2) ? "Yes" : "No") << endl;

    cout << "Hash contains key 7? " 
         << (hashContains(7) ? "Yes" : "No") << endl;

    cout << "Value at key 1: " << hashGet(1) << endl;
    cout << "Value at key 42: " << hashGet(42) << endl;

    hashInsert(42, 999);
    cout << "Updated value at key 42: " << hashGet(42) << endl;

    hashRemove(2);
    cout << "Hash contains key 2 after removal? "
         << (hashContains(2) ? "Yes" : "No") << endl;

    return 0;
}
