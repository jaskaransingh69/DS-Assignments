#include <iostream>
#include <vector>
using namespace std;
void heapifyMax(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}
void heapifyMin(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}
// Increasing order using max-heap
void heapSortInc(vector<int>& a) {
    int n = a.size();
    // build max heap
    for (int i = n/2 - 1; i >= 0; --i) heapifyMax(a, n, i);
    // extract elements
    for (int i = n-1; i > 0; --i) {
        swap(a[0], a[i]);
        heapifyMax(a, i, 0);
    }
}
// Decreasing order using min-heap
void heapSortDec(vector<int>& a) {
    int n = a.size();
    // build min heap
    for (int i = n/2 - 1; i >= 0; --i) heapifyMin(a, n, i);
    // extract
    for (int i = n-1; i > 0; --i) {
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}
int main() {
    vector<int> v = {4, 10, 3, 5, 1};
    vector<int> a = v;
    heapSortInc(a);
    cout << "Heapsort increasing: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';

    vector<int> b = v;
    heapSortDec(b);
    cout << "Heapsort decreasing: ";
    for (int x : b) cout << x << ' ';
    cout << '\n';
    return 0;
}
