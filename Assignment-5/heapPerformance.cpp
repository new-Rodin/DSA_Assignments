#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<int> heap;
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void heapifyDown(int i) {
    int largest = i;
    int l = left(i), r = right(i);

    if (l < heap.size() && heap[l] > heap[largest])
        largest = l;
    if (r < heap.size() && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

// Operations
void insertHeap(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

int extractMax() {
    if (heap.empty()) return INT_MIN;
    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return root;
}

int peekHeap() {
    if (heap.empty()) return INT_MIN;
    return heap[0];
}



int main() {
    cout<<"Enter input size: "<<endl;
    
    int n;cin>>n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) data[i] = rand();

    auto start1 = high_resolution_clock::now();
    for (int x : data) insertHeap(x);
    while (!heap.empty()) extractMax();
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1).count();
    cout << "Custom Heap time: " << duration1 << " ms" << endl;

    auto start2 = high_resolution_clock::now();
    priority_queue<int> pq;
    for (int x : data) pq.push(x);
    while (!pq.empty()) pq.pop();
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2).count();
    cout << "STL priority_queue time: " << duration2 << " ms" << endl;

    return 0;
}

