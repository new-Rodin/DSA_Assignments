#include<iostream>
using namespace std;
int heapArr[200000];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0 && heapArr[(i - 1) / 2] < heapArr[i]) {
        swap(heapArr[i], heapArr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int n = heapSize;
    while (true) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && heapArr[l] > heapArr[largest]) largest = l;
        if (r < n && heapArr[r] > heapArr[largest]) largest = r;
        if (largest == i) break;
        swap(heapArr[i], heapArr[largest]);
        i = largest;
    }
}

void heapInsert(int val) {
    heapArr[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

int heapPeekMax() {
    if (heapSize == 0) throw runtime_error("Heap empty");
    return heapArr[0];
}

int heapExtractMax() {
    if (heapSize == 0) throw runtime_error("Heap empty");
    int root = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    if (heapSize > 0) heapifyDown(0);
    return root;
}
int main() {

    cout<<"Insert elements, -1 to exit: "<<endl;
    while(true){
      int x;
      cin>>x;
      if(x==-1) break;
      else{
        heapInsert(x);
      }
    }
    cout << "Max: " << heapPeekMax() << endl;
    cout << "Extract: " << heapExtractMax() << endl;
    cout << "New Max: " << heapPeekMax() << endl;

    return 0;
}

