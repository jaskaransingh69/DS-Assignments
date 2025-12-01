#include<iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear;

    Queue(){
        front = -1; rear = -1;
    }

    void enqueue(int x){
        if(rear == 99) return;
        if(front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue(){
        if(front == -1) return -1;
        int x = arr[front];
        if(front == rear) front = rear = -1;
        else front++;
        return x;
    }

    bool isEmpty(){
        return front == -1;
    }
};

int main(){
    Queue q, firstHalf;
    int n, x;

    cin >> n;  
    for(int i=0; i<n; i++){
        cin >> x;
        q.enqueue(x);
    }

    int half = n / 2;

    for(int i=0; i<half; i++)
        firstHalf.enqueue(q.dequeue());

    cout << "Interleaved: ";

    while(!firstHalf.isEmpty()){
        cout << firstHalf.dequeue() << " ";
        cout << q.dequeue() << " ";
    }
}
