#include<iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue(int s){
        size = s;
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void enqueue(int x){
        if(isFull()){
            cout << "Queue Full\n";
            return;
        }
        if(front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue Empty\n";
            return;
        }
        if(front == rear){
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek(){
        if(isEmpty()) return -1;
        return arr[front];
    }

    void display(){
        if(isEmpty()){
            cout << "Queue Empty\n";
            return;
        }
        for(int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Queue q(100);
    int choice, val;

    while(true){
        cout << "\n1 Enqueue\n2 Dequeue\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> choice;

        switch(choice){
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (q.isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: q.display(); break;
            case 6: cout << q.peek() << endl; break;
            case 7: return 0;
        }
    }
}
