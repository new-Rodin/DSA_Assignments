#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct Node {
    int key, value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
    int bucketSize;
    vector<Node*> table;

    int hashFunc(int key) {
        return key % bucketSize;
    }

public:
    HashTable(int size) : bucketSize(size), table(size, nullptr) {}

    void insert(int key, int value) {
        int index = hashFunc(key);
        Node* node = table[index];
        while (node) {
            if (node->key == key) {
                node->value = value; // update
                return;
            }
            node = node->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool search(int key, int &value) {
        int index = hashFunc(key);
        Node* node = table[index];
        while (node) {
            if (node->key == key) {
                value = node->value;
                return true;
            }
            node = node->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunc(key);
        Node* node = table[index];
        Node* prev = nullptr;
        while (node) {
            if (node->key == key) {
                if (prev) prev->next = node->next;
                else table[index] = node->next;
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
};

int main() {
    int n;
    cout<<"Enter input size: "<<endl;
    cin>>n;
    vector<int> keys(n);
    for (int i = 0; i < n; i++) keys[i] = rand();

    HashTable ht(2000003);

    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < n; i++) ht.insert(keys[i], i);
    int dummy;
    for (int i = 0; i < n; i++) ht.search(keys[i], dummy);
    for (int i = 0; i < n; i++) ht.remove(keys[i]);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
    cout << "Custom Hash Table time: " << duration1 << " ms" << endl;

    unordered_map<int,int> mp;
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < n; i++) mp[keys[i]] = i;
    for (int i = 0; i < n; i++) dummy = mp[keys[i]];
    for (int i = 0; i < n; i++) mp.erase(keys[i]);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
    cout << "STL unordered_map time: " << duration2 << " ms" << endl;

    return 0;
}

