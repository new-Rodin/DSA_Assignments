#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <cstdlib>

using namespace std;
using clk = chrono::high_resolution_clock;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val)
        root->left = insertNode(root->left, x);
    else if (x > root->val)
        root->right = insertNode(root->right, x);
    return root;
}

bool searchNode(Node* root, int x) {
    if (!root) return false;
    if (root->val == x) return true;
    if (x < root->val)
        return searchNode(root->left, x);
    else
        return searchNode(root->right, x);
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (!root) return nullptr;
    if (x < root->val)
        root->left = deleteNode(root->left, x);
    else if (x > root->val)
        root->right = deleteNode(root->right, x);
    else {
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* mn = findMin(root->right);
            root->val = mn->val;
            root->right = deleteNode(root->right, mn->val);
        }
    }
    return root;
}

void deleteTree(Node* r) {
    if (!r) return;
    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
}

int main() {
    cout << "Compare custom BST vs std::set \n";
    int N;
    cout << "Enter number of values : ";
    cin >> N;
    if (!(N)) return 0;
    vector<int> data(N);
    srand(123);
    for (int i = 0; i < N; ++i)
        data[i] = rand();
    Node* root = nullptr;
    auto t1 = clk::now();
    for (int x : data)
        root = insertNode(root, x);
    auto t2 = clk::now();
    long long bst_insert_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    set<int> s;
    t1 = clk::now();
    for (int x : data)
        s.insert(x);
    t2 = clk::now();
    long long set_insert_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    int Q = min(N, 10000);
    t1 = clk::now();
    int found1 = 0;
    for (int i = 0; i < Q; ++i)
        if (searchNode(root, data[i]))
            ++found1;
    t2 = clk::now();
    long long bst_search_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    t1 = clk::now();
    int found2 = 0;
    for (int i = 0; i < Q; ++i)
        if (s.find(data[i]) != s.end())
            ++found2;
    t2 = clk::now();
    long long set_search_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    int D = min(N, 5000);
    t1 = clk::now();
    for (int i = 0; i < D; ++i)
        root = deleteNode(root, data[i]);
    t2 = clk::now();
    long long bst_delete_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    t1 = clk::now();
    for (int i = 0; i < D; ++i)
        s.erase(data[i]);
    t2 = clk::now();
    long long set_delete_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    cout << "Results (milliseconds):\n";
    cout << "BST insert: " << bst_insert_ms << " ms, set insert: " << set_insert_ms << " ms\n";
    cout << "BST search: " << bst_search_ms << " ms, set search: " << set_search_ms << " ms\n";
    cout << "BST delete: " << bst_delete_ms << " ms, set delete: " << set_delete_ms << " ms\n";
   
    deleteTree(root);
    return 0;
}
