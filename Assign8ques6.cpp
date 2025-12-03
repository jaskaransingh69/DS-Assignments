#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void demoStdPQ() {
    priority_queue<int> pq; // max-heap
    pq.push(5); pq.push(1); pq.push(10);
    cout << "std::priority_queue top: " << pq.top() << '\n';
    pq.pop();
    cout << "after pop top: " << pq.top() << '\n';
}
// 2) Custom binary max-heap
class MaxHeap {
    vector<int> a;
public:
    MaxHeap() {}
    void push(int x) {
        a.push_back(x);
        int i = a.size()-1;
        while (i > 0) {
            int p = (i-1)/2;
            if (a[p] >= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }
    void pop() {
        if (a.empty()) return;
        a[0] = a.back(); a.pop_back();
        int n = a.size();
        int i = 0;
        while (true) {
            int l = 2*i+1, r = 2*i+2, largest = i;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }
    int top() const {
        if (a.empty()) throw runtime_error("heap empty");
        return a[0];
    }
    bool empty() const { return a.empty(); }
    int size() const { return a.size(); }
};

int main() {
    cout << "Demo std::priority_queue:\n";
    demoStdPQ();

    cout << "\nDemo custom MaxHeap:\n";
    MaxHeap h;
    h.push(3); h.push(8); h.push(2); h.push(10);
    while (!h.empty()) {
        cout << h.top() << ' ';
        h.pop();
    }
    cout << '\n';
    return 0;
}
