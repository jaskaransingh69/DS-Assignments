#include<iostream>
using namespace std;

class Stack {
public:
    int arr[100];
    int top;
    int size;

    Stack(int s){
        size = s;
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size - 1;
    }

    void push(int x){
        if(isFull()){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout << "Stack Empty\n";
            return;
        }
        for(int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Stack s(100);
    int ch, x;

    while(true){
        cout << "\n1 Push\n2 Pop\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> ch;

        switch(ch){
            case 1: cin >> x; s.push(x); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (s.isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: s.display(); break;
            case 6: cout << s.peek() << endl; break;
            case 7: return 0;
        }
    }
}
